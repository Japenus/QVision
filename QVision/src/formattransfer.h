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
};

#endif // FORMATTRANSFER_H
