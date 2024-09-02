#ifndef FORMATTRANSFER_H
#define FORMATTRANSFER_H
#include"global.h"
class FormatTransfer
{
public:
    Mat Pix2Mat(Pix *datatype);
    Pix* Mat2Pix(Mat datatype);
    QString Int2QString(int data);
    QImage Pix2QImage(Pix *datatype);
    Pix* QImage2Pix(QImage &datatype);
    Mat QPixmap2Mat(QPixmap &datatype);
    QPixmap matToQpixmap(Mat &datatype);
    static FormatTransfer & ins(){static FormatTransfer f;return f;}
};

#endif // FORMATTRANSFER_H
