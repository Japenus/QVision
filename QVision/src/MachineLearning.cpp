#include "MachineLearning.h"
#include <QStyleFactory>
MachineLearning::MachineLearning(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    QRect win=QGuiApplication::screens().at(0)->geometry();
    QMenuBar *menu = new QMenuBar();
    QAction *resetBg = new QAction("Reset Background");
    QMenu *list = menu->addMenu("Option");
    list->addSeparator();
    list->addAction(resetBg);
    setMenuBar(menu);

    vi=new QVideoWidget;
    lbtn=new QPushButton("left");
    paras=new QGroupBox("参数列表");
    saveScreen=new QPushButton("Save");
    stopCapture=new QPushButton("Stop");
    closeCurWin=new QPushButton("Close");
    startCapture=new QPushButton("Start");

    left=new QWidget;
    right=new QWidget;
    center=new QWidget;

    m_camera = new QCamera(QMediaDevices::defaultVideoInput());
    m_mediaCaptureSession = new QMediaCaptureSession(this);
    m_imageCapture = new QImageCapture();

    left->setMaximumSize(win.width()/3,win.height());
    left->setMinimumSize(win.width()/5,win.height()/2);

    right->setMaximumSize(win.width()-win.width()/3,win.height());
    right->setMinimumSize((win.width()/5)*2,win.height()/2);

    left->setStyleSheet("background-color: rgba(128, 128, 128, 50);"
                        " border: 2px solid cyan;border-radius: 10px;");
    right->setStyleSheet("background-color: rgba(128, 128, 128, 50);"
                         "border-radius: 10px;border: 2px solid cyan;");
    center->setStyleSheet("border-radius: 10px;border: 2px solid gray;");

    main=new QHBoxLayout;
    pLeft=new QVBoxLayout;
    pRight=new QVBoxLayout;

    QHBoxLayout *rightBtnList=new QHBoxLayout;

    rightBtnList->addWidget(startCapture);
    rightBtnList->addWidget(stopCapture);
    rightBtnList->addWidget(saveScreen);
    rightBtnList->addWidget(closeCurWin);

    // paras->setLayout(rightBtnList);
    pLeft->addWidget(paras);
    pRight->addWidget(vi);
    pRight->addLayout(rightBtnList);


    left->setLayout(pLeft);
    right->setLayout(pRight);

    main->addWidget(left);
    main->addWidget(right);
    center->setLayout(main);
    setCentralWidget(center);


    connect(resetBg,&QAction::triggered,this,&MachineLearning::modifyBackground);
    connect(closeCurWin, &QPushButton::clicked, this, &MachineLearning::closeWin);
    connect(saveScreen, &QPushButton::clicked, this, &MachineLearning::onSavingImage);
    connect(stopCapture, &QPushButton::clicked, this, &MachineLearning::onStopStreaming);
    connect(startCapture, &QPushButton::clicked, this, &MachineLearning::onStartStreaming);

    resize(800,600);
    setWindowTitle("Machine Learning");
}

MachineLearning::~MachineLearning()
{

}

void MachineLearning::onStartStreaming()
{
    m_camera->start();
    m_mediaCaptureSession->setCamera(m_camera);
    m_mediaCaptureSession->setVideoOutput(vi);
}

void MachineLearning::onStopStreaming()
{
    m_camera->stop();
}

void MachineLearning::onSavingImage()
{
    m_mediaCaptureSession->setImageCapture(m_imageCapture);
    m_imageSavingPath=QFileDialog::getExistingDirectory(this,"选择文件夹","");
    m_imageCapture->captureToFile(m_imageSavingPath);
}

void MachineLearning::modifyBackground()
{
    srcBg=QFileDialog::getOpenFileName(this,"选择背景","","All files *(*.*)");
    if(srcBg.isNull()) return;
    bgImg=QImage(srcBg);
}

void MachineLearning::closeWin()
{
    this->close();
}

void MachineLearning::paintEvent(QPaintEvent *event)
{
    QPainter draw(this);
    // draw.setViewport(100,100,400,600);//绘制的位置
    // draw.setWindow(0,0,800,600);//从原始图像中截取一块区域
    if (!bgImg.isNull()) {
        draw.drawImage(0, 0, bgImg.scaled(width(), height(), Qt::KeepAspectRatioByExpanding));
    }else{
        draw.setBrush(QBrush(Qt::green));
        drawStar(&draw, width() / 2, height() / 2, 20, 10, 5);
    }
}

void MachineLearning::drawStar(QPainter *painter, int x, int y, int outerRadius, int innerRadius, int points)
{
    QVector<QPointF> starPoints;
    for (int i = 0; i < points * 2; ++i) {
        double angle = i * M_PI / points;
        double radius = (i % 2 == 0) ? outerRadius : innerRadius;
        starPoints.append(QPointF(x + radius * cos(angle), y - radius * sin(angle)));
    }
    painter->drawPolygon(QPolygonF(starPoints));
}
