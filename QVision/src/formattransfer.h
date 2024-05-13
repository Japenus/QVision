#ifndef FORMATTRANSFER_H
#define FORMATTRANSFER_H
#include"global.h"
class FormatTransfer
{
public:
    static FormatTransfer & ins(){static FormatTransfer f;return f;}
    Mat Pix2Mat(Pix *datatype);
    Pix* Mat2Pix(Mat datatype);
    QImage Pix2QImage(Pix *datatype);
    Pix* QImage2Pix(QImage &datatype);
    Mat QPixmap2Mat(QPixmap &datatype);
    QString Int2QString(int data);
};

#endif // FORMATTRANSFER_H
