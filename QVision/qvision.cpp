#include "qvision.h"
QVision::QVision(QWidget *parent): QMainWindow(parent)
{
    QIcon icon("Spyder.png");
    QRect DeviceSize=QGuiApplication::screens().at(0)->geometry();
    int w=DeviceSize.width();
    int h=DeviceSize.height();


    QMenuBar *menubar = new QMenuBar();
    QMenu *tab1 = menubar->addMenu("文件");
    QMenu *tab2 = menubar->addMenu("预处理");
    QMenu *tab3 = menubar->addMenu("工具");
    QMenu *tab4 = menubar->addMenu("运算");
    QMenu *tab5 = menubar->addMenu("算法");
    QMenu *tab6 = menubar->addMenu("批处理");
    QMenu *tab7 = menubar->addMenu("模型");
    QMenu *tab8 = menubar->addMenu("网络");
    QMenu *tab9 = menubar->addMenu("媒体");
    QMenu *tab10 = menubar->addMenu("数据库");
    QMenu *tab11 = menubar->addMenu("关于");

    //sub Menu
    QMenu *tab2_1 = tab2->addMenu("Transform");
    QMenu *tab2_2 = tab2->addMenu("Decline Noise");
    QMenu *tab2_3 = tab2->addMenu("Shapes Process");
    QMenu *tab3_1 = tab3->addMenu("Detect Edges");
    QMenu *tab5_1 = tab5->addMenu("Hough Transform");
    QMenu *tab5_1_1 = tab5_1->addMenu("Arbitary Shapes");
    QMenu *tab5_2 = tab5->addMenu("Corner Detect");
    QMenu *tab7_1 = tab7->addMenu("Dynamic Capture");


    QAction *save = new QAction("Save", this);
    QAction *exitApp = new QAction("Exit", this);
    QAction *openFile = new QAction("Open", this);

    QAction *Erosion = new QAction("Erosion", this);
    QAction *BoxF = new QAction("Box Filter", this);
    QAction *MeanF = new QAction("Mean Filter", this);
    QAction *Dilation = new QAction("Dilation", this);
    QAction *LogT = new QAction("Log Transform", this);
    QAction *GaussF = new QAction("Gauss Filter", this);
    QAction *GrayT = new QAction("Gray Transform", this);
    QAction *MediumF = new QAction("Medium Filter", this);
    QAction *GammaT = new QAction("Gamma Transform", this);
    QAction *LinearT = new QAction("Linear Transform", this);
    QAction *BilateralF = new QAction("Bilateral Filter", this);


    QAction *Sobel = new QAction("Sobel", this);
    QAction *Canny = new QAction("Canny", this);
    QAction *Eraser = new QAction("Eraser", this);
    QAction *Scharr = new QAction("Scharr", this);
    QAction *AreaF = new QAction("Area Fill", this);
    QAction *AreaC = new QAction("Area Cover", this);
    QAction *PickC = new QAction("Pick Color", this);
    QAction *WakeUpQ = new QAction("WakeUp QQ", this);
    QAction *ScreenC = new QAction("Screen Cut", this);
    QAction *FixT = new QAction("Fix Threshold", this);
    QAction *ShowO = new QAction("Show Outline", this);
    QAction *RegionG = new QAction("Region Grow", this);
    QAction *RotateS = new QAction("Rotate Scale", this);
    QAction *ImageP = new QAction("Image Pyramid", this);
    QAction *AdaptT = new QAction("Adapt Threshold", this);
    QAction *StatisticP = new QAction("Statistic Pixels", this);
    QAction *ThresholdP = new QAction("Threshold Process", this);
    QAction *CalculateD = new QAction("Calculate Distance", this);
    QAction *PerspectiveT = new QAction("Perspective Transform", this);


    QAction *Surf = new QAction("SURF", this);
    QAction *Fast = new QAction("Fast", this);
    QAction *Guil = new QAction("Guil", this);
    QAction *Mser = new QAction("Mser", this);
    QAction *Gftt = new QAction("GFTT", this);
    QAction *Line = new QAction("Line", this);
    QAction *Brisk = new QAction("Brisk", this);
    QAction *Harris = new QAction("Harris", this);
    QAction *Circle = new QAction("Circle", this);
    QAction *Ballard = new QAction("Ballard", this);
    QAction *Ellipse = new QAction("Ellipse", this);
    QAction *FloodF = new QAction("Flood Fill", this);
    QAction *Triangle = new QAction("Triangle", this);
    QAction *ImageE = new QAction("Image Equal", this);
    QAction *Rectangle = new QAction("Rectangle", this);
    QAction *ShiTomasi = new QAction("Shi Tomasi", this);
    QAction *TemplateM = new QAction("Template Match", this);
    QAction *UpgradeT = new QAction("Upgrade TempMatch", this);
    QAction *FeaturePM = new QAction("Feature Point Match", this);


    QAction *AddO = new QAction("Add Operation", this);
    QAction *OpenC = new QAction("Open Calculate", this);
    QAction *CloseC = new QAction("Close Calculate", this);
    QAction *LinearS = new QAction("Linear Stretch", this);
    QAction *DivideC = new QAction("Divide Calculate", this);
    QAction *MultipyC = new QAction("Multipy Calculate", this);
    QAction *FourierT = new QAction("Fourier Transform", this);
    QAction *LaplacianT = new QAction("Laplacian Transform", this);
    QAction *SubtractionO = new QAction("Subtraction Operation", this);


    QAction *CaptureL = new QAction("Capture Line", this);
    QAction *CaptureC = new QAction("Capture Circle", this);
    QAction *CaptureS = new QAction("Capture Square", this);
    QAction *CaptureE = new QAction("Capture Ellpise", this);
    QAction *TesseractO = new QAction("Tesseract OCR", this);
    QAction *RecognizeF = new QAction("Recognize Face", this);
    QAction *CaptureT = new QAction("Capture Triangle", this);
    QAction *CustomizeM = new QAction("Customize Model", this);
    QAction *CaptureH = new QAction("Capture HumanEyes", this);
    QAction *CaptureCC = new QAction("Capture Character", this);
    QAction *CaptureHH = new QAction("Capture HumanFace", this);


    QAction *RenameF = new QAction("Rename Files", this);
    QAction *ResizeI = new QAction("Resize Images", this);
    QAction *WriteT = new QAction("Write to Files", this);
    QAction *OutputI = new QAction("Output ImgData", this);
    QAction *OutputF = new QAction("Output FileInfo", this);

    QAction *TcpIp = new QAction("Tcp/Ip", this);
    QAction *Spyder = new QAction("Spyder", this);

    QAction *LaunchDB = new QAction("Launch", this);
    QAction *VideoP = new QAction("Video Player", this);

    QAction *CSDN = new QAction("CSDN", this);
    QAction *Github = new QAction("Github", this);
    QAction *JueJin = new QAction("JueJin", this);

    tab1->addSeparator();
    tab1->addAction(openFile);
    tab1->addAction(save);
    tab1->addAction(exitApp);

    tab2->addSeparator();
    tab2->addMenu(tab2_1);
    tab2->addMenu(tab2_2);
    tab2->addMenu(tab2_3);
    tab2_1->addAction(GrayT);
    tab2_1->addAction(LogT);
    tab2_1->addAction(LinearT);
    tab2_1->addAction(GammaT);
    tab2_2->addAction(BoxF);
    tab2_2->addAction(MeanF);
    tab2_2->addAction(MediumF);
    tab2_2->addAction(BilateralF);
    tab2_2->addAction(GaussF);
    tab2_3->addAction(Dilation);
    tab2_3->addAction(Erosion);

    tab3->addMenu(tab3_1);
    tab3_1->addAction(Sobel);
    tab3_1->addAction(Canny);
    tab3_1->addAction(Scharr);
    tab3->addAction(RegionG);
    tab3->addAction(FixT);
    tab3->addAction(ShowO);
    tab3->addAction(ThresholdP);
    tab3->addAction(AdaptT);
    tab3->addAction(AreaC);
    tab3->addAction(AreaF);
    tab3->addAction(StatisticP);
    tab3->addAction(PerspectiveT);
    tab3->addAction(CalculateD);
    tab3->addAction(RotateS);
    tab3->addAction(ImageP);
    tab3->addAction(PickC);
    tab3->addAction(ScreenC);
    tab3->addAction(WakeUpQ);
    tab3->addAction(Eraser);

    tab4->addAction(DivideC);
    tab4->addAction(OpenC);
    tab4->addAction(CloseC);
    tab4->addAction(MultipyC);
    tab4->addAction(LinearS);
    tab4->addAction(AddO);
    tab4->addAction(SubtractionO);
    tab4->addAction(FourierT);
    tab4->addAction(LaplacianT);

    tab5->addAction(Surf);
    tab5->addAction(FloodF);
    tab5->addAction(ImageE);
    tab5->addAction(TemplateM);
    tab5->addAction(FeaturePM);
    tab5->addAction(UpgradeT);
    tab5_1->addAction(Line);
    tab5_1->addAction(Circle);
    tab5_1->addAction(Ellipse);
    tab5_1->addAction(Triangle);
    tab5_1->addAction(Rectangle);
    tab5_1_1->addAction(Guil);
    tab5_1_1->addAction(Ballard);
    tab5_2->addAction(ShiTomasi);
    tab5_2->addAction(Harris);
    tab5_2->addAction(Fast);
    tab5_2->addAction(Brisk);
    tab5_2->addAction(Mser);
    tab5_2->addAction(Gftt);

    tab6->addAction(RenameF);
    tab6->addAction(WriteT);
    tab6->addAction(OutputI);
    tab6->addAction(ResizeI);
    tab6->addAction(OutputF);

    tab7->addAction(CustomizeM);
    tab7->addAction(RecognizeF);
    tab7->addAction(TesseractO);
    tab7->addMenu(tab7_1);
    tab7_1->addAction(CaptureL);
    tab7_1->addAction(CaptureC);
    tab7_1->addAction(CaptureT);
    tab7_1->addAction(CaptureE);
    tab7_1->addAction(CaptureCC);
    tab7_1->addAction(CaptureS);
    tab7_1->addAction(CaptureH);
    tab7_1->addAction(CaptureHH);

    tab8->addAction(Spyder);
    tab8->addAction(TcpIp);
    tab9->addAction(VideoP);
    tab10->addAction(LaunchDB);
    tab11->addAction(Github);
    tab11->addAction(CSDN);
    tab11->addAction(JueJin);

    setMenuBar(menubar);

    srcBox=new QLabel();
    resBox=new QLabel();
    // srcBox->setAcceptDrops(true);
    tip1=new QLabel("Before");
    tip2=new QLabel("After");

    histSrc= new QPushButton("Hist");
    histRes= new QPushButton("Hist");
    bigSrc = new QPushButton("Make Big");
    bigRes = new QPushButton("Make Big");
    closeApp = new QPushButton("Close");
    openSider = new QPushButton("ToolBox");

    tip1->setFixedHeight(3*fixPara);tip1->setAlignment(Qt::AlignCenter);
    tip2->setFixedHeight(3*fixPara);tip2->setAlignment(Qt::AlignCenter);
    tip1->setStyleSheet("border: 1px solid brown;padding: 5px;color: green; /*background-color: orange;*/border-radius: 10px;font-weight: bold; font-style: italic;");
    tip2->setStyleSheet("border: 1px solid brown;padding: 5px;color: green; /*background-color: orange;*/border-radius: 10px;font-weight: bold; font-style: italic;");

    srcBox->setStyleSheet("border: 1px solid brown; padding: 5px;border-radius: 10px;font-weight: bold;");
    resBox->setStyleSheet("border: 1px solid brown; padding: 5px;border-radius: 10px;font-weight: bold;");

    bigRes->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    bigSrc->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");

    histRes->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    histSrc->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;;border-radius: 10px;font-weight: bold;");

    openSider->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    closeApp->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;;border-radius: 10px;font-weight: bold;");

    srcBox->setMaximumSize(w,h);srcBox->setMinimumSize(w/4,h/3);
    resBox->setMaximumSize(w,h);resBox->setMinimumSize(w/4,h/3);
    srcBox->setScaledContents(true);resBox->setScaledContents(true);
    srcBox->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    resBox->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    QVBoxLayout *MainStruct = new QVBoxLayout;
    QHBoxLayout *Row1 = new QHBoxLayout;
    QHBoxLayout *Row2 = new QHBoxLayout;
    QHBoxLayout *Row3 = new QHBoxLayout;
    QHBoxLayout *Row4 = new QHBoxLayout;
    QHBoxLayout *Row5 = new QHBoxLayout;
    appFace=new QWidget;

    Row1->addWidget(tip1);Row1->addWidget(tip2);
    Row2->addWidget(srcBox);Row2->addWidget(resBox);
    Row3->addWidget(histSrc);Row3->addWidget(histRes);
    Row4->addWidget(bigSrc);Row4->addWidget(bigRes);
    Row5->addWidget(openSider);Row5->addWidget(closeApp);

    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(Row3);
    MainStruct->addLayout(Row4);
    MainStruct->addLayout(Row5);
    MainStruct->setStretch(0,10);
    MainStruct->setSpacing(fixPara);
    MainStruct->setContentsMargins(fixPara, fixPara, fixPara, fixPara);

    appFace->setLayout(MainStruct);
    setCentralWidget(appFace);

    connect(bigSrc,&QPushButton::clicked,this,&QVision::BigSrc);
    connect(bigRes,&QPushButton::clicked,this,&QVision::BigRes);
    connect(histSrc,&QPushButton::clicked,this,&QVision::SrcHist);
    connect(histRes,&QPushButton::clicked,this,&QVision::ResHist);
    connect(openSider,&QPushButton::clicked,this,&QVision::showSider);
    connect(closeApp,&QPushButton::clicked,this,&QVision::closeQVision);

    connect(save,&QAction::triggered,this,&QVision::saveImg);
    connect(openFile,&QAction::triggered,this,&QVision::openImg);
    connect(exitApp,&QAction::triggered,this,&QVision::exitQVision);


    connect(BoxF,&QAction::triggered,this,&QVision::BoxFilter);
    connect(Erosion,&QAction::triggered,this,&QVision::Erosion);
    connect(MeanF,&QAction::triggered,this,&QVision::MeanFilter);
    connect(Dilation,&QAction::triggered,this,&QVision::Dilation);
    connect(LogT,&QAction::triggered,this,&QVision::LogTransform);
    connect(GaussF,&QAction::triggered,this,&QVision::GaussFilter);
    connect(GrayT,&QAction::triggered,this,&QVision::GrayTransform);
    connect(MediumF,&QAction::triggered,this,&QVision::MediumFilter);
    connect(GammaT,&QAction::triggered,this,&QVision::GammaTransform);
    connect(LinearT,&QAction::triggered,this,&QVision::LinearTransform);
    connect(BilateralF,&QAction::triggered,this,&QVision::BilateralFilter);

    connect(Sobel,&QAction::triggered,this,&QVision::Sobel);
    connect(Canny,&QAction::triggered,this,&QVision::Canny);
    connect(Eraser,&QAction::triggered,this,&QVision::Eraser);
    connect(Scharr,&QAction::triggered,this,&QVision::Scharr);
    connect(AreaF,&QAction::triggered,this,&QVision::AreaFill);
    connect(AreaC,&QAction::triggered,this,&QVision::AreaCover);
    connect(PickC,&QAction::triggered,this,&QVision::PickColor);
    connect(WakeUpQ,&QAction::triggered,this,&QVision::WakeUpQQ);
    connect(FixT,&QAction::triggered,this,&QVision::FixThreshold);
    connect(ShowO,&QAction::triggered,this,&QVision::ShowOutline);
    connect(ImageP,&QAction::triggered,this,&QVision::ImageEqual);
    connect(RegionG,&QAction::triggered,this,&QVision::RegionGrow);
    connect(RotateS,&QAction::triggered,this,&QVision::RotateScale);
    connect(AdaptT,&QAction::triggered,this,&QVision::AdaptThreshold);
    connect(ScreenC,&QAction::triggered,this,&QVision::CaptureScreen);
    connect(StatisticP,&QAction::triggered,this,&QVision::StatisticPixels);
    connect(ThresholdP,&QAction::triggered,this,&QVision::ThresholdProcess);
    connect(CalculateD,&QAction::triggered,this,&QVision::CalculateDistance);
    connect(PerspectiveT,&QAction::triggered,this,&QVision::PerspectiveTransform);


    connect(Surf,&QAction::triggered,this,&QVision::SURF);
    connect(Gftt,&QAction::triggered,this,&QVision::GFTT);
    connect(Guil,&QAction::triggered,this,&QVision::Guil);
    connect(Line,&QAction::triggered,this,&QVision::Line);
    connect(Fast,&QAction::triggered,this,&QVision::Fast);
    connect(Mser,&QAction::triggered,this,&QVision::Mser);
    connect(Brisk,&QAction::triggered,this,&QVision::Brisk);
    connect(Circle,&QAction::triggered,this,&QVision::Circle);
    connect(Harris,&QAction::triggered,this,&QVision::Harris);
    connect(Ellipse,&QAction::triggered,this,&QVision::Ellipse);
    connect(Ballard,&QAction::triggered,this,&QVision::Ballard);
    connect(FloodF,&QAction::triggered,this,&QVision::FloodFill);
    connect(ImageE,&QAction::triggered,this,&QVision::ImageEqual);
    connect(Triangle,&QAction::triggered,this,&QVision::Triangle);
    connect(Rectangle,&QAction::triggered,this,&QVision::Rectangle);
    connect(ShiTomasi,&QAction::triggered,this,&QVision::ShiTomasi);
    connect(TemplateM,&QAction::triggered,this,&QVision::TemplateMatch);
    connect(UpgradeT,&QAction::triggered,this,&QVision::UpgradeTempMatch);
    connect(FeaturePM,&QAction::triggered,this,&QVision::FeaturePointMatch);

    connect(AddO,&QAction::triggered,this,&QVision::Add);
    connect(DivideC,&QAction::triggered,this,&QVision::Divide);
    connect(FourierT,&QAction::triggered,this,&QVision::Fourier);
    connect(MultipyC,&QAction::triggered,this,&QVision::Multipy);
    connect(OpenC,&QAction::triggered,this,&QVision::OpenCalculate);
    connect(LaplacianT,&QAction::triggered,this,&QVision::Laplacian);
    connect(CloseC,&QAction::triggered,this,&QVision::CloseCalculate);
    connect(LinearS,&QAction::triggered,this,&QVision::LinearStretch);
    connect(SubtractionO,&QAction::triggered,this,&QVision::Subtraction);

    connect(CaptureL,&QAction::triggered,this,&QVision::CaptureLine);
    connect(CaptureC,&QAction::triggered,this,&QVision::CaptureCircle);
    connect(CaptureS,&QAction::triggered,this,&QVision::CaptureSquare);
    connect(CaptureE,&QAction::triggered,this,&QVision::CaptureEllpise);
    connect(TesseractO,&QAction::triggered,this,&QVision::TesseractOCR);
    connect(CaptureT,&QAction::triggered,this,&QVision::CaptureTriangle);
    connect(RecognizeF,&QAction::triggered,this,&QVision::RecongnizeFace);
    connect(CaptureH,&QAction::triggered,this,&QVision::CaptureHumanEyes);
    connect(CaptureCC,&QAction::triggered,this,&QVision::CaptureCharacter);
    connect(CustomizeM,&QAction::triggered,this,&QVision::SelfDefineModel);
    connect(CaptureHH,&QAction::triggered,this,&QVision::CaptureHumanFace);

    connect(CSDN,&QAction::triggered,this,&QVision::CSDN);
    connect(TcpIp,&QAction::triggered,this,&QVision::TCPIP);
    connect(Github,&QAction::triggered,this,&QVision::Follow);
    connect(Spyder,&QAction::triggered,this,&QVision::Spyder);
    connect(JueJin,&QAction::triggered,this,&QVision::JueJin);
    connect(LaunchDB,&QAction::triggered,this,&QVision::Launch);
    connect(VideoP,&QAction::triggered,this,&QVision::VideoPlayer);
    connect(RenameF,&QAction::triggered,this,&QVision::RenameFile);
    connect(WriteT,&QAction::triggered,this,&QVision::WriteToData);
    connect(OutputI,&QAction::triggered,this,&QVision::OutputImgData);
    connect(ResizeI,&QAction::triggered,this,&QVision::ResizeImgSize);
    connect(OutputF,&QAction::triggered,this,&QVision::OutputFileInfo);

    QImage SrcImg=QImage(Src.data,Src.cols,Src.rows,Src.step,QImage::Format_RGB888).rgbSwapped();
    QImage ResImg=QImage(Dst.data,Dst.cols,Dst.rows,Dst.step,QImage::Format_RGB888).rgbSwapped();

    srcBox->setPixmap(QPixmap::fromImage(SrcImg).scaled(srcBox->size(),Qt::KeepAspectRatio));
    resBox->setPixmap(QPixmap::fromImage(ResImg).scaled(resBox->size(),Qt::KeepAspectRatio));

    srcBox->setScaledContents(true);srcBox->setFrameStyle(QFrame::Box);
    resBox->setScaledContents(true);resBox->setFrameStyle(QFrame::Box);

    setWindowIcon(icon);
    setWindowTitle("Image Process System");
}

