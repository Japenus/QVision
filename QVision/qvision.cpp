#include "qvision.h"
QVision::QVision(QWidget *parent): QMainWindow(parent)
{
    init();
    QIcon icon(iconSrc);
    // QRect DeviceSize=QGuiApplication::screens().at(0)->geometry();
    // int w=DeviceSize.width();
    // int h=DeviceSize.height();
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


    open = new QAction("Open", this);
    save = new QAction("Save", this);
    exit = new QAction("Exit", this);

    erose = new QAction("Erosion", this);
    boxFilt = new QAction("Box Filter", this);
    meanFilt = new QAction("Mean Filter", this);
    dilate = new QAction("Dilation", this);
    logTrans = new QAction("Log Transform", this);
    gaussFilt = new QAction("Gauss Filter", this);
    grayTrans = new QAction("Gray Transform", this);
    mediumFilt = new QAction("Medium Filter", this);
    gammaTrans = new QAction("Gamma Transform", this);
    linearTrans = new QAction("Linear Transform", this);
    bilateralFilt = new QAction("Bilateral Filter", this);

    sobelEdge = new QAction("Sobel", this);
    cannyEdge = new QAction("Canny", this);
    erase = new QAction("Eraser", this);
    scharrEdge = new QAction("Scharr", this);
    areaFilled = new QAction("Area Fill", this);
    areaCovered = new QAction("Area Cover", this);
    pickupColor = new QAction("Pick Color", this);
    wakeQQ = new QAction("WakeUp QQ", this);
    screenShot = new QAction("Screen Cut", this);
    fixThres = new QAction("Fix Threshold", this);
    showEdge = new QAction("Show Outline", this);
    regionGrowing = new QAction("Region Grow", this);
    rotScale = new QAction("Rotate Scale", this);
    imgPyramid = new QAction("Image Pyramid", this);
    adaptThres = new QAction("Adapt Threshold", this);
    statisticPix = new QAction("Statistic Pixels", this);
    thresProcess = new QAction("Threshold Process", this);
    calculateDist = new QAction("Calculate Distance", this);
    perspectTrans = new QAction("Perspective Transform", this);

    surfFeature = new QAction("SURF", this);
    fastCornerDetect = new QAction("Fast", this);
    houghGuil = new QAction("Guil", this);
    mserCornerDetect = new QAction("Mser", this);
    gfttCornerDetect = new QAction("GFTT", this);
    houghLine = new QAction("Line", this);
    briskCornerDetect = new QAction("Brisk", this);
    harrisCornerDetect = new QAction("Harris", this);
    houghCircle = new QAction("Circle", this);
    houghBallard = new QAction("Ballard", this);
    houghEllipse = new QAction("Ellipse", this);
    floodFilled = new QAction("Flood Fill", this);
    houghTriangle = new QAction("Triangle", this);
    imgEqual = new QAction("Image Equal", this);
    houghRectangle = new QAction("Rectangle", this);
    shiTomasiCornerDetect = new QAction("Shi Tomasi", this);
    tempMatch = new QAction("Template Match", this);
    upgradeTMatch = new QAction("Upgrade TempMatch", this);
    featurePntMatch = new QAction("Feature Point Match", this);

    addOper = new QAction("Add Operation", this);
    openCal = new QAction("Open Calculate", this);
    closeCal = new QAction("Close Calculate", this);
    lineStretch = new QAction("Linear Stretch", this);
    divideCal = new QAction("Divide Calculate", this);
    multipyCal = new QAction("Multipy Calculate", this);
    fourierTrans = new QAction("Fourier Transform", this);
    laplaceTrans = new QAction("Laplacian Transform", this);
    subtractOper = new QAction("Subtraction Operation", this);

    capLine = new QAction("Capture Line", this);
    capCircle = new QAction("Capture Circle", this);
    capSquare = new QAction("Capture Square", this);
    capEllipse = new QAction("Capture Ellpise", this);
    tessOcr = new QAction("Tesseract OCR", this);
    recogFace = new QAction("Recognize Face", this);
    capTriangle = new QAction("Capture Triangle", this);
    machineLearn = new QAction("Machine Learn", this);
    userModel = new QAction("Customize Model", this);
    capHumaneye = new QAction("Capture HumanEyes", this);
    capSelfmodel = new QAction("Capture SelfDefine", this);
    capChar = new QAction("Capture Character", this);
    capHumanFace = new QAction("Capture HumanFace", this);


    renameFiles = new QAction("Rename Files", this);
    resizeImg = new QAction("Resize Images", this);
    writeToFile = new QAction("Write to Files", this);
    exportImgdata = new QAction("Output ImgData", this);
    exportFileinfo = new QAction("Output FileInfo", this);

    tcpIp = new QAction("Tcp/Ip", this);
    spyderNet = new QAction("Spyder", this);

    launchDB = new QAction("Launch", this);
    videoPage = new QAction("Video Player", this);

    contactCSDN = new QAction("CSDN", this);
    contactGithub = new QAction("Github", this);
    contactJueJin = new QAction("JueJin", this);


    tab1->addSeparator();
    tab1->addAction(open);
    tab1->addAction(save);
    tab1->addAction(exit);

    tab2->addSeparator();
    tab2->addMenu(tab2_1);
    tab2->addMenu(tab2_2);
    tab2->addMenu(tab2_3);
    tab2_1->addAction(grayTrans);
    tab2_1->addAction(logTrans);
    tab2_1->addAction(linearTrans);
    tab2_1->addAction(gammaTrans);
    tab2_2->addAction(boxFilt);
    tab2_2->addAction(meanFilt);
    tab2_2->addAction(mediumFilt);
    tab2_2->addAction(bilateralFilt);
    tab2_2->addAction(gaussFilt);
    tab2_3->addAction(dilate);
    tab2_3->addAction(erose);

    tab3->addMenu(tab3_1);
    tab3_1->addAction(sobelEdge);
    tab3_1->addAction(cannyEdge);
    tab3_1->addAction(scharrEdge);
    tab3->addAction(regionGrowing);
    tab3->addAction(fixThres);
    tab3->addAction(showEdge);
    tab3->addAction(thresProcess);
    tab3->addAction(adaptThres);
    tab3->addAction(areaCovered);
    tab3->addAction(areaFilled);
    tab3->addAction(statisticPix);
    tab3->addAction(perspectTrans);
    tab3->addAction(calculateDist);
    tab3->addAction(rotScale);
    tab3->addAction(imgPyramid);
    tab3->addAction(pickupColor);
    tab3->addAction(screenShot);
    tab3->addAction(wakeQQ);
    tab3->addAction(erase);

    tab4->addAction(divideCal);
    tab4->addAction(openCal);
    tab4->addAction(closeCal);
    tab4->addAction(multipyCal);
    tab4->addAction(lineStretch);
    tab4->addAction(addOper);
    tab4->addAction(subtractOper);
    tab4->addAction(fourierTrans);
    tab4->addAction(laplaceTrans);

    tab5->addAction(surfFeature);
    tab5->addAction(floodFilled);
    tab5->addAction(imgEqual);
    tab5->addAction(tempMatch);
    tab5->addAction(featurePntMatch);
    tab5->addAction(upgradeTMatch);
    tab5_1->addAction(houghLine);
    tab5_1->addAction(houghCircle);
    tab5_1->addAction(houghEllipse);
    tab5_1->addAction(houghTriangle);
    tab5_1->addAction(houghRectangle);
    tab5_1_1->addAction(houghGuil);
    tab5_1_1->addAction(houghBallard);
    tab5_2->addAction(shiTomasiCornerDetect);
    tab5_2->addAction(harrisCornerDetect);
    tab5_2->addAction(fastCornerDetect);
    tab5_2->addAction(briskCornerDetect);
    tab5_2->addAction(mserCornerDetect);
    tab5_2->addAction(gfttCornerDetect);

    tab6->addAction(renameFiles);
    tab6->addAction(writeToFile);
    tab6->addAction(exportImgdata);
    tab6->addAction(resizeImg);
    tab6->addAction(exportFileinfo);

    tab7->addAction(machineLearn);
    tab7->addAction(userModel);
    tab7->addAction(recogFace);
    tab7->addAction(tessOcr);
    tab7->addMenu(tab7_1);
    tab7_1->addAction(capLine);
    tab7_1->addAction(capCircle);
    tab7_1->addAction(capTriangle);
    tab7_1->addAction(capEllipse);
    tab7_1->addAction(capChar);
    tab7_1->addAction(capSelfmodel);
    tab7_1->addAction(capSquare);
    tab7_1->addAction(capHumaneye);
    tab7_1->addAction(capHumanFace);

    tab8->addAction(spyderNet);
    tab8->addAction(tcpIp);
    tab9->addAction(videoPage);
    tab10->addAction(launchDB);
    tab11->addAction(contactGithub);
    tab11->addAction(contactCSDN);
    tab11->addAction(contactJueJin);

    SetIcon();
    setMenuBar(menubar);

    srcBox=new QGraphicsView;
    resBox=new QGraphicsView;

    srcScene=new QGraphicsScene(this);
    resScene=new QGraphicsScene(this);

    srcBox->setDragMode(QGraphicsView::ScrollHandDrag);
    resBox->setDragMode(QGraphicsView::ScrollHandDrag);

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
    tip1->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: green;border-radius: 10px;font-weight: bold; font-style: italic;");
    tip2->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: green;border-radius: 10px;font-weight: bold; font-style: italic;");

    srcBox->setStyleSheet("border: 1px solid "+color3+"; padding: 5px;border-radius: 10px;font-weight: bold;");
    resBox->setStyleSheet("border: 1px solid "+color3+"; padding: 5px;border-radius: 10px;font-weight: bold;");

    bigRes->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: "+color7+";border-radius: 10px;font-weight: bold;");
    bigSrc->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: "+color7+";border-radius: 10px;font-weight: bold;");

    histRes->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: "+color7+";border-radius: 10px;font-weight: bold;");
    histSrc->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: "+color7+";;border-radius: 10px;font-weight: bold;");

    openSider->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: "+color7+";border-radius: 10px;font-weight: bold;");
    closeApp->setStyleSheet("border: 1px solid "+color3+";padding: 5px;color: "+color7+";;border-radius: 10px;font-weight: bold;");

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
    connect(open,&QAction::triggered,this,&QVision::openImg);
    connect(exit,&QAction::triggered,this,&QVision::exitQVision);


    connect(boxFilt,&QAction::triggered,this,&QVision::BoxFilter);
    connect(erose,&QAction::triggered,this,&QVision::Erosion);
    connect(meanFilt,&QAction::triggered,this,&QVision::MeanFilter);
    connect(dilate,&QAction::triggered,this,&QVision::Dilation);
    connect(logTrans,&QAction::triggered,this,&QVision::LogTransform);
    connect(gaussFilt,&QAction::triggered,this,&QVision::GaussFilter);
    connect(grayTrans,&QAction::triggered,this,&QVision::GrayTransform);
    connect(mediumFilt,&QAction::triggered,this,&QVision::MediumFilter);
    connect(gammaTrans,&QAction::triggered,this,&QVision::GammaTransform);
    connect(linearTrans,&QAction::triggered,this,&QVision::LinearTransform);
    connect(bilateralFilt,&QAction::triggered,this,&QVision::BilateralFilter);

    connect(sobelEdge,&QAction::triggered,this,&QVision::Sobel);
    connect(cannyEdge,&QAction::triggered,this,&QVision::Canny);
    connect(erase,&QAction::triggered,this,&QVision::Eraser);
    connect(scharrEdge,&QAction::triggered,this,&QVision::Scharr);
    connect(areaFilled,&QAction::triggered,this,&QVision::AreaFill);
    connect(areaCovered,&QAction::triggered,this,&QVision::AreaCover);
    connect(pickupColor,&QAction::triggered,this,&QVision::PickColor);
    connect(wakeQQ,&QAction::triggered,this,&QVision::WakeUpQQ);
    connect(fixThres,&QAction::triggered,this,&QVision::FixThreshold);
    connect(showEdge,&QAction::triggered,this,&QVision::ShowOutline);
    connect(imgPyramid,&QAction::triggered,this,&QVision::ImagePyramid);
    connect(regionGrowing,&QAction::triggered,this,&QVision::RegionGrow);
    connect(rotScale,&QAction::triggered,this,&QVision::RotateScale);
    connect(adaptThres,&QAction::triggered,this,&QVision::AdaptThreshold);
    connect(screenShot,&QAction::triggered,this,&QVision::CaptureScreen);
    connect(statisticPix,&QAction::triggered,this,&QVision::StatisticPixels);
    connect(thresProcess,&QAction::triggered,this,&QVision::ThresholdProcess);
    connect(calculateDist,&QAction::triggered,this,&QVision::CalculateDistance);
    connect(perspectTrans,&QAction::triggered,this,&QVision::PerspectiveTransform);


    connect(surfFeature,&QAction::triggered,this,&QVision::SURF);
    connect(gfttCornerDetect,&QAction::triggered,this,&QVision::GFTT);
    connect(houghGuil,&QAction::triggered,this,&QVision::Guil);
    connect(houghLine,&QAction::triggered,this,&QVision::Line);
    connect(fastCornerDetect,&QAction::triggered,this,&QVision::Fast);
    connect(mserCornerDetect,&QAction::triggered,this,&QVision::Mser);
    connect(briskCornerDetect,&QAction::triggered,this,&QVision::Brisk);
    connect(houghCircle,&QAction::triggered,this,&QVision::Circle);
    connect(harrisCornerDetect,&QAction::triggered,this,&QVision::Harris);
    connect(houghEllipse,&QAction::triggered,this,&QVision::Ellipse);
    connect(houghBallard,&QAction::triggered,this,&QVision::Ballard);
    connect(floodFilled,&QAction::triggered,this,&QVision::FloodFill);
    connect(imgEqual,&QAction::triggered,this,&QVision::ImageEqual);
    connect(houghTriangle,&QAction::triggered,this,&QVision::Triangle);
    connect(houghRectangle,&QAction::triggered,this,&QVision::Rectangle);
    connect(shiTomasiCornerDetect,&QAction::triggered,this,&QVision::ShiTomasi);
    connect(tempMatch,&QAction::triggered,this,&QVision::TemplateMatch);
    connect(upgradeTMatch,&QAction::triggered,this,&QVision::UpgradeTempMatch);
    connect(featurePntMatch,&QAction::triggered,this,&QVision::FeaturePointMatch);

    connect(addOper,&QAction::triggered,this,&QVision::Add);
    connect(divideCal,&QAction::triggered,this,&QVision::Divide);
    connect(fourierTrans,&QAction::triggered,this,&QVision::Fourier);
    connect(multipyCal,&QAction::triggered,this,&QVision::Multipy);
    connect(openCal,&QAction::triggered,this,&QVision::OpenCalculate);
    connect(laplaceTrans,&QAction::triggered,this,&QVision::Laplacian);
    connect(closeCal,&QAction::triggered,this,&QVision::CloseCalculate);
    connect(lineStretch,&QAction::triggered,this,&QVision::LinearStretch);
    connect(subtractOper,&QAction::triggered,this,&QVision::Subtraction);

    connect(capLine,&QAction::triggered,this,&QVision::CaptureLine);
    connect(capCircle,&QAction::triggered,this,&QVision::CaptureCircle);
    connect(capSquare,&QAction::triggered,this,&QVision::CaptureSquare);
    connect(capEllipse,&QAction::triggered,this,&QVision::CaptureEllpise);
    connect(tessOcr,&QAction::triggered,this,&QVision::TesseractOCR);
    connect(capTriangle,&QAction::triggered,this,&QVision::CaptureTriangle);
    connect(recogFace,&QAction::triggered,this,&QVision::RecongnizeFace);
    connect(capHumaneye,&QAction::triggered,this,&QVision::CaptureHumanEyes);
    connect(capChar,&QAction::triggered,this,&QVision::CaptureCharacter);
    connect(machineLearn,&QAction::triggered,this,&QVision::MachineLearning);
    connect(userModel,&QAction::triggered,this,&QVision::SelfDefineModel);
    connect(capHumanFace,&QAction::triggered,this,&QVision::CaptureHumanFace);
    connect(capSelfmodel,&QAction::triggered,this,&QVision::CaptureArbitaryShape);

    connect(contactCSDN,&QAction::triggered,this,&QVision::CSDN);
    connect(tcpIp,&QAction::triggered,this,&QVision::TCPIP);
    connect(contactGithub,&QAction::triggered,this,&QVision::Follow);
    connect(spyderNet,&QAction::triggered,this,&QVision::Spyder);
    connect(contactJueJin,&QAction::triggered,this,&QVision::JueJin);
    connect(launchDB,&QAction::triggered,this,&QVision::Launch);
    connect(videoPage,&QAction::triggered,this,&QVision::VideoPlayer);
    connect(renameFiles,&QAction::triggered,this,&QVision::RenameFile);
    connect(writeToFile,&QAction::triggered,this,&QVision::WriteToData);
    connect(exportImgdata,&QAction::triggered,this,&QVision::OutputImgData);
    connect(resizeImg,&QAction::triggered,this,&QVision::ResizeImgSize);
    connect(exportFileinfo,&QAction::triggered,this,&QVision::OutputFileInfo);

    srcBox->setScene(srcScene);
    resBox->setScene(resScene);
    srcBox->show();
    resBox->show();
    resize(1000,600);
    setWindowIcon(icon);
    setWindowTitle("Image System");
}

