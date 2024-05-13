#ifndef DYNAMICDETECT_H
#define DYNAMICDETECT_H
#include"global.h"
#include"tools.h"
#include"Preprocess.h"
#include"ImgAlgorithm.h"
class DynamicDetect
{
public:
    Tools tool;
    static DynamicDetect & ins(){static DynamicDetect d;return d;}
    ImgAlgorithm IAM;
    Preprocess Process;
    void DetectEye();
    void DetectFace();
    void DetectLine();
    void DetectSquare();
    void DetectCircle();
    void DetectEllpise();
    void DetectTriangle();
    void DetectCharacter();
    void DetectByUserCreateModel(const QString &modelPath);
    double angle(Point pt1, Point pt2, Point pt0);
};

#endif // DYNAMICDETECT_H
