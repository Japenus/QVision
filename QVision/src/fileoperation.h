#ifndef FileOperation_H
#define FileOperation_H
#include "global.h"
class FileOperation:public QObject
{
    Q_OBJECT
public:
    int ExportFiles(QString filefolder, QString outpuText);
    static FileOperation & ins(){static FileOperation f;return f;}
    void GetImgData(const QString& folderPath, const QString& outputFile);
    int RenameFile(QString path,QString prefix,int& increment,QString exten);
    void ResizeImg(QString imgfolder, QString outputRes, int weight, int height);
    int WriteToFile(QString filePath, QString context, QString other, int wNum,int incre);
};
#endif // FileOperation_H
