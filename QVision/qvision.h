#ifndef QVISION_H
#define QVISION_H
#include "Api.h"
#include "Tools.h"
#include "global.h"
#include "dialog.h"
#include "dataBase.h"
#include "screenCut.h"
#include "dllManager.h"
#include "multiMedia.h"
#include "preProcess.h"
#include "remoteLogin.h"
#include "imgAlgorithm.h"
#include "imgCalculate.h"
#include "dynamicDetect.h"
#include "fileOperation.h"
#include "algorithm/Sort.h"
#include "MachineLearning.h"
#include "coordinateSystem.h"
#include "networkCommunication.h"
class QVision : public QMainWindow
{
    Q_OBJECT

public:
    void init();
    QVision(QWidget *parent = nullptr);
    ~QVision();

protected:
    void dropEvent(QDropEvent *e) override;
    void wheelEvent(QWheelEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *e) override;
    void dragLeaveEvent(QDragLeaveEvent *e) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

public:
    QPoint base;
    void Show();
    void SetIcon();
    bool imageOpen();
    void Show(Mat src);
    bool Save(Mat what);
    QString getModel();
    QString getFolder();
    QString getFilepath();
    QString getOutputpath();
    QGraphicsScene *resScene;
    Mat QPixmap2Mat(QPixmap &pix);
    QFunctionPointer currentFunPtr;
    QHash<QString, QFunctionPointer> Ptrs;


private:
    QLabel *tip1;
    QLabel *tip2;
    QImage image;
    QPixmap tmp;
    int fixPara=10;
    bool flag=false;
    Mat Src,Dst,Res;
    QWidget *appFace;
    QToolBox siderBar;
    DllManager import;
    QString color1="blue";
    QString color3="cyan";
    QString color4="green";
    QString color2="orange";
    QString color5="yellow";
    QString color6="purple";
    QString iconSrc="ico.png";
    QString color7="lightgreen";

    QGraphicsView *srcBox;
    QGraphicsView *resBox;
    QGraphicsScene *srcScene;

    QPushButton *bigSrc;
    QPushButton *bigRes;
    QPushButton *histRes;
    QPushButton *histSrc;
    QPushButton *closeApp;

    QPushButton *qtChart;
    QPushButton *fixIcon;
    QPushButton *scanwifi;
    QPushButton *searchIp;
    QPushButton *openSider;
    QPushButton *showCoord;
    QPushButton *deviceInfo;
    QPushButton *remoteSignIn;

    QWidget *drawer1;
    QWidget *drawer2;
    QPushButton *heapS;
    QPushButton *quickS;
    QPushButton *mergeS;
    QPushButton *shellS;
    QPushButton *bubbleS;
    QPushButton *selectS;
    QPushButton *insertS;
    QPushButton *testdll;

private slots:
    void Add();
    void SURF();
    void Line();
    void Guil();
    void Fast();
    void Mser();
    void GFTT();
    void CSDN();
    void Sobel();
    void Canny();
    void Brisk();
    void TCPIP();
    void Scharr();
    void Divide();
    void Spyder();
    void Harris();
    void Follow();
    void JueJin();
    void Eraser();
    void Launch();
    void Circle();
    void BigSrc();
    void BigRes();
    void SrcHist();
    void ResHist();
    void openImg();
    void saveImg();
    void Erosion();
    void Multipy();
    void Fourier();
    void Ballard();
    void Ellipse();
    void Triangle();
    void WakeUpQQ();
    void Dilation();
    void AreaFill();
    void ShiTomasi();
    void showSider();
    void Rectangle();
    void BoxFilter();
    void PickColor();
    void FloodFill();
    void AreaCover();
    void Laplacian();
    void MeanFilter();
    void RenameFile();
    void ImageEqual();
    void RegionGrow();
    void WriteToData();
    void CaptureLine();
    void exitQVision();
    void GaussFilter();
    void VideoPlayer();
    void ShowOutline();
    void RotateScale();
    void Subtraction();
    void RemotelogIn();
    void ScanNearWifi();

    void dlldemo();
    void openNote();
    void drawRose();
    void openCalc();
    void heapSort();
    void shellSort();
    void quickSort();
    void mergeSort();
    // void bubbleSort();
    void insertSort();
    void selectSort();