void QVision::wheelEvent(QWheelEvent *event)
{
    QPointF mousePos=event->position();
    double limit=srcBox->width();
    if (event->angleDelta().y() > 0)
    {
        if(mousePos.x()<limit){
            srcBox->scale(1.2, 1.2);
        }else{
            resBox->scale(1.2, 1.2);
        }
    } else {
        if(mousePos.x()<limit){
            srcBox->scale(0.8, 0.8);
        }else{
            resBox->scale(0.8, 0.8);
        }
    }
    event->accept();
}

void QVision::init()
{
    QString runDir=QCoreApplication::applicationDirPath();
    QString configDir = runDir + "/config";
    QDir dir(configDir);
    if (!dir.exists()) dir.mkdir(configDir);
    QString filePath = configDir + "/icon.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        iconSrc = in.readAll();
        file.close();
        this->setWindowIcon(QIcon(iconSrc));
    } else {
        QMessageBox::warning(this, "Warn", "Can't find the program icon!");
    }
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
        srcScene->clear();
        srcScene->addPixmap(QPixmap::fromImage(image).scaled(srcBox->size(),Qt::IgnoreAspectRatio));
    }
}


void QVision::saveImg()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "result1.png", tr("Images (*.png *.jpg *.bmp)"));
    if (!filePath.isEmpty()){
        QPixmap pixmap(resBox->size());
        QPainter painter(&pixmap);
        resScene->render(&painter);
        pixmap.save(filePath);
    }
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

