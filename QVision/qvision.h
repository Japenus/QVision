#ifndef QVISION_H
#define QVISION_H
#include "tools.h"
#include "global.h"
#include "Dialog.h"
#include "database.h"
#include "screencut.h"
#include "multimedia.h"
#include "Preprocess.h"
#include "ImgAlgorithm.h"
#include "imgcalculate.h"
#include "dynamicdetect.h"
#include "fileOperation.h"
#include "CaptureScreen.h"
#include "networkcommunication.h"
QT_BEGIN_NAMESPACE
namespace Ui {
    class QVision;
}
QT_END_NAMESPACE

class QVision : public QMainWindow
{
    Q_OBJECT

public:
    QVision(QWidget *parent = nullptr);
    // void dropEvent(QDropEvent *event);
    // void dragEnterEvent(QDragEnterEvent *event);
    ~QVision();
public:
    DataBase DB;
    Tools tools;
    ScreenCut SC;
    MultiMedia MM;
    ImgAlgorithm IA;
    ImgCalculate IC;
    fileOperation FO;
    CaptureScreen CS;
    Preprocess pretreat;

    GuilDlg GD;
    CannyDlg CD;
    RenameDlg RD;
    BallardDlg BD;
    DynamicDetect DD;

    ResizeDlg RDlg;
    AreaFillDlg AFD;
    RotScaleDlg RSD;
    ThresholdDlg TD;
    CharRecogDlg CRD;

    CalcuDistDlg CDD;
    WriteDataDlg WDD;
    NetSpyderDlg NSDlg;
    FixThresholdDlg FTD;

    TemplateMatchDlg TMD;
    StatisticPixelDlg SPD;
    UpgradeTempMatchDlg UTD;
    NetworkCommunication NC;

    void Show();
    bool haveRes();
    bool IsImgOpen();
    void Show(Mat src);
    bool Save(Mat what);
    QString getModel();
    QString getFolder();
    QString getFilepath();
    QString getOutputpath();
private slots:
    void on_bigSrc_clicked();
    void on_bigRes_clicked();
    void on_srcHist_clicked();
    void on_resHist_clicked();
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
    void on_actionGray_Transform_triggered();
    void on_actionLog_Transform_triggered();
    void on_actionLinear_Transform_triggered();
    void on_actionGamma_Transform_triggered();
    void on_actionBox_Filter_triggered();
    void on_actionMean_Filter_triggered();
    void on_actionMedium_Filter_triggered();
    void on_actionBilateral_Filter_triggered();
    void on_actionGauss_Filter_triggered();
    void on_actionDilation_triggered();
    void on_actionErosion_triggered();
    void on_actionSobel_triggered();
    void on_actionCanny_triggered();
    void on_actionScharr_triggered();
    void on_actionRegion_Grow_triggered();
    void on_actionFix_Threshold_triggered();
    void on_actionShow_Outline_triggered();
    void on_actionThreshold_Process_triggered();
    void on_actionAdapt_Threshold_triggered();
    void on_actionArea_Cover_triggered();
    void on_actionArea_Fill_triggered();
    void on_actionStatistic_Pixels_triggered();
    void on_actionPerspective_Transform_triggered();
    void on_actionCalculate_Distance_triggered();
    void on_actionRotate_Scale_triggered();
    void on_actionImage_Pyramid_triggered();
    void on_actionDivide_triggered();
    void on_actionOpen_2_triggered();
    void on_actionClose_2_triggered();
    void on_actionMultipy_triggered();
    void on_actionLinear_Stretch_triggered();
    void on_actionAdd_triggered();
    void on_actionSubtraction_triggered();
    void on_actionFourier_triggered();
    void on_actionLaplacian_triggered();
    void on_actionSURF_triggered();
    void on_actionFlood_Fill_triggered();
    void on_actionImage_Equal_triggered();
    void on_actionTemplate_Match_triggered();
    void on_actionFeature_Point_MAtch_triggered();
    void on_actionUpgrade_TempMatch_triggered();
    void on_actionLine_triggered();
    void on_actionCircle_triggered();
    void on_actionEllipse_triggered();
    void on_actionTriangle_triggered();
    void on_actionBallard_triggered();
    void on_actionGuil_triggered();
    void on_actionSpyder_triggered();
    void on_actionSelf_Define_Model_triggered();
    void on_actionRename_File_triggered();
    void on_actionWriteToData_triggered();
    void on_actionOutputImg_Data_triggered();
    void on_actionResizeImgSize_triggered();
    void on_actionOutputFile_Info_triggered();
    void on_actionPick_Color_triggered();
    void on_actionRecongnize_Face_triggered();
    void on_actionShi_Tomasi_triggered();
    void on_actionHarris_triggered();
    void on_actionFast_triggered();
    void on_actionBrisk_triggered();
    void on_actionMser_triggered();
    void on_actionGFTT_triggered();
    void on_actionTesseract_OCR_triggered();
    void on_actionCapture_Line_triggered();
    void on_actionCapture_Circle_triggered();
    void on_actionCapture_Triangle_triggered();
    void on_actionCapture_Ellpise_triggered();
    void on_actionCapture_Character_triggered();
    void on_actionVideo_Player_triggered();
    void on_actionCapture_Square_triggered();
    void on_actionFollow_triggered();
    void on_actionCSDN_triggered();
    void on_actionJueJin_triggered();
    void on_actionScreen_Cut_triggered();
    void on_actionWakeUp_QQ_triggered();
    void on_actionCapture_HumanEyes_triggered();
    void on_actionCapture_HumanFace_triggered();
    void on_actionTCP_IP_triggered();
    void on_actionEraser_triggered();
    void on_actionRectangle_triggered();
    void on_actionLaunch_2_triggered();

private:
    int fixPara=10;
    Mat Src,Dst,Res;
    QLabel *tip1;
    QLabel *tip2;
    QLabel *srcBox;
    QLabel *resBox;
    Ui::QVision *ui;
    QPushButton *histSrc;
    QPushButton *histRes;
    QPushButton *bigSrc;
    QPushButton *bigRes;
};
#endif // QVISION_H
