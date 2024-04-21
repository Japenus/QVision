#ifndef FILEOPERATION_H
#define FILEOPERATION_H
#include "global.h"
class fileOperation:public QObject
{
    Q_OBJECT
public:
    int ExportFiles(QString filefolder, QString outpuText);
    void GetImgData(const QString& folderPath, const QString& outputFile);
    int RenameFile(QString path,QString prefix,int& increment,QString exten);
    void ResizeImg(QString imgfolder, QString outputRes, int weight, int height);
    int WriteToFile(QString filePath, QString context, QString other, int wNum,int incre);
};
#endif // FILEOPERATION_H