void QVision::SetIcon()
{
    save->setIcon(QIcon(iconSrc));
    exit->setIcon(QIcon(iconSrc));
    open->setIcon(QIcon(iconSrc));
    boxFilt->setIcon(QIcon(iconSrc));
    meanFilt->setIcon(QIcon(iconSrc));
    dilate->setIcon(QIcon(iconSrc));
    erose->setIcon(QIcon(iconSrc));
    logTrans->setIcon(QIcon(iconSrc));
    gaussFilt->setIcon(QIcon(iconSrc));
    grayTrans->setIcon(QIcon(iconSrc));
    mediumFilt->setIcon(QIcon(iconSrc));
    gammaTrans->setIcon(QIcon(iconSrc));
    linearTrans->setIcon(QIcon(iconSrc));
    bilateralFilt->setIcon(QIcon(iconSrc));
    sobelEdge->setIcon(QIcon(iconSrc));
    cannyEdge->setIcon(QIcon(iconSrc));
    erase->setIcon(QIcon(iconSrc));
    scharrEdge->setIcon(QIcon(iconSrc));
    areaFilled->setIcon(QIcon(iconSrc));
    areaCovered->setIcon(QIcon(iconSrc));
    pickupColor->setIcon(QIcon(iconSrc));
    wakeQQ->setIcon(QIcon(iconSrc));
    screenShot->setIcon(QIcon(iconSrc));
    fixThres->setIcon(QIcon(iconSrc));
    showEdge->setIcon(QIcon(iconSrc));
    regionGrowing->setIcon(QIcon(iconSrc));
    rotScale->setIcon(QIcon(iconSrc));
    imgPyramid->setIcon(QIcon(iconSrc));
    adaptThres->setIcon(QIcon(iconSrc));
    statisticPix->setIcon(QIcon(iconSrc));
    thresProcess->setIcon(QIcon(iconSrc));
    calculateDist->setIcon(QIcon(iconSrc));
    perspectTrans->setIcon(QIcon(iconSrc));
    surfFeature->setIcon(QIcon(iconSrc));
    fastCornerDetect->setIcon(QIcon(iconSrc));
    houghGuil->setIcon(QIcon(iconSrc));
    mserCornerDetect->setIcon(QIcon(iconSrc));
    gfttCornerDetect->setIcon(QIcon(iconSrc));
    houghLine->setIcon(QIcon(iconSrc));
    briskCornerDetect->setIcon(QIcon(iconSrc));
    harrisCornerDetect->setIcon(QIcon(iconSrc));
    houghCircle->setIcon(QIcon(iconSrc));
    houghBallard->setIcon(QIcon(iconSrc));
    houghEllipse->setIcon(QIcon(iconSrc));
    floodFilled->setIcon(QIcon(iconSrc));
    houghTriangle->setIcon(QIcon(iconSrc));
    imgEqual->setIcon(QIcon(iconSrc));
    houghRectangle->setIcon(QIcon(iconSrc));
    shiTomasiCornerDetect->setIcon(QIcon(iconSrc));
    tempMatch->setIcon(QIcon(iconSrc));
    upgradeTMatch->setIcon(QIcon(iconSrc));
    featurePntMatch->setIcon(QIcon(iconSrc));
    addOper->setIcon(QIcon(iconSrc));
    openCal->setIcon(QIcon(iconSrc));
    closeCal->setIcon(QIcon(iconSrc));
    lineStretch->setIcon(QIcon(iconSrc));
    divideCal->setIcon(QIcon(iconSrc));
    multipyCal->setIcon(QIcon(iconSrc));
    fourierTrans->setIcon(QIcon(iconSrc));
    laplaceTrans->setIcon(QIcon(iconSrc));

    subtractOper->setIcon(QIcon(iconSrc));
    capLine->setIcon(QIcon(iconSrc));
    capCircle->setIcon(QIcon(iconSrc));
    capSquare->setIcon(QIcon(iconSrc));
    capEllipse->setIcon(QIcon(iconSrc));
    tessOcr->setIcon(QIcon(iconSrc));
    recogFace->setIcon(QIcon(iconSrc));

    capTriangle->setIcon(QIcon(iconSrc));
    machineLearn->setIcon(QIcon(iconSrc));
    userModel->setIcon(QIcon(iconSrc));
    capHumaneye->setIcon(QIcon(iconSrc));
    capSelfmodel->setIcon(QIcon(iconSrc));
    capChar->setIcon(QIcon(iconSrc));
    capHumanFace->setIcon(QIcon(iconSrc));
    renameFiles->setIcon(QIcon(iconSrc));
    resizeImg->setIcon(QIcon(iconSrc));

    writeToFile->setIcon(QIcon(iconSrc));
    exportImgdata->setIcon(QIcon(iconSrc));
    exportFileinfo->setIcon(QIcon(iconSrc));
    tcpIp->setIcon(QIcon(iconSrc));
    spyderNet->setIcon(QIcon(iconSrc));
    launchDB->setIcon(QIcon(iconSrc));
    videoPage->setIcon(QIcon(iconSrc));
    contactJueJin->setIcon(QIcon(iconSrc));
    contactGithub->setIcon(QIcon(iconSrc));
    contactCSDN->setIcon(QIcon(iconSrc));
}


