#ifndef FORMATTRANSFER_H
#define FORMATTRANSFER_H
#include"global.h"
class FormatTransfer
{
public:
    Mat Pix2Mat(Pix *datatype);
    Pix* Mat2Pix(Mat datatype);
    QImage Pix2QImage(Pix *datatype);
    Pix* QImage2Pix(QImage &datatype);
    Mat QPixmap2Mat(QPixmap &datatype);
    QImage MatToQImage(const Mat &mat);
    QPixmap matToQpixmap(Mat &datatype);
    Mat QImageToMat(const QImage &image);
    static FormatTransfer & ins(){static FormatTransfer f;return f;}
};

#endif // FORMATTRANSFER_H
