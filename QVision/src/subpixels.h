#ifndef SUBPIXELS_H
#define SUBPIXELS_H
#include "global.h"
#include <QObject>
#define L		0
#define THETA	1
#define H		2
#define K		3
#define N		7
#define MMPERPIXEL 0.0145503
#define R2D    57.295779513082323
#define Deg2Rad(Deg) (Deg)/ R2D
#define Rad2Deg(Rad) (Rad)* R2D

#define WHITE 255
#define BLACK 0

#define YESMEDIANBLUR	true
#define NOMEDIANBLUR	false
const double PI = 3.14159265358979323846;
//const int N = 7;
const Mat ZERPOLY00 = (Mat_<double>(7, 7) <<
                    0, 0.0287, 0.0686, 0.0807, 0.0686, 0.0287, 0,
                    0.0287, 0.0815, 0.0816, 0.0816, 0.0816, 0.0815, 0.0287,
                    0.0686, 0.0816, 0.0816, 0.0816, 0.0816, 0.0816, 0.0686,
                    0.0807, 0.0816, 0.0816, 0.0816, 0.0816, 0.0816, 0.0807,
                    0.0686, 0.0816, 0.0816, 0.0816, 0.0816, 0.0816, 0.0686,
                    0.0287, 0.0815, 0.0816, 0.0816, 0.0816, 0.0815, 0.0287,
                    0, 0.0287, 0.0686, 0.0807, 0.0686, 0.0287, 0);

const Mat ZERPOLY11R = (Mat_<double>(7, 7) <<
                    0, -0.015, -0.019, 0, 0.019, 0.015, 0,
                    -0.0224, -0.0466, -0.0233, 0, 0.0233, 0.0466, 0.0224,
                    -0.0573, -0.0466, -0.0233, 0, 0.0233, 0.0466, 0.0573,
                    -0.069, -0.0466, -0.0233, 0, 0.0233, 0.0466, 0.069,
                    -0.0573, -0.0466, -0.0233, 0, 0.0233, 0.0466, 0.0573,
                    -0.0224, -0.0466, -0.0233, 0, 0.0233, 0.0466, 0.0224,
                    0, -0.015, -0.019, 0, 0.019, 0.015, 0);

const Mat ZERPOLY11I = (Mat_<double>(7, 7) <<
                    0, -0.0224, -0.0573, -0.069, -0.0573, -0.0224, 0,
                    -0.015, -0.0466, -0.0466, -0.0466, -0.0466, -0.0466, -0.015,
                    -0.019, -0.0233, -0.0233, -0.0233, -0.0233, -0.0233, -0.019,
                    0, 0, 0, 0, 0, 0, 0,
                    0.019, 0.0233, 0.0233, 0.0233, 0.0233, 0.0233, 0.019,
                    0.015, 0.0466, 0.0466, 0.0466, 0.0466, 0.0466, 0.015,
                    0, 0.0224, 0.0573, 0.069, 0.0573, 0.0224, 0);

const Mat ZERPOLY20 = (Mat_<double>(7, 7) <<
                    0, 0.0225, 0.0394, 0.0396, 0.0394, 0.0225, 0,
                    0.0225, 0.0271, -0.0128, -0.0261, -0.0128, 0.0271, 0.0225,
                    0.0394, -0.0128, -0.0528, -0.0661, -0.0528, -0.0128, 0.0394,
                    0.0396, -0.0261, -0.0661, -0.0794, -0.0661, -0.0261, 0.0396,
                    0.0394, -0.0128, -0.0528, -0.0661, -0.0528, -0.0128, 0.0394,
                    0.0225, 0.0271, -0.0128, -0.0261, -0.0128, 0.0271, 0.0225,
                    0, 0.0225, 0.0394, 0.0396, 0.0394, 0.0225, 0);

const Mat ZERPOLY31R = (Mat_<double>(7, 7) <<
                    0, -0.0103, -0.0073, 0, 0.0073, 0.0103, 0,
                    -0.0153, -0.0018, 0.0162, 0, -0.0162, 0.0018, 0.0153,
                    -0.0223, 0.0324, 0.0333, 0, -0.0333, -0.0324, 0.0223,
                    -0.0190, 0.0438, 0.0390, 0, -0.0390, -0.0438, 0.0190,
                    -0.0223, 0.0324, 0.0333, 0, -0.0333, -0.0324, 0.0223,
                    -0.0153, -0.0018, 0.0162, 0, -0.0162, 0.0018, 0.0153,
                    0, -0.0103, -0.0073, 0, 0.0073, 0.0103, 0);

const Mat ZERPOLY31I = (Mat_<double>(7, 7) <<
                    0, -0.0153, -0.0223, -0.019, -0.0223, -0.0153, 0,
                    -0.0103, -0.0018, 0.0324, 0.0438, 0.0324, -0.0018, -0.0103,
                    -0.0073, 0.0162, 0.0333, 0.039, 0.0333, 0.0162, -0.0073,
                    0, 0, 0, 0, 0, 0, 0,
                    0.0073, -0.0162, -0.0333, -0.039, -0.0333, -0.0162, 0.0073,
                    0.0103, 0.0018, -0.0324, -0.0438, -0.0324, 0.0018, 0.0103,
                    0, 0.0153, 0.0223, 0.0190, 0.0223, 0.0153, 0);