QVision::~QVision()
{

}


//basic
void QVision::openImg()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "png", tr("Type (*.png *.jpg *.bmp)"));
    Src=imread(fileName.toStdString());
    if (!fileName.isEmpty()) {
        flag=true;
        QImage image(fileName);
        srcBox->setPixmap(QPixmap::fromImage(image));
    }
}


void QVision::saveImg()
{
    QImage image = resBox->pixmap().toImage();
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "result1.png", tr("Images (*.png *.jpg *.bmp)"));
    if (!filePath.isEmpty()) image.save(filePath);
}

void QVision::exitQVision()
{
    QApplication::quit();
}

bool QVision::IsImgOpen()
{
    if(!flag)
    {
        QMessageBox::information(this,tr("Tips"),tr("UnSelected Image!"));
        return false;
    }
    return true;
}

QString QVision::getFilepath()
{
    QString imgName=QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Type (*.png *.jpg *.bmp)"));
    if(!imgName.isEmpty()) return imgName;
    return "";
}

QString QVision::getOutputpath()
{
    QString imgName=QFileDialog::getOpenFileName(this,tr("Open File"),"",tr("Type (*.txt);;All Files(*.*)"));
    if(!imgName.isEmpty()) return imgName;
    return "";
}

QString QVision::getModel()
{
    QString modlelName=QFileDialog::getOpenFileName(this,tr("Choose Model"),"xml",tr("Xml Model (*.xml);;Prototxt Model(*.prototxt);;H5 Model(*.h5);;Json Model(*.json);;Weight Model(*.weights)"));
    if(!modlelName.isEmpty()) return modlelName;
    return "";
}