    void TesseractOCR();
    void closeQVision();
    void LogTransform();
    void MediumFilter();
    void FixThreshold();
    void ImagePyramid();
    void GetDeviceInfo();
    void CaptureScreen();
    void CaptureCircle();
    void GrayTransform();
    void CaptureSquare();
    void OutputImgData();
    void ResizeImgSize();
    void TemplateMatch();
    void OpenCalculate();
    void LinearStretch();
    void SearchLocation();
    void DisplayQtChart();
    void RecongnizeFace();
    void OutputFileInfo();
    void GammaTransform();
    void CaptureEllpise();
    void CloseCalculate();
    void AdaptThreshold();
    void AdjustLightness();
    void StatisticPixels();
    void MachineLearning();
    void SelfDefineModel();
    void CaptureTriangle();
    void LinearTransform();
    void BilateralFilter();
    void ThresholdProcess();
    void CaptureCharacter();
    void CaptureHumanEyes();
    void CaptureHumanFace();
    void UpgradeTempMatch();
    void CalculateDistance();
    void FeaturePointMatch();
    void ChangeSoftWareIcon();
    void CaptureArbitaryShape();
    void PerspectiveTransform();
    void ShowCoordinateSystem();

private:
    // tab1
    QAction *open;
    QAction *save;
    QAction *exit;

    // tab2
    QAction *gammaTrans;
    QAction *logTrans;
    QAction *grayTrans;
    QAction *linearTrans;
    QAction *meanFilt;
    QAction *boxFilt;
    QAction *gaussFilt;
    QAction *mediumFilt;
    QAction *bilateralFilt;
    QAction *erose;
    QAction *dilate;

    // tab3
    QAction *sobelEdge;
    QAction *cannyEdge;
    QAction *scharrEdge;
    QAction *erase;
    QAction *areaFilled;
    QAction *areaCovered;
    QAction *pickupColor;
    QAction *wakeQQ;
    QAction *screenShot;
    QAction *fixThres;
    QAction *showEdge;
    QAction *regionGrowing;
    QAction *rotScale;
    QAction *imgPyramid;
    QAction *adaptThres;
    QAction *statisticPix;
    QAction *thresProcess;
    QAction *calculateDist;
    QAction *perspectTrans;

    // tab4
    QAction *houghLine;
    QAction *houghGuil;
    QAction *houghCircle;
    QAction *houghBallard;
    QAction *houghEllipse;
    QAction *houghTriangle;
    QAction *houghRectangle;
    QAction *surfFeature;
    QAction *fastCornerDetect;
    QAction *mserCornerDetect;
    QAction *gfttCornerDetect;
    QAction *briskCornerDetect;
    QAction *harrisCornerDetect;
    QAction *shiTomasiCornerDetect;
    QAction *featurePntMatch;
    QAction *tempMatch;
    QAction *upgradeTMatch;
    QAction *floodFilled;
    QAction *imgEqual;

    // tab5
    QAction *addOper;
    QAction *openCal;
    QAction *closeCal;
    QAction *divideCal;
    QAction *multipyCal;
    QAction *lineStretch;
    QAction *fourierTrans;
    QAction *laplaceTrans;
    QAction *subtractOper;

    // tab6
    QAction *capLine;
    QAction *tessOcr;
    QAction *capChar;
    QAction *capSquare;
    QAction *capCircle;
    QAction *recogFace;
    QAction *userModel;
    QAction *capEllipse;
    QAction *capTriangle;
    QAction *capHumaneye;
    QAction *machineLearn;
    QAction *capSelfmodel;
    QAction *capHumanFace;

    // tab7
    QAction *renameFiles;
    QAction *resizeImg;
    QAction *writeToFile;
    QAction *exportImgdata;
    QAction *exportFileinfo;

    // tab8
    QAction *tcpIp;
    QAction *spyderNet;

    // tab9
    QAction *launchDB;
    QAction *videoPage;

    // tab10
    QAction *contactCSDN;
    QAction *contactGithub;
    QAction *contactJueJin;
};
#endif // QVISIONH
