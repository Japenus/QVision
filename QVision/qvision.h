#ifndef QVISION_H
#define QVISION_H
#include "Api.h"
#include "tools.h"
#include "global.h"
#include "Dialog.h"
#include "database.h"
#include "screencut.h"
#include "DllManager.h"
#include "multimedia.h"
#include "Preprocess.h"
#include "remotelogin.h"
#include "ImgAlgorithm.h"
#include "imgcalculate.h"
#include "dynamicdetect.h"
#include "fileOperation.h"
#include "algorithm/Sort.h"
#include "coordinatesystem.h"
#include "networkcommunication.h"
class QVision : public QMainWindow
{
    Q_OBJECT

public:
    QVision(QWidget *parent = nullptr);
    void init();
    // void dropEvent(QDropEvent *event);
    // void dragEnterEvent(QDragEnterEvent *event);
    ~QVision();
public:
    void Show();
    bool IsImgOpen();
    void Show(Mat src);
    bool Save(Mat what);
    QString getModel();
    QString getFolder();
    QString getFilepath();
    QString getOutputpath();
    Mat QPixmap2Mat(QPixmap &pix);
    QFunctionPointer currentFunPtr;
    QHash<QString, QFunctionPointer> Ptrs;
private:
    bool flag=false;
    QLabel *tip1;
    QLabel *tip2;
    int fixPara=10;
    QLabel *srcBox;
    QLabel *resBox;
    Mat Src,Dst,Res;
    QWidget *appFace;
    QToolBox siderBar;
    DllManager import;
    QPushButton *bigSrc;
    QPushButton *bigRes;
    QPushButton *histRes;
    QPushButton *histSrc;
    QPushButton *closeApp;

    QPushButton *openSider;
    QPushButton *qtChart;
    QPushButton *scanwifi;
    QPushButton *searchIp;
    QPushButton *showCoord;
    QPushButton *deviceInfo;
    QPushButton *remoteSignIn;

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
    void CaptureArbitaryShape();
    void PerspectiveTransform();
    void ShowCoordinateSystem();
};
#endif // QVISIONH