QString QVision::getFolder()
{
    QString folderPath=QFileDialog::getExistingDirectory(this,tr("Choose Folder"),"",QFileDialog::ShowDirsOnly);
    if(!folderPath.isEmpty()) return folderPath;
    return "";
}

void QVision::Show()
{
    QImage img;
    if(!Dst.empty()){
        if (Dst.channels() == 1)
        {
            img = QImage(Dst.data, Dst.cols, Dst.rows, Dst.step, QImage::Format_Grayscale8);
        }
        else
        {
            img = QImage(Dst.data, Dst.cols, Dst.rows, Dst.step, QImage::Format_BGR888);
        }
        QPixmap pixmap = QPixmap::fromImage(img);
        resBox->setPixmap(pixmap);
        resBox->setScaledContents(true);
        resBox->show();
    }
}

void QVision::Show(Mat image)
{
    QImage img;
    if (image.channels() == 1)
    {
        img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_Grayscale8);
    }
    else
    {
        img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);
    }
    QPixmap pixmap = QPixmap::fromImage(img);
    resBox->setPixmap(pixmap);
    resBox->setScaledContents(true);
    resBox->show();
}

bool QVision::Save(Mat what)
{
    imwrite("output.png",what);
    Mat success=imread("output.png");
    if(success.empty()) return false;
    return true;
}