const Mat ZERPOLY40 = (Mat_<double>(7, 7) <<
                    0, 0.013, 0.0056, -0.0018, 0.0056, 0.013, 0,
                    0.0130, -0.0186, -0.0323, -0.0239, -0.0323, -0.0186, 0.0130,
                    0.0056, -0.0323, 0.0125, 0.0406, 0.0125, -0.0323, 0.0056,
                    -0.0018, -0.0239, 0.0406, 0.0751, 0.0406, -0.0239, -0.0018,
                    0.0056, -0.0323, 0.0125, 0.0406, 0.0125, -0.0323, 0.0056,
                    0.0130, -0.0186, -0.0323, -0.0239, -0.0323, -0.0186, 0.0130,
                    0, 0.013, 0.0056, -0.0018, 0.0056, 0.013, 0);


const Mat SOBELX = (Mat_<double>(7, 7) <<
                    0, 0, 0, 0, 0, 0,0,
                    0, 0, 0, 0, 0, 0,0,
                    0, 0, -1,0, 1, 0,0,
                    0, 0, -2,0, 2, 0,0,
                    0, 0, -1,0, 1, 0,0,
                    0, 0, 0, 0, 0, 0,0,
                    0, 0, 0, 0, 0, 0,0);

const Mat SOBELY = (Mat_<double>(7, 7) <<
                    0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0,
                    0, 0, 1, 2, 1, 0, 0,
                    0, 0, 0, 0, 0, 0, 0,
                    0, 0,-1,-2,-1, 0, 0,
                    0, 0, 0, 0, 0, 0, 0,
                    0, 0, 0, 0, 0, 0, 0);

typedef struct ZerResult{
    double distance_mm = 0.0;
    double distance_pixel = 0.0;
    Point2d line1_kb = Point2d(0.0, 0.0);
    Point2d line2_kb = Point2d(0.0, 0.0);
    Mat matedge = Mat();
} ZerResult;


typedef struct ZerResultCir{
    double radius_mm = 0.0;
    double radius_pixel = 0.0;
    Point2d centerPoint_pixel = Point2d(0.0, 0.0);
    Point2d centerPoint_mm = Point2d(0.0, 0.0);
    Mat matedge = Mat();
} ZerResultCir;

class SubPixels:public QObject
{
    Q_OBJECT
public:
    SubPixels();

    void getCovPoint(Mat& matIn, vector<Point2i>& vecEdgePoint, int cannyL=150, int cannyH=200, int cannyCore=3);
    void getNeibor(vector<Point2i>& vecEdgePoint, Mat& matIn, Mat* matNeibor, int nbsize=N);
    void calEdgedxdy(Mat* matNeibor, int neiborNum, vector<Point2i>& vecDxdy);
    double calRratio(double absdx, double absdy);
    void calInterTime(vector<Point2i>& vecDxdy, int neiborNum, vector<Point2i>& vecResizeXY,Point2i VHtime=Point2i(4,4));
    void resizeNeibor(Mat* matNeibor, Mat* matResizeNeibor, vector<Point2i>& vecResizeXY, int neiborNum);
    void calEdgePara(Mat& matSingleResizeNeibor, Point2i resizeXY, vector<Vec4d>& vecPara, vector<Point2d>& subPixelRela, int nbsize=N, int ZerBgrL=10, int ZerBgrH=50);
    void DrawRectangle(Mat& img, Rect box, int drawColor=BLACK);
    void drawLine(Mat &image, double theta, double rho, Scalar color);
    void on_MouseHandle(int event, int x, int y, int flag, void* param);

    double meanX(vector<Point2d>& pts);
    void CircleInfo(vector<Point2d>& pts, Point2d& center, double& radius);
    double Vc(double A, double B, double C, double D, double E, double F, double G);
    double GetRadius(vector<Point2d>& pts, Point2d center);
    double Suuu(vector<Point2d>& pts, double mean_x);
    double Uc(double A, double B, double C, double D, double E, double F, double G);
    double Suu(vector<Point2d>& pts, double mean_x);
    double Svvv(vector<Point2d>& pts, double mean_y);
    double Suv(vector<Point2d>& pts, double mean_x, double mean_y);
    double Svv(vector<Point2d>& pts, double mean_y);
    double Suvv(vector<Point2d>& pts, double mean_x, double mean_y);
    double Suuv(vector<Point2d>& pts, double mean_x, double mean_y);
    double meanY(vector<Point2d>& pts);
    double Ui(vector<Point2d>& pts, int index, double meanXValue);
    double Vi(vector<Point2d>& pts, int index, double meanYValue);

    void fitLinev3(vector<Point2d>& vecLine, float* line);

    ZerResult CalDistanceSquare(Mat& matRoi, double rto = MMPERPIXEL,
                int drawColor = WHITE, bool ifmedianBlur=YESMEDIANBLUR,
                int cannyL = 150, int cannyH = 200, int cannyCore = 3,
                int nbsize = N, Point2i VHtime = Point2i(4, 4),
                int ZerBgrL = 10, int ZerBgrH = 50);

    ZerResultCir CalDistanceCircle(Mat& matRoi, double rto = MMPERPIXEL,
                int drawColor = WHITE, bool ifmedianBlur = YESMEDIANBLUR,
                int cannyL = 150, int cannyH = 200, int cannyCore = 3,
                int nbsize = N, Point2i VHtime = Point2i(4, 4),
                int ZerBgrL = 10, int ZerBgrH = 50);
};

#endif // SUBPIXELS_H