void QVision::Show()
{
    QImage img;
    if(!Dst.empty()){
        if (Dst.channels() == 1){
            img = QImage(Dst.data, Dst.cols, Dst.rows, Dst.step, QImage::Format_Grayscale8);
        }else{
            img = QImage(Dst.data, Dst.cols, Dst.rows, Dst.step, QImage::Format_BGR888);
        }
        QPixmap pixmap = QPixmap::fromImage(img).scaled(srcBox->size(),Qt::IgnoreAspectRatio);
        resScene->addPixmap(pixmap);
    }
}

void QVision::Show(Mat image)
{
    QImage img;
    if (image.channels() == 1){
        img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_Grayscale8);
    }else{
        img = QImage(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);
    }
    QPixmap pixmap = QPixmap::fromImage(img).scaled(srcBox->size(),Qt::IgnoreAspectRatio);
    resScene->addPixmap(pixmap);
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
    QPixmap pixmap = srcBox->grab();
    Src = QPixmap2Mat(pixmap);
    Tools::ins().ShowHistogram(Src);
}


void QVision::ResHist()
{
    if(!IsImgOpen()||resScene->items().empty()) return;
    QPixmap pixmap = resBox->grab();
    Dst = QPixmap2Mat(pixmap);
    Tools::ins().ShowHistogram(Dst);
}

void QVision::BigSrc()
{
    if(!IsImgOpen()) return;
    Tools::ins().MakeBig(Src);
    // resScene->addPixmap(Tools::ins().tmp);
}


void QVision::BigRes()
{
    if(!IsImgOpen()) return;
    Tools::ins().MakeBig(Dst);
}


void QVision::closeQVision()
{
    QApplication::quit();
}

//预处理
void QVision::GrayTransform()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().GrayTransform(Src);
    Show(Dst);
}


void QVision::LogTransform()
{
    if(!IsImgOpen()) return;
    bool ok;
    int log=QInputDialog::getInt(this,tr("设置值"),tr("Log:"),5,0,100,1,&ok);
    if(ok) Dst=Preprocess::ins().LogTransform(Src,log);
    Show(Dst);
}


void QVision::LinearTransform()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().LinearTransform(Src);
    Show(Dst);
}


void QVision::GammaTransform()
{
    if(!IsImgOpen()) return;
    bool ok;
    double gamma = QInputDialog::getDouble(this, tr("设置值"), tr("gamma:"), 2.0, 0, 10, 2, &ok);
    if(ok) Dst = Preprocess::ins().GammaTransform(Src, gamma);
    Show(Dst);
}


void QVision::BoxFilter()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().BoxFilter(Src);
    Show(Dst);
}


void QVision::MeanFilter()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().MeanFilter(Src);
    Show(Dst);
}


void QVision::MediumFilter()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().MediumFilter(Src);
    Show(Dst);
}


void QVision::BilateralFilter()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().BilateralFilter(Src);
    Show(Dst);
}

void QVision::GaussFilter()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().GaussFilter(Src);
    Show(Dst);
}


void QVision::Dilation()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().Dilation(Src);
    Show(Dst);
}


void QVision::Erosion()
{
    if(!IsImgOpen()) return;
    Dst=Preprocess::ins().Erosion(Src);
    Show(Dst);
}

//工具
void QVision::Sobel()
{
    if(!IsImgOpen()) return;
    Dst=Tools::ins().EdgeSobel(Src);
    Show();
}


void QVision::Canny()
{
    if(!IsImgOpen()) return;
    if(CannyDlg::ins().exec()== QDialog::Accepted){
        int L=CannyDlg::ins().getValue(0);
        int H=CannyDlg::ins().getValue(1);
        CannyDlg::ins().setValue(H,L);
        CannyDlg::ins().low= CannyDlg::ins().getValue(0);
        CannyDlg::ins().high =CannyDlg::ins().getValue(1);
        Dst = Tools::ins().EdgeCanny(Src,L,H);
        Show();
    }
}


void QVision::Scharr()
{
    if(!IsImgOpen()) return;
    Dst=Tools::ins().Edgescharr(Src);
    Show();
}


void QVision::RegionGrow()
{
    if(!IsImgOpen()) return;
    bool ok;
    int threshold=QInputDialog::getInt(this,tr("设置阈值"),tr("value:"),100,0,255,10,&ok);
    Point seedPoint(10, 10);
    Mat visited = Mat::zeros(Src.size(), CV_8U);
    if(ok) Dst = Tools::ins().RegionGrow(Src, seedPoint, threshold, visited);
    Show(Dst);
}


void QVision::FixThreshold()
{
    if(!IsImgOpen()) return;
    if(FixThresholdDlg::ins().exec()== QDialog::Accepted){
        int val=FixThresholdDlg::ins().getValue();
        FixThresholdDlg::ins().setValue(val);
        FixThresholdDlg::ins().Val=val;
        Dst = Tools::ins().FixThreshold(Src, val);
        Show();
    }
}