Mat QVision::QPixmap2Mat(QPixmap &datatype)
{
    QImage image = datatype.toImage();
    if(image.isNull())
    {
        QMessageBox::warning(this,tr("警告"),tr("转换失败"));
        return Mat();
    }
    Mat res(image.height(), image.width(), CV_8UC4, image.bits(), image.bytesPerLine());
    cvtColor(res, res, COLOR_BGRA2BGR);
    return res;
}

void QVision::SrcHist()
{
    if(!IsImgOpen()) return;
    QPixmap pixmap = srcBox->pixmap();
    Src = QPixmap2Mat(pixmap);
    tools.ShowHistogram(Src);
}


void QVision::ResHist()
{
    if(!resBox->pixmap()) return;
    QPixmap pixmap = resBox->pixmap();
    Dst = QPixmap2Mat(pixmap);
    tools.ShowHistogram(Dst);
}


void QVision::BigSrc()
{
    if(!IsImgOpen()) return;
    tools.MakeBig(Src);
}


void QVision::BigRes()
{
    if(!IsImgOpen()) return;
    tools.MakeBig(Dst);
}


void QVision::closeQVision()
{
    QApplication::quit();
}

//预处理
void QVision::GrayTransform()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.GrayTransform(Src);
    Show(Dst);
}


