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
    static Tools& ins(){static Tools t;return t;}
public:
    Preprocess process;
    Scalar PickColor();
    QSqlDatabase MySql();
    int Pyramid(Mat src);
    void recognizeFace();
    Rect GetCoordinate();
    void MakeBig(Mat src);
    Mat EdgeSobel(Mat src);
    Mat EdgeCanny(Mat src);
    Mat AreaCover(Mat img);
    Mat Edgescharr(Mat src);
    QSqlDatabase SqlServer();
    Mat ShowHistogram(Mat src);
    QString NetSpyder(QString &url);
    Mat ShowOutline(Mat src,int val);
    Mat FixThreshold(Mat img, int val);
    int Statistic(Mat img, int pixval);
    QSqlDatabase SQLite(QString dbfile);
    Mat ThresholdProcess(Mat src,int val);
    Mat PersTransform(Mat src,Mat target);
    Mat EraseArea(Mat src,Scalar c,int s);
    QString CharRecognize(Mat img);
    QString recognizeQRCode(Mat img);
    QString recognizeBarCode(Mat img);
    QString CharRecognize(QString imgPath);
    Mat EdgeCanny(Mat src,int low,int high);
    int Screenshot(Mat src, QString winName);
    QStringList GetTables(QSqlDatabase *qDB);
    QStringList GetDataBases(QSqlDatabase *qDB);
    Mat ThresholdProcess(Mat src,int val,int type);
    double CalcDist(int X1, int Y1, int x2, int Y2);
    Mat RotateScale(Mat src, double angle, double scale);
    double CalcIOU(const Rect& rectA, const Rect& rectB);
    Mat AdaptThreshold(Mat src, int blocksize, double C);
    void MatchImgPath(QRegularExpression re,QString context);
    void MatchRegExp(QRegularExpression &regExp,QString &Str);
    Mat ThresholdProcess(Mat src,int val,int maxVal,int type);
    QString NetSpyder(QString &url,QProgressBar *bar,QElapsedTimer *t);
    QStringList GetTableFields(QSqlDatabase *db, const QString& tableName);
    Mat RegionGrow(Mat& src, Point seedPoint, int threshold, Mat& visited);
    Mat AreaFill(Mat whichImg,const Scalar &fillColor,int vsize,int vcount);
    QList<QList<QString>> GetTableData(QSqlDatabase *db, const QString& tableName);
    vector<Rect> NonMaxSuppress(const vector<Rect>& boxes, const vector<double>& scores,double threshold);
    void SetHoughParas(Ptr<GeneralizedHoughBallard> ballard,double a,int b,double c,int d,int e,int f,int g);
    void DrawRotRect(Mat whichimg,const Point2f& rCenter,const Size2f& rSize,float rAngle, Scalar rColor,int rwidth);
    vector<pair<Rect, double>> TotalArea(const Mat& src, const Mat& temp,double step,double min, double max,int threshold);
    void SetHoughParas(Ptr<GeneralizedHoughGuil> guil,double a, int b, double c, double d, int e, int f, int g, int h, int i, int j, int k,float l,float m,double n,int o,int p,float q);

public:
    bool isCut;
    QPixmap tmp;
private:
    QString res;
};

#endif // TOOLS_H
