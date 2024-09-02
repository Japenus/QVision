#ifndef DYNAMICDETECT_H
#define DYNAMICDETECT_H
#include "Global.h"
#include "tools.h"
#include "Preprocess.h"
#include "ImgAlgorithm.h"
class DynamicDetect
{
public:
    void detectEye();
    void detectFace();
    void detectLine();
    void detectSquare();
    void detectCircle();
    void detectEllpise();
    void detectTriangle();
    void detectCharacter();
    double angle(Point pt1, Point pt2, Point pt0);
    void detectByUserCreateModel(const QString &modelPath);
    static DynamicDetect & ins(){static DynamicDetect d;return d;}
};

#endif // DYNAMICDETECT_H