void QVision::LogTransform()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.LogTransform(Src,10);
    Show(Dst);
}


void QVision::LinearTransform()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.LinearTransform(Src);
    Show(Dst);
}


void QVision::GammaTransform()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.GammaTransform(Src,1.2);
    Show(Dst);
}


void QVision::BoxFilter()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.BoxFilter(Src);
    Show(Dst);
}


void QVision::MeanFilter()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.MeanFilter(Src);
    Show(Dst);
}


void QVision::MediumFilter()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.MediumFilter(Src);
    Show(Dst);
}


void QVision::BilateralFilter()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.BilateralFilter(Src);
    Show(Dst);
}

void QVision::GaussFilter()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.GaussFilter(Src);
    Show(Dst);
}


void QVision::Dilation()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.Dilation(Src);
    Show(Dst);
}


void QVision::Erosion()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.Erosion(Src);
    Show(Dst);
}

//工具
void QVision::Sobel()
{
    if(!IsImgOpen()) return;
    Dst=tools.EdgeSobel(Src);
    Show();
}


void QVision::Canny()
{
    if(!IsImgOpen()) return;
    if(CD.exec()== QDialog::Accepted){
        int L=CD.getValue(0);
        int H=CD.getValue(1);
        CD.setValue(H,L);
        CD.low= CD.getValue(0);
        CD.high =CD.getValue(1);
        Dst = tools.EdgeCanny(Src,L,H);
        Show();
    }
}


void QVision::Scharr()
{
    if(!IsImgOpen()) return;
    Dst=tools.Edgescharr(Src);
    Show();
}


void QVision::RegionGrow()
{
    if(!IsImgOpen()) return;
    int threshold = 10;
    Point seedPoint(10, 10);
    Mat visited = Mat::zeros(Src.size(), CV_8U);
    Dst = tools.RegionGrow(Src, seedPoint, threshold, visited);
    Show(Dst);
}


void QVision::FixThreshold()
{
    if(!IsImgOpen()) return;
    if(FTD.exec()== QDialog::Accepted){
        int val=FTD.getValue();
        FTD.setValue(val);
        FTD.Val=val;
        Dst = tools.FixThreshold(Src, val);
        Show();
    }
}


void QVision::ShowOutline()
{
    if(!IsImgOpen()) return;
    int val=80;
    Dst=tools.ShowOutline(Src,val);
    Show();
}


void QVision::ThresholdProcess()
{
    if(!IsImgOpen()) return;
    if(TD.exec()== QDialog::Accepted){
        int type=TD.getValue(1);
        int val=TD.getValue(2);
        TD.setValue(val,type);
        TD.thresval=type;
        TD.threstype =val;
        Dst=tools.ThresholdProcess(Src,val,type);
        Show();
    }
}


void QVision::AdaptThreshold()
{
    if(!IsImgOpen()) return;
    int size=15;
    double c=2.0;
    Dst=tools.AdaptThreshold(Src,size,c);
    Show();
}


void QVision::AreaCover()
{
    if(!IsImgOpen()) return;
    Dst=tools.AreaCover(Src);
    Show();
}


void QVision::AreaFill()
{
    if(!IsImgOpen()) return;
    Scalar fill=tools.PickColor();
    if(AFD.exec()== QDialog::Accepted){
        int setNum=AFD.getValue(1);
        int setSize=AFD.getValue(2);
        AFD.setValue(setSize,setNum);
        AFD.PointSize = setSize;
        AFD.PointNum = setNum;
        Dst=tools.AreaFill(Src,fill,setSize,setNum);
        Show();
    }
}


void QVision::StatisticPixels()
{
    if(!IsImgOpen())return;
    if(SPD.exec()== QDialog::Accepted){
        int pixval=SPD.getValue();
        SPD.setValue(pixval);
        SPD.pixelval = pixval;
        int num = tools.Statistic(Src,pixval);
        QMessageBox::information(this,tr("提示"),tr("该像素值数量:%1").arg(num));
    }
}


void QVision::PerspectiveTransform()
{
    QString srcImg = getFilepath();
    QString targetImg = getFilepath();
    Mat SI =imread(srcImg.toStdString());
    Mat TGI = imread(targetImg.toStdString());
    if(SI.empty()||TGI.empty()){
        QMessageBox::information(this,tr("提示"),tr("用户已取消"));
        return;
    }else{
        Dst=tools.PersTransform(SI, TGI);
        Show();
    }
}


void QVision::CalculateDistance()
{
    if(CDD.exec()== QDialog::Accepted)
    {
        int curx1=CDD.getValue(1);
        int cury1=CDD.getValue(2);
        int curx2=CDD.getValue(3);
        int cury2=CDD.getValue(4);
        CDD.setValue(curx1,cury1,curx2,cury2);
        CDD.x1 = curx1;
        CDD.y1 = cury1;
        CDD.x2 = curx2;
        CDD.y2 = cury2;
        int res=tools.CalcDist(curx1,cury1,curx2,cury2);
        QMessageBox::information(this,tr("提示"),tr("两点间距离为:%1").arg(res));
    }
}


void QVision::RotateScale()
{
    if(!IsImgOpen())return;
    if(RSD.exec()== QDialog::Accepted)
    {
        int rotate=RSD.getValue(1);
        int scale=RSD.getValue(2);
        RSD.setValue(rotate,scale);
        RSD.rotate = rotate;
        RSD.scale = scale;
        Dst=tools.RotateScale(Src,rotate,scale);
        Show();
    }
}


void QVision::ImagePyramid()
{
    if(!IsImgOpen()) return;
    tools.Pyramid(Src);
}


void QVision::PickColor()
{
    tools.PickColor();
}

