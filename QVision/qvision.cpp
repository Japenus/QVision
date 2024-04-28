#include "qvision.h"
#include "ui_qvision.h"

QVision::QVision(QWidget *parent): QMainWindow(parent), ui(new Ui::QVision)
{
    QIcon icon("Spyder.png");
    ui->setupUi(this);
    QRect DeviceSize=QGuiApplication::screens().at(0)->geometry();
    int w=DeviceSize.width();
    int h=DeviceSize.height();
    srcBox=new QLabel();
    resBox=new QLabel();
    // srcBox->setAcceptDrops(true);
    tip1=new QLabel("Before");
    tip2=new QLabel("After");

    histSrc= new QPushButton("Hist");
    histRes= new QPushButton("Hist");
    bigSrc = new QPushButton("Make Big");
    bigRes = new QPushButton("Make Big");

    tip1->setFixedHeight(3*fixPara);
    tip2->setFixedHeight(3*fixPara);
    tip1->setAlignment(Qt::AlignCenter);
    tip2->setAlignment(Qt::AlignCenter);
    tip1->setStyleSheet("border: 1px solid brown;padding: 5px;color: green; /*background-color: orange;*/border-radius: 10px;font-weight: bold; font-style: italic;");
    tip2->setStyleSheet("border: 1px solid brown;padding: 5px;color: green; /*background-color: orange;*/border-radius: 10px;font-weight: bold; font-style: italic;");

    srcBox->setStyleSheet("border: 1px solid brown; padding: 5px;border-radius: 10px;font-weight: bold;");
    resBox->setStyleSheet("border: 1px solid brown; padding: 5px;border-radius: 10px;font-weight: bold;");

    bigRes->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    bigSrc->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");

    histRes->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    histSrc->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;;border-radius: 10px;font-weight: bold;");

    srcBox->setMaximumSize(w,h);srcBox->setMinimumSize(w/4,h/3);
    resBox->setMaximumSize(w,h);resBox->setMinimumSize(w/4,h/3);
    srcBox->setScaledContents(true);resBox->setScaledContents(true);
    srcBox->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    resBox->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    QVBoxLayout *MainStruct =new  QVBoxLayout;
    QHBoxLayout *Row1 = new QHBoxLayout;
    QHBoxLayout *Row2 = new QHBoxLayout;
    QHBoxLayout *Row3 = new QHBoxLayout;
    QHBoxLayout *Row4 = new QHBoxLayout;
    QWidget *central=new QWidget;

    Row1->addWidget(tip1);Row1->addWidget(tip2);
    Row2->addWidget(srcBox);Row2->addWidget(resBox);
    Row3->addWidget(histSrc);Row3->addWidget(histRes);
    Row4->addWidget(bigSrc);Row4->addWidget(bigRes);

    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(Row3);
    MainStruct->addLayout(Row4);
    MainStruct->setStretch(0,10);
    MainStruct->setSpacing(fixPara);
    MainStruct->setContentsMargins(fixPara, fixPara, fixPara, fixPara);

    central->setLayout(MainStruct);
    setCentralWidget(central);

    connect(histSrc,&QPushButton::clicked,this,&QVision::on_srcHist_clicked);
    connect(histRes,&QPushButton::clicked,this,&QVision::on_resHist_clicked);
    connect(bigSrc,&QPushButton::clicked,this,&QVision::on_bigSrc_clicked);
    connect(bigRes,&QPushButton::clicked,this,&QVision::on_bigRes_clicked);

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
    delete ui;
}


//basic
void QVision::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "png", tr("Type (*.png *.jpg *.bmp)"));
    Src=imread(fileName.toStdString());
    if (!fileName.isEmpty()) {
        QImage image(fileName);
        srcBox->setPixmap(QPixmap::fromImage(image));
    }
}


void QVision::on_actionSave_triggered()
{
    QImage image = resBox->pixmap().toImage();
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"), "result1.png", tr("Images (*.png *.jpg *.bmp)"));
    if (!filePath.isEmpty()) image.save(filePath);
}

void QVision::on_actionExit_triggered()
{
    QApplication::quit();
}

bool QVision::IsImgOpen()
{
    if(Src.empty())
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
    Mat tmp=imread("output.png");
    if(!tmp.empty()){
        img = QImage(tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_BGR888);
        QPixmap showcut = QPixmap::fromImage(img);
        resBox->setPixmap(showcut);
        resBox->setScaledContents(true);
        resBox->show();
    }

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
        qDebug() << "Failed to convert";
        return Mat();
    }
    Mat res(image.height(), image.width(), CV_8UC4, image.bits(), image.bytesPerLine());
    cvtColor(res, res, COLOR_BGRA2BGR);
    return res;
}

