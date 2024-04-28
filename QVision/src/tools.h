#ifndef TOOLS_H
#define TOOLS_H
#include"color.h"
#include"global.h"
#include"preprocess.h"
#include"formattransfer.h"
class Tools:public QObject
{
    Q_OBJECT
public:
    FormatTransfer FT;
    Preprocess process;
    QString addData();
    QString delData();
    QString findData();
    Scalar PickColor();
    QSqlDatabase MySql();
    QSqlDatabase SQLite();
    QSqlDatabase SqlServer();
    QString updateData();
    int Pyramid(Mat src);
    Rect GetCoordinate();
    void MakeBig(Mat src);
    Mat EdgeSobel(Mat src);
    Mat EdgeCanny(Mat src);
    Mat AreaCover(Mat img);
    Mat Edgescharr(Mat src);
    QStringList GetTables(QSqlDatabase *qDB);
    QStringList GetTables(QSqlDatabase *qDB,QString databaseName);
    QStringList GetDataBases(QSqlDatabase *qDB);
    Mat ShowHistogram(Mat src);
    QString CharRecognize(Mat img);
    QString NetSpyder(QString &url);
    Mat ShowOutline(Mat src,int val);
    Mat FixThreshold(Mat img, int val);
    int Statistic(Mat img, int pixval);
    Mat ThresholdProcess(Mat src,int val);
    Mat PersTransform(Mat src,Mat target);
    Mat EdgeCanny(Mat src,int low,int high);
    int Screenshot(Mat src, QString winName);
    QString CharRecognize(const QString &imgPath);
    Mat ThresholdProcess(Mat src,int val,int type);
    double CalcDist(int X1, int Y1, int x2, int Y2);
    Mat RotateScale(Mat src, double angle, double scale);
    double CalcIOU(const Rect& rectA, const Rect& rectB);
    Mat AdaptThreshold(Mat src, int blocksize, double C);
    void MatchImgPath(QRegularExpression re,QString context);
    void MatchRegExp(QRegularExpression &regExp,QString &Str);
    Mat ThresholdProcess(Mat src,int val,int maxVal,int type);
    QString NetSpyder(QString &url,QProgressBar *bar,QElapsedTimer *t);
    Mat RegionGrow(Mat& src, Point seedPoint, int threshold, Mat& visited);
    Mat AreaFill(Mat whichImg,const Scalar &fillColor,int vsize,int vcount);
    vector<Rect> NonMaxSuppress(const vector<Rect>& boxes, const vector<double>& scores,double threshold);
    void SetHoughParas(Ptr<GeneralizedHoughBallard> ballard,double a,int b,double c,int d,int e,int f,int g);
    void DrawRotRect(Mat whichimg,const Point2f& rCenter,const Size2f& rSize,float rAngle, Scalar rColor,int rwidth);
    vector<pair<Rect, double>> TotalArea(const Mat& src, const Mat& temp,double step,double min, double max,int threshold);
    void SetHoughParas(Ptr<GeneralizedHoughGuil> guil,double a, int b, double c, double d, int e, int f, int g, int h, int i, int j, int k,float l,float m,double n,int o,int p,float q);
};

#endif // TOOLS_H