void QVision::CaptureScreen()
{
    SC.show();
    Show();
}

void QVision::WakeUpQQ()
{
    QProcess process;
    QString where = "D:/QQ/QQ.exe";
    process.start(where);
    if(process.waitForFinished(-1)){
        QMessageBox::information(this,tr("提示"),tr("进程已完成"));
    }
}

void QVision::Eraser()
{
    QMessageBox::information(this,tr("提示"),tr("橡皮擦功能"));
}

//图像运算
void QVision::Divide()
{
    if(!IsImgOpen()) return;
    Dst=IC.Divide(Src);
    Show();
}


void QVision::OpenCalculate()
{
    if(!IsImgOpen()) return;
    Dst=IC.OnCalc(Src);
    Show();
}


void QVision::CloseCalculate()
{
    if(!IsImgOpen()) return;
    Dst=IC.OffCalc(Src);
    Show();
}


void QVision::Multipy()
{
    if(!IsImgOpen()) return;
    Dst=IC.Multipy(Src);
    Show();
}


void QVision::LinearStretch()
{
    if(!IsImgOpen()) return;
    Dst=IC.LineStretch(Src);
    Show();
}


void QVision::Add()
{
    QString m1=getFilepath();
    QString m2=getFilepath();
    Mat s1=imread(m1.toStdString());
    Mat s2=imread(m2.toStdString());
    if(s1.empty()||s2.empty()) return;
    if(s1.size()!=s2.size()) return;
    Dst=IC.Add(s1,s2);
    Show();
}


void QVision::Subtraction()
{
    QString m1=getFilepath();
    QString m2=getFilepath();
    Mat s1=imread(m1.toStdString());
    Mat s2=imread(m2.toStdString());
    if(s1.empty()||s2.empty()) return;
    if(s1.size()!=s2.size()) return;
    Dst=IC.Subtraction(s1,s2);
    Show();
}


void QVision::Fourier()
{
    if(!IsImgOpen()) return;
    Dst=IC.FourierTransform(Src);
    Show();
}


void QVision::Laplacian()
{
    if(!IsImgOpen()) return;
    Dst=IC.LaplacianTransform(Src);
    Show();
}

//图像算法
void QVision::SURF()
{
    if(!IsImgOpen()) return;
    Dst=IA.SURF(Src);
    Show();
}


void QVision::FloodFill()
{
    if(!IsImgOpen()) return;
    Dst=IA.FloodFill(Src);
    Show();
}


void QVision::ImageEqual()
{
    if(!IsImgOpen()) return;
    Dst=IA.HistEqual(Src);
    Show();
}


void QVision::TemplateMatch()
{
    QString temPath = getFilepath();
    QString srcPath = getFilepath();
    if (temPath.isEmpty()||srcPath.isEmpty()) return;
    Mat src = imread(srcPath.toStdString());
    Mat temp = imread(temPath.toStdString());
    if(TMD.exec()== QDialog::Accepted){
        int curThresh=TMD.getValue();
        TMD.setValue(curThresh);
        TMD.thresh=curThresh;
        Dst=IA.MatchTemp(src, temp, curThresh);
        Show();
    }
}


void QVision::FeaturePointMatch()
{
    QString temPath = getFilepath();
    QString srcPath = getFilepath();
    if (temPath.isEmpty()||srcPath.isEmpty())return;
    Mat src1 = imread(temPath.toStdString());
    Mat src2 =imread(srcPath.toStdString());
    Dst=IA.FeaturePointMatch(src1,src2);
    Save(Dst);
    Show();
}


void QVision::UpgradeTempMatch()
{
    QString temPath = getFilepath();
    QString srcPath = getFilepath();
    if (temPath.isEmpty()||srcPath.isEmpty()) return;
    Mat temp = imread(temPath.toStdString());
    Mat src = imread(srcPath.toStdString());
    if(UTD.exec()== QDialog::Accepted){
        int ImgThres=UTD.getValue();
        double scalestep=UTD.getValue(1);
        double overlapThres=UTD.getValue(2);
        double MinscaleRatio=UTD.getValue(3);
        double MaxscaleRatio=UTD.getValue(4);
        double PreProcessThres=UTD.getValue(5);
        UTD.ImgThres=ImgThres;
        UTD.ScaleStep=scalestep;
        UTD.OverlapThres=overlapThres;
        UTD.MinScaleRatio=MinscaleRatio;
        UTD.MaxScaleRatio=MaxscaleRatio;
        UTD.PreProcessThres=PreProcessThres;
        Dst=IA.UpgradeMatchTemp(temp, src, ImgThres, scalestep, MinscaleRatio, MaxscaleRatio,overlapThres,PreProcessThres);
        Save(Dst);
        Show();
    }
}


void QVision::Line()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughLine(Src);
    Show();
}


void QVision::Circle()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughCircle(Src);
    Show();
}


void QVision::Ellipse()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughEllipse(Src);
    Show();
}


void QVision::Triangle()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughTriangle(Src);
    Show();
}

void QVision::Rectangle()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughRectangle(Src);
    Show();
}

void QVision::Ballard()
{
    QString temPath = getFilepath();
    QString srcPath = getFilepath();
    if (temPath.isEmpty()||srcPath.isEmpty()) return;
    Mat temp = imread(temPath.toStdString());
    Mat src = imread(srcPath.toStdString());
    if(BD.exec()== QDialog::Accepted)
    {
        int mindist=BD.getValue(1);
        int level=BD.getValue(2);
        double dp=BD.getValue(3);
        int buffersize=BD.getValue(4);
        int vote=BD.getValue(5);
        int cannylow=BD.getValue(6);
        int cannyhigh=BD.getValue(7);
        BD.setValue(mindist,level,dp,buffersize,vote,cannylow,cannyhigh);

        BD.mindist=mindist;
        BD.level=level;
        BD.dp=dp;
        BD.buffersize=buffersize;
        BD.vote=vote;
        BD.cannylow=cannylow;
        BD.cannyhigh=cannyhigh;
        Dst=IA.HoughBallard(src,temp,mindist,level,dp,buffersize,vote,cannylow,cannyhigh);
        Save(Dst);
        Show();
    }
}