void QVision::ShowOutline()
{
    if(!IsImgOpen()) return;
    bool ok;
    int val=QInputDialog::getInt(this,tr("设置阈值"),tr("value:"),100,0,255,10,&ok);
    if(ok) Dst=Tools::ins().ShowOutline(Src,val);
    Show();
}


void QVision::ThresholdProcess()
{
    if(!IsImgOpen()) return;
    if(ThresholdDlg::ins().exec()== QDialog::Accepted){
        int type=ThresholdDlg::ins().getValue(1);
        int val=ThresholdDlg::ins().getValue(2);
        ThresholdDlg::ins().setValue(val,type);
        ThresholdDlg::ins().thresval=type;
        ThresholdDlg::ins().threstype =val;
        Dst=Tools::ins().ThresholdProcess(Src,val,type);
        Show();
    }
}


void QVision::AdaptThreshold()
{
    if(!IsImgOpen()) return;
    int size=15;
    bool ok;
    double para = QInputDialog::getDouble(this, tr("设置系数"), tr("x:"), 2.0, 0, 10, 2, &ok);
    if(ok) Dst=Tools::ins().AdaptThreshold(Src,size,para);
    Show();
}


void QVision::AreaCover()
{
    if(!IsImgOpen()) return;
    Dst=Tools::ins().AreaCover(Src);
    Show();
}


void QVision::AreaFill()
{
    if(!IsImgOpen()) return;
    Scalar fill=Tools::ins().PickColor();
    if(AreaFillDlg::ins().exec()== QDialog::Accepted){
        int setNum=AreaFillDlg::ins().getValue(1);
        int setSize=AreaFillDlg::ins().getValue(2);
        AreaFillDlg::ins().setValue(setSize,setNum);
        AreaFillDlg::ins().PointSize = setSize;
        AreaFillDlg::ins().PointNum = setNum;
        Dst=Tools::ins().AreaFill(Src,fill,setSize,setNum);
        Show();
    }
}


void QVision::StatisticPixels()
{
    if(!IsImgOpen())return;
    if(StatisticPixelDlg::ins().exec()== QDialog::Accepted){
        int pixval=StatisticPixelDlg::ins().getValue();
        StatisticPixelDlg::ins().setValue(pixval);
        StatisticPixelDlg::ins().pixelval=pixval;
        int num = Tools::ins().Statistic(Src,pixval);
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
        Dst=Tools::ins().PersTransform(SI, TGI);
        Show();
    }
}


void QVision::CalculateDistance()
{
    if(CalcuDistDlg::ins().exec()== QDialog::Accepted)
    {
        int curx1=CalcuDistDlg::ins().getValue(1);
        int cury1=CalcuDistDlg::ins().getValue(2);
        int curx2=CalcuDistDlg::ins().getValue(3);
        int cury2=CalcuDistDlg::ins().getValue(4);
        CalcuDistDlg::ins().setValue(curx1,cury1,curx2,cury2);
        CalcuDistDlg::ins().x1 = curx1;
        CalcuDistDlg::ins().y1 = cury1;
        CalcuDistDlg::ins().x2 = curx2;
        CalcuDistDlg::ins().y2 = cury2;
        int res=Tools::ins().CalcDist(curx1,cury1,curx2,cury2);
        QMessageBox::information(this,tr("提示"),tr("两点间距离为:%1").arg(res));
    }
}


void QVision::RotateScale()
{
    if(!IsImgOpen())return;
    if(RotScaleDlg::ins().exec()== QDialog::Accepted)
    {
        double rotate=RotScaleDlg::ins().getValue();
        double scale=RotScaleDlg::ins().getDValue();
        RotScaleDlg::ins().setValue(rotate,scale);
        RotScaleDlg::ins().rotate = rotate;
        RotScaleDlg::ins().scale = scale;
        Dst=Tools::ins().RotateScale(Src,rotate,scale);
        Show();
    }
}


void QVision::ImagePyramid()
{
    if(!IsImgOpen()) return;
    Tools::ins().Pyramid(Src);
}


void QVision::PickColor()
{
    Tools::ins().PickColor();
}

void QVision::CaptureScreen()
{
    ScreenCut::ins().show();
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
    bool ok;
    Mat des;
    QMessageBox select;
    select.setText("选择操作对象");
    QPushButton *srcQBtn = select.addButton(tr("原始图"), QMessageBox::ActionRole);
    QPushButton *resQBtn = select.addButton(tr("结果图"), QMessageBox::ActionRole);
    select.exec();
    Scalar eraseColor=Tools::ins().PickColor();
    int penSize = QInputDialog::getInt(this, "设置", "画笔尺寸:",40,0,255,10,&ok);
    if (select.clickedButton() == srcQBtn)
    {
        des = Src;
    }
    else if (select.clickedButton() == resQBtn)
    {
        if(Dst.empty()) return;
        des = Dst;

    }
    else
    {
        return;
    }
    if(ok) Dst=Tools::ins().EraseArea(des,eraseColor,penSize);
    Show();
}

//图像运算
void QVision::Divide()
{
    if(!IsImgOpen()) return;
    Dst=ImgCalculate::ins().Divide(Src);
    Show();
}


void QVision::OpenCalculate()
{
    if(!IsImgOpen()) return;
    Dst=ImgCalculate::ins().OnCalc(Src);
    Show();
}


void QVision::CloseCalculate()
{
    if(!IsImgOpen()) return;
    Dst=ImgCalculate::ins().OffCalc(Src);
    Show();
}


void QVision::Multipy()
{
    if(!IsImgOpen()) return;
    Dst=ImgCalculate::ins().Multipy(Src);
    Show();
}


void QVision::LinearStretch()
{
    if(!IsImgOpen()) return;
    Dst=ImgCalculate::ins().LineStretch(Src);
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
    Dst=ImgCalculate::ins().Add(s1,s2);
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
    Dst=ImgCalculate::ins().Subtraction(s1,s2);
    Show();
}


void QVision::Fourier()
{
    if(!IsImgOpen()) return;
    Dst=ImgCalculate::ins().FourierTransform(Src);
    Show();
}


void QVision::Laplacian()
{
    if(!IsImgOpen()) return;
    Dst=ImgCalculate::ins().LaplacianTransform(Src);
    Show();
}

//图像算法
void QVision::SURF()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().SURF(Src);
    Show();
}


void QVision::FloodFill()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().FloodFill(Src);
    Show();
}


void QVision::ImageEqual()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().HistEqual(Src);
    Show();
}