void QVision::on_srcHist_clicked()
{
    if(!srcBox->pixmap()) return;
    Dst=tools.ShowHistogram(Src);
}


void QVision::on_resHist_clicked()
{
    if(!resBox->pixmap()) return;
    QPixmap pixmap = resBox->pixmap();
    Dst = QPixmap2Mat(pixmap);
    tools.ShowHistogram(Dst);
}


void QVision::on_bigSrc_clicked()
{
    if(!srcBox->pixmap()) return;
    tools.MakeBig(Src);
    Show();
}


void QVision::on_bigRes_clicked()
{
    if(!resBox->pixmap()) return;
    tools.MakeBig(Dst);
    Show();
}

//预处理
void QVision::on_actionGray_Transform_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.GrayTransform(Src);
    Show(Dst);
}


void QVision::on_actionLog_Transform_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.LogTransform(Src,10);
    Show(Dst);
}


void QVision::on_actionLinear_Transform_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.LinearTransform(Src);
    Show(Dst);
}


void QVision::on_actionGamma_Transform_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.GammaTransform(Src,1.2);
    Show(Dst);
}


void QVision::on_actionBox_Filter_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.BoxFilter(Src);
    Show(Dst);
}


void QVision::on_actionMean_Filter_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.MeanFilter(Src);
    Show(Dst);
}


void QVision::on_actionMedium_Filter_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.MediumFilter(Src);
    Show(Dst);
}


void QVision::on_actionBilateral_Filter_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.BilateralFilter(Src);
    Show(Dst);
}

void QVision::on_actionGauss_Filter_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.GaussFilter(Src);
    Show(Dst);
}


void QVision::on_actionDilation_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.Dilation(Src);
    Show(Dst);
}


void QVision::on_actionErosion_triggered()
{
    if(!IsImgOpen()) return;
    Dst=pretreat.Erosion(Src);
    Show(Dst);
}

//工具
void QVision::on_actionSobel_triggered()
{
    if(!IsImgOpen()) return;
    Dst=tools.EdgeSobel(Src);
    Show();
}


void QVision::on_actionCanny_triggered()
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


void QVision::on_actionScharr_triggered()
{
    if(!IsImgOpen()) return;
    Dst=tools.Edgescharr(Src);
    Show();
}


void QVision::on_actionRegion_Grow_triggered()
{
    if(!IsImgOpen()) return;
    int threshold = 10;
    Point seedPoint(10, 10);
    Mat visited = Mat::zeros(Src.size(), CV_8U);
    Dst = tools.RegionGrow(Src, seedPoint, threshold, visited);
    Show(Dst);
}


void QVision::on_actionFix_Threshold_triggered()
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


void QVision::on_actionShow_Outline_triggered()
{
    if(!IsImgOpen()) return;
    int val=80;
    Dst=tools.ShowOutline(Src,val);
    Show();
}


void QVision::on_actionThreshold_Process_triggered()
{
    if(!IsImgOpen()) return;
    if(TD.exec()== QDialog::Accepted){
        int type=TD.getValue(1);
        int val=TD.getValue(2);
        TD.setValue(val,type);
        TD.thresval=type;
        TD.threstype =val;
        Dst=tools.ThresholdProcess(Src,val,type);
        imwrite("output.png",Dst);
        Show();
    }
}


void QVision::on_actionAdapt_Threshold_triggered()
{
    if(!IsImgOpen()) return;
    int size=15;
    double c=2.0;
    Dst=tools.AdaptThreshold(Src,size,c);
    Show();
}


void QVision::on_actionArea_Cover_triggered()
{
    if(!IsImgOpen()) return;
    Dst=tools.AreaCover(Src);
    Show();
}


void QVision::on_actionArea_Fill_triggered()
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


void QVision::on_actionStatistic_Pixels_triggered()
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


void QVision::on_actionPerspective_Transform_triggered()
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


void QVision::on_actionCalculate_Distance_triggered()
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


void QVision::on_actionRotate_Scale_triggered()
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


void QVision::on_actionImage_Pyramid_triggered()
{
    if(!IsImgOpen()) return;
    tools.Pyramid(Src);
}


void QVision::on_actionPick_Color_triggered()
{
    tools.PickColor();
}

void QVision::on_actionScreen_Cut_triggered()
{
    SC.show();
    Show();
}

void QVision::on_actionWakeUp_QQ_triggered()
{
    QProcess process;
    QString where = "D:/QQ/QQ.exe";
    process.start(where);
    if(process.waitForFinished(-1)){
        qDebug()<< "finished";
    }
}

void QVision::on_actionEraser_triggered()
{

}

//图像运算
void QVision::on_actionDivide_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IC.Divide(Src);
    Show();
}


void QVision::on_actionOpen_2_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IC.OnCalc(Src);
    Show();
}