void QVision::Guil()
{
    QString temPath=getFilepath();
    if (temPath.isNull())return;
    QString srcPath=getFilepath();
    Mat temp = imread(temPath.toStdString());
    Mat src =imread(srcPath.toStdString());
    if(GD.exec()== QDialog::Accepted)
    {
        int mindist=GD.getValue(MINDIST);
        int level=GD.getValue(LEVEL);
        double dp=GD.getDValue(DP);
        double xi=GD.getDValue(XI);
        int buffersize=GD.getValue(BUFFERSIZE);
        int cannylow=GD.getValue(CANNYLOWTHRESHOLD);
        int cannyhigh=GD.getValue(CANNYHIGHTHRESHOLD);
        int minangle=GD.getValue(MINANGLE);
        int maxangle=GD.getValue(MAXANGLE);
        int anglestep=GD.getValue(ANGLESTEP);
        int anglethreshold=GD.getValue(ANGLETHRESHOLD);
        float minscale=GD.getFValue(MINSCALE);
        float maxscale=GD.getFValue(MAXSCALE);
        float angleplise=GD.getFValue(ANGLEEPSILON);
        double scalestep=GD.getDValue(SCALESTEP);
        int scalethreshold=GD.getValue(SCALETHRESHOLD);
        int posthreshold=GD.getValue(POSITIONTHRESHOLD);
        qInfo()<<"minangle"<<minangle;
        qInfo()<<"maxangle"<<maxangle;
        qInfo()<<"minscale"<<minscale;
        qInfo()<<"maxscale"<<maxscale;
        qInfo()<<"scalestep"<<scalestep;
        GD.setValue(mindist,level,dp,xi,buffersize,cannylow,cannyhigh,minangle,maxangle,anglestep,anglethreshold,
                    minscale,maxscale,angleplise,scalestep,scalethreshold,posthreshold);
        GD.mindist=mindist;
        GD.level=level;
        GD.dp=dp;
        GD.xi=xi;
        GD.buffersize=buffersize;
        GD.cannylow=cannylow;
        GD.cannyhigh=cannyhigh;
        GD.minangle=minangle;
        GD.maxangle=maxangle;
        GD.anglestep=anglestep;
        GD.anglethreshold=anglethreshold;
        GD.minscale=minscale;
        GD.maxscale=maxscale;
        GD.angleplise=angleplise;
        GD.scalestep=scalestep;
        GD.scalethreshold=scalethreshold;
        GD.posthreshold=posthreshold;
        try
        {
            Dst=IA.HoughGuil(src,temp,mindist,level,dp,xi,buffersize,cannylow,cannyhigh,minangle,maxangle,anglestep,
                               anglethreshold,minscale,maxscale,angleplise,scalestep,scalethreshold,posthreshold);
        }
        catch(const exception& e)
        {
            QString eMsg ="参数错误!\n";
            eMsg += e.what();
            QMessageBox::critical(nullptr,"错误",eMsg,QMessageBox::Ok);
            return;
        }
        Save(Dst);
        Show();
    }
}

void QVision::ShiTomasi()
{
    if(!IsImgOpen()) return;
    Dst=IA.ShiTomasiDetect(Src);
    Show();
}


void QVision::Harris()
{
    if(!IsImgOpen()) return;
    Dst=IA.HarrisDetect(Src);
    Show();
}


void QVision::Fast()
{
    if(!IsImgOpen()) return;
    Dst=IA.FASTDetect(Src);
    Show();
}


void QVision::Brisk()
{
    if(!IsImgOpen()) return;
    Dst=IA.BRISKDetect(Src);
    Show();
}


void QVision::Mser()
{
    if(!IsImgOpen()) return;
    Dst=IA.MSERDetect(Src);
    Show();
}


void QVision::GFTT()
{
    if(!IsImgOpen()) return;
    Dst=IA.GFTTDetect(Src);
    Show();
}


//模型、检测
void QVision::SelfDefineModel()
{
    if(!IsImgOpen()) return;
    QString modelPath=getModel();
    Dst=IA.SelfModel(Src,modelPath);
    Show();
}

void QVision::RecongnizeFace()
{
    if(!IsImgOpen()) return;
    Dst=IA.DetectFaceFromImg(Src);
    Show();
}

void QVision::TesseractOCR()
{
    CRD.show();
}


void QVision::CaptureLine()
{
    DD.DetectLine();
}


void QVision::CaptureCircle()
{
    DD.DetectCircle();
}


void QVision::CaptureTriangle()
{
    DD.DetectTriangle();
}

void QVision::CaptureSquare()
{
    DD.DetectSquare();
}

void QVision::CaptureEllpise()
{
    DD.DetectEllpise();
}

void QVision::CaptureCharacter()
{
    DD.DetectCharacter();
}

void QVision::CaptureHumanEyes()
{
    DD.DetectEye();
}

void QVision::CaptureHumanFace()
{
    DD.DetectFace();
}

//文件操作
void QVision::RenameFile()
{
    if(RD.exec()== QDialog::Accepted)
    {
        QString dir = RD.getValue(1);
        QString exten = RD.getValue(2);
        QString prefix=RD.getValue(3);
        int num = RD.getValue();
        RD.setValue(num,dir,exten,prefix);
        RD.incre=num;
        RD.dir=dir;
        RD.exten=exten;
        RD.prefix=prefix;
        int renamed=FO.RenameFile(dir,prefix,num,exten);
        QMessageBox::information(this,tr("提示"),tr("已重命名文件数:%1").arg(renamed));
    }
}


void QVision::WriteToData()
{
    if(WDD.exec()==QDialog::Accepted)
    {
        QString dir =WDD.getInfo(1);
        QString context =WDD.getInfo(2);
        QString other =WDD.getInfo(3);
        int Num =WDD.getValue(1);
        int Incre =WDD.getValue(2);
        WDD.setValue(Num,Incre,dir,context,other);
        WDD.wnum=Num;
        WDD.increvar=Incre;
        WDD.dir=dir;
        WDD.context=context;
        WDD.other=other;
        FO.WriteToFile(dir,context,other,Num,Incre);
        QMessageBox::information(this,tr("提示"),tr("内容已写入"));
    }
}


void QVision::OutputImgData()
{
    QString dir=getFolder();
    QString savepath=getOutputpath();
    FO.GetImgData(dir,savepath);
}


