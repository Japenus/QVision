#ifndef IMGCALCULATE_H
#define IMGCALCULATE_H

#include "global.h"
#include "Preprocess.h"

class ImgCalculate:public QObject
{
    Q_OBJECT
public:
    static ImgCalculate & ins(){static ImgCalculate i;return i;}
public:
    Preprocess prepro;
    Mat Divide(Mat src);
    Mat OnCalc(Mat src);
    Mat OffCalc(Mat src);
    Mat Multipy(Mat src);
    Mat LineStretch(Mat src);
    Mat Add(Mat img1, Mat img2);
    Mat FourierTransform(Mat src);
    Mat LaplacianTransform(Mat src);
    Mat Subtraction(Mat img1, Mat img2);
};

#endif // IMGCALCULATE_H

