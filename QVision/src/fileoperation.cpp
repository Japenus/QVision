#include <fstream>
#include <filesystem>
#include "FileOperation.h"
namespace fs=filesystem;
int FileOperation::RenameFile(QString path,QString prefix,int& increment,QString exten)
{
    int num = increment;
    vector<fs::path> waitRename;
    fs::path dirPath(path.toStdString());
    for (const auto& entry : fs::directory_iterator(dirPath))
    {
        if (fs::is_regular_file(entry.path()))
        {
            waitRename.push_back(entry.path());
        }
    }
    for (const auto& filePath : waitRename)
    {
        string beforeName = prefix.toStdString();
        string extension = exten. toStdString();
        string newName = beforeName + to_string(num) + "." + extension;
        fs::path newFile = dirPath / newName;
        while (fs::exists(newFile))
        {
            num++;
            newName = beforeName + to_string(num) + "." + extension;
            newFile = dirPath / newName;
        }
        fs::rename(filePath,newFile);
        num++;
    }
    int renamed = num - increment;
    return renamed;
}
int FileOperation::WriteToFile(QString filePath, QString context, QString other, int wNum,int incre)
{
    ofstream ofs;
    ofs.open(filePath.toStdString(),ios::app);
    if (ofs.is_open()) {
        QString baseDir = context;
        for (int i = 0; i <= wNum; i++)
        {
            QString data = baseDir + QString::number(incre) + other;
            incre++;
            ofs << data.toStdString() << endl;
        }
        ofs.close();
    }
    return 0;
}
void FileOperation::GetImgData(const QString& folderPath, const QString& outputFile)
{
    ofstream ofs(outputFile.toStdString());
    for (const auto& entry : filesystem::directory_iterator(folderPath.toStdString()))
    {
        if (entry.is_regular_file())
        {
            QString filePath = QString::fromStdString(entry.path().string());
            Mat image = imread(filePath.toStdString());
            if (!image.empty()) {
                ofs << filePath.toStdString() << " " << image.cols << " " << image.rows << endl;
            }
        }
    }
    ofs.close();
}
void FileOperation::ResizeImg(QString imgfolder, QString outputRes, int weight, int height)
{
    for (const auto& entry : fs::directory_iterator (imgfolder.toStdString()))
    {
        if (entry.is_regular_file())
        {
            QString tempImg = QString::fromStdString(entry.path().string());
            Mat image = imread(tempImg.toStdString());
            if (!image.empty())
            {
                Mat res;
                resize(image, res, Size(weight, height));
                QString resized = outputRes + "/" + QString::fromStdString(entry.path().filename().string());
                imwrite(resized.toStdString(), res);
            }
        }
    }
}
int FileOperation::ExportFiles(QString filefolder, QString outpuText)
{
    int fileCount = 0;
    filesystem::path folderPath(filefolder.toStdString());
    ofstream ofs(outpuText.toStdString());
    if (ofs.is_open())
    {
        for (const auto& entry : filesystem::directory_iterator (folderPath))
        {
            if (!entry.is_directory())
            {
                ofs << entry.path() << endl;
                fileCount++;
            }
        }
        ofs.close();
        QMessageBox::information(nullptr, QString("Tips"), QString("Export file number:%1").arg(fileCount));
        return fileCount;
    }
    else
    {
        return -1;
    }
}