void QVision::ResizeImgSize()
{
    QString sourceDir = getFolder();
    QString outputDir = getFolder();
    if(outputDir!=""){
        if(RDlg.exec()== QDialog::Accepted){
            int W=RDlg.getValue(1);
            int H=RDlg.getValue(2);
            RDlg.setValue(W,H);
            RDlg.w=W;
            RDlg.h=H;
            FO.ResizeImg(sourceDir,outputDir,W, H);
            QMessageBox::information(this,tr("提示"),tr("数据已写入!"));
        }
    }else{
        return;
    }
}


void QVision::OutputFileInfo()
{
    QString dir=getFolder();
    QString savepath=getOutputpath();
    if(!dir.isNull()&&!savepath.isNull()) FO.ExportFiles(dir,savepath);
}


//网络
void QVision::Spyder()
{
    if(NSDlg.exec()==QDialog::Accepted){
        QString url=NSDlg.getValue(1);
        QString keyword=NSDlg.getValue(2);
        QString path=NSDlg.getValue(3);
        QString html=NSDlg.getValue(4);
        NSDlg.setValue(url,keyword,path,html);
        NSDlg.url=url;
        NSDlg.keyword=keyword;
        NSDlg.savePath=path;
        NSDlg.htmlCode=html;
    }
}

void QVision::TCPIP()
{
    NC.show();
}

//多媒体
void QVision::VideoPlayer()
{
    MM.resize(640,480);
    MM.show();
}


//数据库
void QVision::Launch()
{
    DB.show();
}


//关于
void QVision::Follow()
{
    QUrl url("https://github.com/Japenus");
    QDesktopServices::openUrl(url);
}

void QVision::CSDN()
{
    QUrl url("https://blog.csdn.net/qq51610936?type=blog");
    QDesktopServices::openUrl(url);
}

void QVision::JueJin()
{
    QUrl url("https://juejin.cn/user/2080717187580488");
    QDesktopServices::openUrl(url);
}

//others

void QVision::showSider()
{
    siderBar.setWindowTitle("工具箱");
    scanwifi=new QPushButton("wifi扫描",this);
    deviceInfo=new QPushButton("设备信息",this);
    remoteSignIn=new QPushButton("远程登录",this);
    qtChart=new QPushButton("显示图表",this);
    searchIp=new QPushButton("ip查询",this);
    connect(scanwifi,&QPushButton::clicked,this,&QVision::ScanNearWifi);
    connect(deviceInfo,&QPushButton::clicked,this,&QVision::GetDeviceInfo);
    connect(remoteSignIn,&QPushButton::clicked,this,&QVision::RemotelogIn);
    connect(qtChart,&QPushButton::clicked,this,&QVision::DisplayQtChart);
    connect(searchIp,&QPushButton::clicked,this,&QVision::SearchLocation);

    siderBar.addItem(scanwifi,"抽屉1");
    siderBar.addItem(deviceInfo,"抽屉2");
    siderBar.addItem(remoteSignIn, "抽屉3");
    siderBar.addItem(qtChart, "抽屉4");
    siderBar.addItem(searchIp, "抽屉5");
    siderBar.resize(300,400);
    siderBar.show();
}

void QVision::ScanNearWifi()
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    foreach (const QNetworkInterface &interface, interfaces) {
        if (interface.type() == QNetworkInterface::Wifi) {
            QMessageBox::information(this,tr("WiFi"),tr("SSID:%1").arg(interface.humanReadableName()));
        }
    }
}

void QVision::RemotelogIn()
{
    RL.show();
}

void QVision::GetDeviceInfo()
{
    QString deviceInfo;

    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, interfaces) {
        deviceInfo += "Interface name: " + interface.name() + "\n";
        deviceInfo += "MAC address: " + interface.hardwareAddress() + "\n";
    }

    foreach (QHostAddress address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)) {
            deviceInfo += "IP address: " + address.toString() + "\n";
        }
    }

    deviceInfo += "Operating system: " + QSysInfo::prettyProductName() + "\n";
    deviceInfo += "Architecture: " + QSysInfo::currentCpuArchitecture() + "\n";
    deviceInfo += "Kernel type: " + QSysInfo::kernelType() + "\n";
    deviceInfo += "Kernel version: " + QSysInfo::kernelVersion() + "\n";

    QMessageBox::information(nullptr, "Device Information", deviceInfo);
}

void QVision::AdjustLightness()
{
    // QScreen *screen = QGuiApplication::primaryScreen();

    // qreal currentBrightness = screen->brightness();

    // QMessageBox::information(this,tr("提示"),tr("当前亮度:%1").arg(currentBrightness));
    // qreal newBrightness = currentBrightness - 10;

    // screen->setBrightness(newBrightness);

    // MessageBox::information(this,tr("提示"),tr("调整后亮度:%1").arg(newBrightness));
    QMessageBox::information(this,tr("提示"),tr("调整亮度"));
}

void QVision::SearchLocation()
{
    QString res;
    QNetworkAccessManager manager;
    QNetworkRequest request;
    QString ipAddress = QInputDialog::getText(this, "ip查询", "ip地址:");
    QUrl url("http://ip-api.com/json/" + ipAddress);
    request.setUrl(url);

    QNetworkReply *reply = manager.get(request);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jsonObj = jsonDoc.object();

        QString country = jsonObj["country"].toString();
        QString city = jsonObj["city"].toString();
        QString region = jsonObj["regionName"].toString();

        res="IP Address: "+ipAddress;
        res+="Country: "+country;
        res+="City: "+city;
        res+="Region: "+region;
        QMessageBox::information(this,tr("查询结果"),tr("详细信息:%1").arg(res));
    } else {
        QMessageBox::warning(this,tr("警告"),tr("错误:%1").arg(reply->errorString()));
    }
    reply->deleteLater();
}

void QVision::DisplayQtChart()
{
    // QtCharts::QBarSeries *series = new QtCharts::QBarSeries();
    // QtCharts::QBarSet *set = new QtCharts::QBarSet("Data");
    // *set << 1 << 2 << 3 << 4 << 5;
    // series->append(set);

    // QtCharts::QChart *chart = new QtCharts::QChart();
    // chart->addSeries(series);
    // chart->setTitle("Simple Bar Chart");
    // chart->createDefaultAxes();
    // chart->legend()->setVisible(true);

    // QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    // chartView->setRenderHint(QPainter::Antialiasing);

    // chartView->show();
    QMessageBox::information(this,tr("提示"),tr("图表"));
}