void QVision::TemplateMatch()
{
    QString temPath = getFilepath();
    QString srcPath = getFilepath();
    if (temPath.isEmpty()||srcPath.isEmpty()) return;
    Mat src = imread(srcPath.toStdString());
    Mat temp = imread(temPath.toStdString());
    if(TemplateMatchDlg::ins().exec()== QDialog::Accepted){
        int curThresh=TemplateMatchDlg::ins().getValue();
        TemplateMatchDlg::ins().setValue(curThresh);
        TemplateMatchDlg::ins().thresh=curThresh;
        Dst=ImgAlgorithm::ins().MatchTemp(src, temp, curThresh);
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
    Dst=ImgAlgorithm::ins().FeaturePointMatch(src1,src2);
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
    if(UpgradeTempMatchDlg::ins().exec()== QDialog::Accepted){
        int ImgThres=UpgradeTempMatchDlg::ins().getValue();
        double scalestep=UpgradeTempMatchDlg::ins().getValue(1);
        double overlapThres=UpgradeTempMatchDlg::ins().getValue(2);
        double MinscaleRatio=UpgradeTempMatchDlg::ins().getValue(3);
        double MaxscaleRatio=UpgradeTempMatchDlg::ins().getValue(4);
        double PreProcessThres=UpgradeTempMatchDlg::ins().getValue(5);
        UpgradeTempMatchDlg::ins().ImgThres=ImgThres;
        UpgradeTempMatchDlg::ins().ScaleStep=scalestep;
        UpgradeTempMatchDlg::ins().OverlapThres=overlapThres;
        UpgradeTempMatchDlg::ins().MinScaleRatio=MinscaleRatio;
        UpgradeTempMatchDlg::ins().MaxScaleRatio=MaxscaleRatio;
        UpgradeTempMatchDlg::ins().PreProcessThres=PreProcessThres;
        Dst=ImgAlgorithm::ins().UpgradeMatchTemp(temp, src, ImgThres, scalestep, MinscaleRatio, MaxscaleRatio,overlapThres,PreProcessThres);
        Save(Dst);
        Show();
    }
}


void QVision::Line()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().HoughLine(Src);
    Show();
}


void QVision::Circle()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().HoughCircle(Src);
    Show();
}


void QVision::Ellipse()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().HoughEllipse(Src);
    Show();
}


void QVision::Triangle()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().HoughTriangle(Src);
    Show();
}

void QVision::Rectangle()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().HoughRectangle(Src);
    Show();
}

void QVision::Ballard()
{
    QString temPath = getFilepath();
    QString srcPath = getFilepath();
    if (temPath.isEmpty()||srcPath.isEmpty()) return;
    Mat temp = imread(temPath.toStdString());
    Mat src = imread(srcPath.toStdString());
    if(BallardDlg::ins().exec()== QDialog::Accepted)
    {
        int mindist=BallardDlg::ins().getValue(1);
        int level=BallardDlg::ins().getValue(2);
        double dp=BallardDlg::ins().getValue(3);
        int buffersize=BallardDlg::ins().getValue(4);
        int vote=BallardDlg::ins().getValue(5);
        int cannylow=BallardDlg::ins().getValue(6);
        int cannyhigh=BallardDlg::ins().getValue(7);
        BallardDlg::ins().setValue(mindist,level,dp,buffersize,vote,cannylow,cannyhigh);
        BallardDlg::ins().mindist=mindist;
        BallardDlg::ins().level=level;
        BallardDlg::ins().dp=dp;
        BallardDlg::ins().buffersize=buffersize;
        BallardDlg::ins().vote=vote;
        BallardDlg::ins().cannylow=cannylow;
        BallardDlg::ins().cannyhigh=cannyhigh;
        Dst=ImgAlgorithm::ins().HoughBallard(src,temp,mindist,level,dp,buffersize,vote,cannylow,cannyhigh);
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
    if(GuilDlg::ins().exec()== QDialog::Accepted)
    {
        int mindist=GuilDlg::ins().getValue(MINDIST);
        int level=GuilDlg::ins().getValue(LEVEL);
        double dp=GuilDlg::ins().getDValue(DP);
        double xi=GuilDlg::ins().getDValue(XI);
        int buffersize=GuilDlg::ins().getValue(BUFFERSIZE);
        int cannylow=GuilDlg::ins().getValue(CANNYLOWTHRESHOLD);
        int cannyhigh=GuilDlg::ins().getValue(CANNYHIGHTHRESHOLD);
        int minangle=GuilDlg::ins().getValue(MINANGLE);
        int maxangle=GuilDlg::ins().getValue(MAXANGLE);
        int anglestep=GuilDlg::ins().getValue(ANGLESTEP);
        int anglethreshold=GuilDlg::ins().getValue(ANGLETHRESHOLD);
        float minscale=GuilDlg::ins().getFValue(MINSCALE);
        float maxscale=GuilDlg::ins().getFValue(MAXSCALE);
        float angleplise=GuilDlg::ins().getFValue(ANGLEEPSILON);
        double scalestep=GuilDlg::ins().getDValue(SCALESTEP);
        int scalethreshold=GuilDlg::ins().getValue(SCALETHRESHOLD);
        int posthreshold=GuilDlg::ins().getValue(POSITIONTHRESHOLD);
        qInfo()<<"minangle"<<minangle;
        qInfo()<<"maxangle"<<maxangle;
        qInfo()<<"minscale"<<minscale;
        qInfo()<<"maxscale"<<maxscale;
        qInfo()<<"scalestep"<<scalestep;
        GuilDlg::ins().setValue(mindist,level,dp,xi,buffersize,cannylow,cannyhigh,minangle,maxangle,anglestep,anglethreshold,
                                minscale,maxscale,angleplise,scalestep,scalethreshold,posthreshold);
        GuilDlg::ins().mindist=mindist;
        GuilDlg::ins().level=level;
        GuilDlg::ins().dp=dp;
        GuilDlg::ins().xi=xi;
        GuilDlg::ins().buffersize=buffersize;
        GuilDlg::ins().cannylow=cannylow;
        GuilDlg::ins().cannyhigh=cannyhigh;
        GuilDlg::ins().minangle=minangle;
        GuilDlg::ins().maxangle=maxangle;
        GuilDlg::ins().anglestep=anglestep;
        GuilDlg::ins().anglethreshold=anglethreshold;
        GuilDlg::ins().minscale=minscale;
        GuilDlg::ins().maxscale=maxscale;
        GuilDlg::ins().angleplise=angleplise;
        GuilDlg::ins().scalestep=scalestep;
        GuilDlg::ins().scalethreshold=scalethreshold;
        GuilDlg::ins().posthreshold=posthreshold;
        try
        {
            Dst=ImgAlgorithm::ins().HoughGuil(src,temp,mindist,level,dp,xi,buffersize,cannylow,cannyhigh,minangle,maxangle,anglestep,
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
    Dst=ImgAlgorithm::ins().ShiTomasiDetect(Src);
    Show();
}


void QVision::Harris()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().HarrisDetect(Src);
    Show();
}


void QVision::Fast()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().FASTDetect(Src);
    Show();
}


void QVision::Brisk()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().BRISKDetect(Src);
    Show();
}


void QVision::Mser()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().MSERDetect(Src);
    Show();
}


void QVision::GFTT()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().GFTTDetect(Src);
    Show();
}


//模型、检测
void QVision::MachineLearning()
{
    MachineLearning::ins().show();
}

void QVision::SelfDefineModel()
{
    if(!IsImgOpen()) return;
    QString modelPath=getModel();
    Dst=ImgAlgorithm::ins().SelfModel(Src,modelPath);
    Show();
}

void QVision::RecongnizeFace()
{
    if(!IsImgOpen()) return;
    Dst=ImgAlgorithm::ins().DetectFaceFromImg(Src);
    Show();
}

void QVision::TesseractOCR()
{
    CharRecogDlg::ins().show();
}


void QVision::CaptureLine()
{
    DynamicDetect::ins().DetectLine();
}


void QVision::CaptureCircle()
{
    DynamicDetect::ins().DetectCircle();
}


void QVision::CaptureTriangle()
{
    DynamicDetect::ins().DetectTriangle();
}

void QVision::CaptureSquare()
{
    DynamicDetect::ins().DetectSquare();
}

void QVision::CaptureEllpise()
{
    DynamicDetect::ins().DetectEllpise();
}

