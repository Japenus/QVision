#ifndef DYNAMICDETECT_H
#define DYNAMICDETECT_H
#include "Global.h"
#include "tools.h"
#include "Preprocess.h"
#include "ImgAlgorithm.h"
class DynamicDetect
{
public:
    Tools tool;
    static DynamicDetect & ins(){static DynamicDetect d;return d;}
    ImgAlgorithm IAM;
    Preprocess Process;
    void detectEye();
    void detectFace();
    void detectLine();
    void detectSquare();
    void detectCircle();
    void detectEllpise();
    void detectTriangle();
    void detectCharacter();
    void detectByUserCreateModel(const QString &modelPath);
    void recognizeFace();
    double angle(Point pt1, Point pt2, Point pt0);
};

#endif // DYNAMICDETECT_H
