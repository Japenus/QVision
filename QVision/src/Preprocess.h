#ifndef PREPROCESS_H
#define PREPROCESS_H
#include"global.h"
class Preprocess:public QObject
{
    Q_OBJECT
public:
    static Preprocess & ins(){static Preprocess p;return p;}
public:
    Mat Erosion(Mat src);
    Mat Dilation(Mat src);
    Mat BoxFilter(Mat src);
    Mat MeanFilter(Mat src);
    Mat GaussFilter(Mat src);
    Mat MediumFilter(Mat src);
    Mat GrayTransform(Mat src);
    Mat BilateralFilter(Mat src);
    Mat LinearTransform(Mat src);
    Mat LogTransform(Mat src , double para);
    Mat GammaTransform(Mat src, float gamma);
};
#endif // PREPROCESS_H