void QVision::CaptureCharacter()
{
    DynamicDetect::ins().DetectCharacter();
}

void QVision::CaptureHumanEyes()
{
    DynamicDetect::ins().DetectEye();
}

void QVision::CaptureHumanFace()
{
    DynamicDetect::ins().DetectFace();
}

void QVision::CaptureArbitaryShape()
{
    QString usermodelPath=QFileDialog::getOpenFileName(this,"获取模型","eg.xml","选择模型(*.xml)");
    DynamicDetect::ins().DetectByUserCreateModel(usermodelPath);
}

//文件操作
void QVision::RenameFile()
{
    if(RenameDlg::ins().exec()== QDialog::Accepted)
    {
        QString dir = RenameDlg::ins().getValue(1);
        QString exten = RenameDlg::ins().getValue(2);
        QString prefix=RenameDlg::ins().getValue(3);
        int num = RenameDlg::ins().getValue();
        RenameDlg::ins().setValue(num,dir,exten,prefix);
        RenameDlg::ins().incre=num;
        RenameDlg::ins().dir=dir;
        RenameDlg::ins().exten=exten;
        RenameDlg::ins().prefix=prefix;
        int renamed=FileOperation::ins().RenameFile(dir,prefix,num,exten);
        QMessageBox::information(this,tr("提示"),tr("已重命名文件数:%1").arg(renamed));
    }else{
        QMessageBox::information(this,tr("提示"),tr("已取消!"));
        return;
    }
}


void QVision::WriteToData()
{
    if(WriteDataDlg::ins().exec()==QDialog::Accepted)
    {
        QString dir =WriteDataDlg::ins().getInfo(1);
        QString context =WriteDataDlg::ins().getInfo(2);
        QString other =WriteDataDlg::ins().getInfo(3);
        int Num =WriteDataDlg::ins().getValue(1);
        int Incre =WriteDataDlg::ins().getValue(2);
        WriteDataDlg::ins().setValue(Num,Incre,dir,context,other);
        WriteDataDlg::ins().wnum=Num;
        WriteDataDlg::ins().increvar=Incre;
        WriteDataDlg::ins().dir=dir;
        WriteDataDlg::ins().context=context;
        WriteDataDlg::ins().other=other;
        FileOperation::ins().WriteToFile(dir,context,other,Num,Incre);
        QMessageBox::information(this,tr("提示"),tr("内容已写入"));
    }else{
        QMessageBox::information(this,tr("提示"),tr("已取消!"));
        return;
    }
}


void QVision::OutputImgData()
{
    QString dir=getFolder();
    QString savepath=getOutputpath();
    if(dir.isEmpty()||savepath.isEmpty()){
        QMessageBox::warning(this,"警告","未选择导出目录!");
        return;
    }
    FileOperation::ins().GetImgData(dir,savepath);
}


void QVision::ResizeImgSize()
{
    QString sourceDir = getFolder();
    QString outputDir = getFolder();
    if(sourceDir.isEmpty()||outputDir.isEmpty()){
        QMessageBox::warning(this,"警告","未选择导出目录!");
        return;
    }
    if(ResizeDlg::ins().exec()== QDialog::Accepted){
        int W=ResizeDlg::ins().getValue(1);
        int H=ResizeDlg::ins().getValue(2);
        ResizeDlg::ins().setValue(W,H);
        ResizeDlg::ins().w=W;
        ResizeDlg::ins().h=H;
        FileOperation::ins().ResizeImg(sourceDir,outputDir,W, H);
        QMessageBox::information(this,tr("提示"),tr("数据已写入!"));
    }
}


void QVision::OutputFileInfo()
{
    QString dir=getFolder();
    QString savepath=getOutputpath();
    if(dir.isEmpty()||savepath.isEmpty()){
        QMessageBox::warning(this,"警告","未选择导出目录!");
        return;
    }
    FileOperation::ins().ExportFiles(dir,savepath);
}


//NetWork Programming
void QVision::Spyder()
{
    if(NetSpyderDlg::ins().exec()==QDialog::Accepted){
        QString url=NetSpyderDlg::ins().getValue(1);
        QString keyword=NetSpyderDlg::ins().getValue(2);
        QString path=NetSpyderDlg::ins().getValue(3);
        QString html=NetSpyderDlg::ins().getValue(4);
        NetSpyderDlg::ins().setValue(url,keyword,path,html);
        NetSpyderDlg::ins().url=url;
        NetSpyderDlg::ins().keyword=keyword;
        NetSpyderDlg::ins().savePath=path;
        NetSpyderDlg::ins().htmlCode=html;
    }
}

void QVision::TCPIP()
{
    NetworkCommunication::ins().show();
}

//多媒体
void QVision::VideoPlayer()
{
    MultiMedia::ins().resize(640,480);
    MultiMedia::ins().show();
}


//数据库
void QVision::Launch()
{
    DataBase::ins().show();
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
    QWidget *drawer1 = new QWidget(this);
    QWidget *drawer2 = new QWidget(this);

    QVBoxLayout *layout = new QVBoxLayout(drawer1);
    QVBoxLayout *drawer2Layout = new QVBoxLayout(drawer2);
    QHBoxLayout *row1 = new QHBoxLayout();
    QHBoxLayout *row2 = new QHBoxLayout();

    searchIp = new QPushButton("ip查询", drawer1);
    qtChart = new QPushButton("显示图表", drawer1);
    scanwifi = new QPushButton("wifi扫描", drawer1);
    deviceInfo = new QPushButton("设备信息", drawer1);
    remoteSignIn = new QPushButton("远程登录", drawer1);
    showCoord = new QPushButton("坐标系", drawer1);
    fixIcon = new QPushButton("修改图标", drawer1);
    searchIp->setIcon(QIcon(iconSrc));

    heapS = new QPushButton("堆排序", drawer2);
    shellS = new QPushButton("希尔排序", drawer2);
    bubbleS = new QPushButton("冒泡排序", drawer2);
    insertS = new QPushButton("插入排序", drawer2);
    selectS = new QPushButton("选择排序", drawer2);
    quickS = new QPushButton("快速排序", drawer2);
    mergeS = new QPushButton("归并排序", drawer2);
    testdll = new QPushButton("dll", drawer2);


    row1->addWidget(scanwifi);
    row1->addWidget(deviceInfo);
    row1->addWidget(showCoord);

    row2->addWidget(remoteSignIn);
    row2->addWidget(qtChart);
    row2->addWidget(searchIp);
    row2->addWidget(fixIcon);

    layout->addLayout(row1);
    layout->addLayout(row2);

    drawer2Layout->addWidget(heapS);
    drawer2Layout->addWidget(shellS);
    drawer2Layout->addWidget(bubbleS);
    drawer2Layout->addWidget(insertS);
    drawer2Layout->addWidget(selectS);
    drawer2Layout->addWidget(quickS);
    drawer2Layout->addWidget(mergeS);
    drawer2Layout->addWidget(testdll);

    siderBar.addItem(drawer1, "Drawer1");
    siderBar.addItem(drawer2, "Drawer2");

    connect(scanwifi, &QPushButton::clicked, this, &QVision::ScanNearWifi);
    connect(qtChart, &QPushButton::clicked, this, &QVision::DisplayQtChart);
    connect(searchIp, &QPushButton::clicked, this, &QVision::SearchLocation);
    connect(remoteSignIn, &QPushButton::clicked, this, &QVision::RemotelogIn);
    connect(deviceInfo, &QPushButton::clicked, this, &QVision::GetDeviceInfo);
    connect(showCoord, &QPushButton::clicked, this, &QVision::ShowCoordinateSystem);
    connect(fixIcon, &QPushButton::clicked, this, &QVision::ChangeSoftWareIcon);


    connect(heapS, &QPushButton::clicked, this, &QVision::heapSort);
    connect(shellS, &QPushButton::clicked, this, &QVision::shellSort);
    connect(quickS, &QPushButton::clicked, this, &QVision::quickSort);
    connect(mergeS, &QPushButton::clicked, this, &QVision::mergeSort);
    connect(testdll, &QPushButton::clicked, this, &QVision::dlldemo);
    connect(bubbleS, &QPushButton::clicked, this, &QVision::insertSort);/////
    connect(insertS, &QPushButton::clicked, this, &QVision::insertSort);
    connect(selectS, &QPushButton::clicked, this, &QVision::selectSort);
    siderBar.resize(300, 400);
    siderBar.show();
}

