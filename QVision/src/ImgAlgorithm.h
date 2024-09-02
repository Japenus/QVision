#ifndef IMGALGORITHM_H
#define IMGALGORITHM_H
#include"tools.h"
#include"color.h"
#include"Global.h"
#include"Dialog.h"
#include"preprocess.h"
class ImgAlgorithm:public QObject
{
    Q_OBJECT
public:
    Mat SURF(Mat src);
    Mat FloodFill(Mat src);
    Mat HistEqual(Mat src);
    Mat HoughLine(Mat src);
    Mat ORBDetect(Mat src);
    int FloodFiTT(Mat src);
    Mat GetFeature(Mat src);
    int WrapAffine(Mat src);
    Mat FASTDetect(Mat src);
    Mat GFTTDetect(Mat src);
    Mat MSERDetect(Mat src);
    Mat HoughCircle(Mat src);
    Mat BRISKDetect(Mat src);
    Mat HoughEllipse(Mat src);
    Mat HarrisDetect(Mat src);
    Mat HoughTriangle(Mat src);
    Mat HoughRectangle(Mat src);
    Mat ShiTomasiDetect(Mat src);
    Mat DetectFaceFromImg(Mat src);
    int MatchKPoint(Mat temp, Mat src);
    Mat FeaturePointMatch(Mat m1, Mat m2);
    Mat SelfModel(Mat src,QString modelpath);
    vector<Vec3f> DynamicDetectcir(Mat frame);
    vector<Vec3f> DynamicDetectEll(Mat frame);
    vector<Vec2f> DynamicDetectLine(Mat frame);
    vector<Vec2f> DynamicDetectTriangle(Mat frame);
    Mat MatchTemp(Mat src, Mat target, int thresVal);
    static ImgAlgorithm & ins(){static ImgAlgorithm i;return i;}
    Mat UpgradeMatchTemp(Mat temp, Mat src, int a,double b,double c , double d,double e,double f);
    Mat HoughBallard(Mat src, Mat temp,double mindist, int level, double dp, int buffer, int vote, int low, int high);
    Mat HoughGuil(Mat src, Mat temp, double a, int b, double c, double d, int e, int f, int g, int h, int i, int j, int k,float l,float m,double n,int o,int p,float q);
};

#endif // IMGALGORITHM_H