void QVision::on_actionClose_2_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IC.OffCalc(Src);
    Show();
}


void QVision::on_actionMultipy_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IC.Multipy(Src);
    Show();
}


void QVision::on_actionLinear_Stretch_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IC.LineStretch(Src);
    Show();
}


void QVision::on_actionAdd_triggered()
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


void QVision::on_actionSubtraction_triggered()
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


void QVision::on_actionFourier_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IC.FourierTransform(Src);
    Show();
}


void QVision::on_actionLaplacian_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IC.LaplacianTransform(Src);
    Show();
}

//图像算法
void QVision::on_actionSURF_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.SURF(Src);
    Show();
}


void QVision::on_actionFlood_Fill_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.FloodFill(Src);
    Show();
}


void QVision::on_actionImage_Equal_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.HistEqual(Src);
    Show();
}


void QVision::on_actionTemplate_Match_triggered()
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


void QVision::on_actionFeature_Point_MAtch_triggered()
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


void QVision::on_actionUpgrade_TempMatch_triggered()
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


void QVision::on_actionLine_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughLine(Src);
    Show();
}


void QVision::on_actionCircle_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughCircle(Src);
    Show();
}


void QVision::on_actionEllipse_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughEllipse(Src);
    Show();
}


void QVision::on_actionTriangle_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughTriangle(Src);
    Show();
}

void QVision::on_actionRectangle_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.HoughRectangle(Src);
    Show();
}

void QVision::on_actionBallard_triggered()
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


void QVision::on_actionGuil_triggered()
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

void QVision::on_actionShi_Tomasi_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.ShiTomasiDetect(Src);
    Show();
}


void QVision::on_actionHarris_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.HarrisDetect(Src);
    Show();
}


void QVision::on_actionFast_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.FASTDetect(Src);
    Show();
}


void QVision::on_actionBrisk_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.BRISKDetect(Src);
    Show();
}


void QVision::on_actionMser_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.MSERDetect(Src);
    Show();
}


void QVision::on_actionGFTT_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.GFTTDetect(Src);
    Show();
}


//模型、检测
void QVision::on_actionSelf_Define_Model_triggered()
{
    if(!IsImgOpen()) return;
    QString modelPath=getModel();
    Dst=IA.SelfModel(Src,modelPath);
    Show();
}

void QVision::on_actionRecongnize_Face_triggered()
{
    if(!IsImgOpen()) return;
    Dst=IA.DetectFaceFromImg(Src);
    Show();
}

void QVision::on_actionTesseract_OCR_triggered()
{
    CRD.exec();
}

void QVision::on_actionCapture_Line_triggered()
{
    DD.DetectLine();
}


void QVision::on_actionCapture_Circle_triggered()
{
    DD.DetectCircle();
}


void QVision::on_actionCapture_Triangle_triggered()
{
    DD.DetectTriangle();
}

void QVision::on_actionCapture_Square_triggered()
{
    DD.DetectSquare();
}

void QVision::on_actionCapture_Ellpise_triggered()
{
    DD.DetectEllpise();
}

void QVision::on_actionCapture_Character_triggered()
{
    DD.DetectCharacter();
}

void QVision::on_actionCapture_HumanEyes_triggered()
{
    DD.DetectEye();
}

void QVision::on_actionCapture_HumanFace_triggered()
{
    DD.DetectFace();
}

//文件操作
void QVision::on_actionRename_File_triggered()
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


void QVision::on_actionWriteToData_triggered()
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


void QVision::on_actionOutputImg_Data_triggered()
{
    QString dir=getFolder();
    QString savepath=getOutputpath();
    FO.GetImgData(dir,savepath);
}


void QVision::on_actionResizeImgSize_triggered()
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


void QVision::on_actionOutputFile_Info_triggered()
{
    QString dir=getFolder();
    QString savepath=getOutputpath();
    if(!dir.isNull()&&!savepath.isNull()) FO.ExportFiles(dir,savepath);
}


//网络
void QVision::on_actionSpyder_triggered()
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

void QVision::on_actionTCP_IP_triggered()
{
    NC.show();
}

//多媒体
void QVision::on_actionVideo_Player_triggered()
{
    MM.resize(640,480);
    MM.show();
}


//数据库
void QVision::on_actionLaunch_2_triggered()
{
    DB.show();
}


//关于
void QVision::on_actionFollow_triggered()
{
    QUrl url("https://github.com/Japenus");
    QDesktopServices::openUrl(url);
}

void QVision::on_actionCSDN_triggered()
{
    QUrl url("https://blog.csdn.net/qq_51610936?type=blog");
    QDesktopServices::openUrl(url);
}

void QVision::on_actionJueJin_triggered()
{
    QUrl url("https://juejin.cn/user/2080717187580488");
    QDesktopServices::openUrl(url);
}