void QVision::dlldemo()
{
    if(!import.loadLib("Sort.dll")) return;
    Ptrs = import.getAllFuncPtrs();
    currentFunPtr=Ptrs["bubbleSort"];
    if(currentFunPtr){
        int arr[] = {3, 1, 4, 5, 9, 2, 6};
        int len = sizeof(arr) / sizeof(arr[0]);
        funcType bubbleSort=reinterpret_cast<funcType>(currentFunPtr);
        bubbleSort(arr,len);
        for(auto a:arr) qInfo()<<a;
    }
}

void QVision::heapSort()
{
    QVector<int> array;
    array.append({5,2,6,1,8,9,3,7,4});
    qInfo()<<"原始数组:"<<array;
    Sort::ins().heapSort(array);
    qInfo()<<"排序后:"<<array;
}

void QVision::shellSort()
{
    QVector<int> array;
    array.append({5,2,6,1,8,9,3,7,4});
    qInfo() << "原始数组:" << array;
    Sort::ins().shellSort(array);
    qInfo()<<"排序后:"<<array;
}

void QVision::quickSort()
{
    QVector<int> array;
    array.append({5,2,6,1,8,9,3,7,4});
    qInfo() << "原始数组:" << array;
    Sort::ins().quickSort(array,0,array.size()-1);
    qInfo()<<"排序后:"<<array;
}

void QVision::mergeSort()
{
    QVector<int> array;
    array.append({5,2,6,1,8,9,3,7,4});
    qInfo() << "原始数组:" << array;
    Sort::ins().mergeSort(array, 0, array.size() - 1);
    qInfo() << "排序后:" << array;
}

// void QVision::bubbleSort()
// {
// QVector<int> array;
// array.append({5,2,6,1,8,9,3,7,4});
// qInfo() << "原始数组:" << array;
// Sort::ins().bubblesort(array);
// qInfo()<<"排序后:"<<array;
// }

void QVision::insertSort()
{
    QVector<int> array;
    array.append({5,2,6,1,8,9,3,7,4});
    qInfo() << "原始数组:" << array;
    Sort::ins().insertSort(array);
    qInfo()<<"排序后:"<<array;
}

void QVision::selectSort()
{
    QVector<int> array;
    array.append({5,2,6,1,8,9,3,7,4});
    qInfo() << "原始数组:" << array;
    Sort::ins().selectSort(array);
    qInfo()<<"排序后:"<<array;
}

void QVision::ScanNearWifi()
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach (const QNetworkInterface &interface, interfaces)
    {
        if (interface.type() == QNetworkInterface::Wifi)
        {
            QMessageBox::information(this,tr("WiFi"),tr("SSID:%1").arg(interface.humanReadableName()));
        }
    }
}

void QVision::RemotelogIn()
{
    RemoteLogin::ins().show();
}

void QVision::GetDeviceInfo()
{
    QString deviceInfo;
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, interfaces) {
        deviceInfo += "接口名称: " + interface.name() + "\n";
        deviceInfo += "MAC地址: " + interface.hardwareAddress() + "\n";
    }

    foreach (QHostAddress address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost)) {
            deviceInfo += "IP地址: " + address.toString() + "\n";
        }
    }

    deviceInfo += "操作系统: " + QSysInfo::prettyProductName() + "\n";
    deviceInfo += "处理器架构: " + QSysInfo::currentCpuArchitecture() + "\n";
    deviceInfo += "内核类型: " + QSysInfo::kernelType() + "\n";
    deviceInfo += "内核版本: " + QSysInfo::kernelVersion() + "\n";
    QMessageBox::information(nullptr, "设备信息", deviceInfo);
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
    if(ipAddress.isNull()){
        QMessageBox::warning(this,tr("警告"),tr("ip为空!"));
        return;
    }
    QUrl url("http://ip-api.com/json/" + ipAddress);
    request.setUrl(url);
    QNetworkReply *reply = manager.get(request);
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
        QJsonObject jsonObj = jsonDoc.object();
        QString stat = jsonObj["status"].toString();
        QString contin = jsonObj["continent"].toString();
        QString contrycode = jsonObj["contryCode"].toString();
        QString curren = jsonObj["currency"].toString();
        QString timezo = jsonObj["timezone"].toString();
        QString netisp = jsonObj["isp"].toString();
        QString iscellphone = jsonObj["mobile"].toString();
        QString isproxy = jsonObj["proxy"].toString();
        QString host = jsonObj["hosting"].toString();
        QString latitude = jsonObj["lat"].toString();
        QString longtitude = jsonObj["lon"].toString();
        QString country = jsonObj["country"].toString();
        QString city = jsonObj["city"].toString();
        QString region = jsonObj["regionName"].toString();
        QString street = jsonObj["district"].toString();

        res+="查询状态:"+stat;
        res+="<经度>"+latitude;
        res+="<纬度>"+longtitude;
        res+="<位于洲>"+contin;
        res+="<国家>"+country;
        res+="<城市>"+city;
        res+="<地区>"+region;
        res+="<街道>"+street;
        res+="<货币>"+curren;
        res+="<时区>"+timezo;
        res+="<运营商>"+netisp;
        res+="<是否手机>"+iscellphone;
        res+="<使用代理>"+isproxy;
        res+="<是否主机>"+host;
        res+="<国家代码>"+contrycode;
        QMessageBox::information(this,tr("查询结果"),tr("详细信息:%1").arg(res));
    } else {
        QMessageBox::warning(this,tr("警告"),tr("错误:%1").arg(reply->errorString()));
        return;
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

void QVision::ShowCoordinateSystem()
{
    CoordinateSystem::ins().show();
}

void QVision::ChangeSoftWareIcon()
{
    QString userDeskTop="C:/Users/"+QSysInfo::machineHostName()+"/Desktop";
    iconSrc=QFileDialog::getOpenFileName(this,"选择图标",userDeskTop,"All Files *(*.*)");
    QString icon = QCoreApplication::applicationDirPath() + "/config/icon.txt";
    QFile file(icon);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << iconSrc;
        file.close();
        QMessageBox::information(this, "提示", "重启软件以应用新图标!");
    } else {
        QMessageBox::warning(this, "警告", "配置错误!");
    }
    QProcess::startDetached(qApp->applicationFilePath());
    qApp->exit();
}
