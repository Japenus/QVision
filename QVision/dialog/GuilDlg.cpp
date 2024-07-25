#include "GuilDlg.h"
GuilDlg::GuilDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    minDistBox=new QSpinBox(this);
    levelBox=new QSpinBox(this);
    dpBox=new QSpinBox(this);
    xiBox=new QSpinBox(this);

    buffersizeBox=new QSpinBox(this);
    cannylowBox=new QSpinBox(this);
    cannyhighBox=new QSpinBox(this);
    minangleBox=new QSpinBox(this);

    maxangleBox=new QSpinBox(this);
    anglestepBox=new QDoubleSpinBox(this);
    anglethresholdBox=new QSpinBox(this);
    minscaleBox=new QDoubleSpinBox(this);

    maxscaleBox=new QDoubleSpinBox(this);
    anglepliseBox=new QSpinBox(this);
    scalestepBox=new QDoubleSpinBox(this);
    scalethresholdBox=new QSpinBox(this);
    posthresholdBox=new QSpinBox(this);

    okBtn=new QPushButton("Ok",this);
    cancelBtn=new QPushButton("Cancel",this);

    minDistBox->setValue(100);
    minDistBox->setRange(0,10000);
    minDistBox->setSingleStep(10);
    levelBox->setValue(360);
    levelBox->setRange(0,10000);
    levelBox->setSingleStep(10);
    dpBox->setValue(1);
    dpBox->setRange(0,10);
    dpBox->setSingleStep(1);
    xiBox->setValue(90);
    xiBox->setRange(0,1000);
    xiBox->setSingleStep(1);

    buffersizeBox->setValue(1000);
    buffersizeBox->setRange(0,10000);
    buffersizeBox->setSingleStep(100);
    cannylowBox->setValue(50);
    cannylowBox->setRange(0,255);
    cannylowBox->setSingleStep(10);
    cannyhighBox->setValue(100);
    cannyhighBox->setRange(0,255);
    cannyhighBox->setSingleStep(10);
    minangleBox->setValue(80);
    minangleBox->setRange(0,10000);
    minangleBox->setSingleStep(20);

    maxangleBox->setValue(100);
    maxangleBox->setRange(0,360);
    maxangleBox->setSingleStep(1);
    anglestepBox->setValue(1);
    anglestepBox->setRange(0,100);
    anglestepBox->setSingleStep(10);
    anglethresholdBox->setValue(15000);
    anglethresholdBox->setRange(0,20000);
    anglethresholdBox->setSingleStep(1000);
    minscaleBox->setValue(0.5);
    minscaleBox->setRange(-2,2);
    minscaleBox->setSingleStep(0.5);

    maxscaleBox->setValue(2.0);
    maxscaleBox->setRange(-2,2);
    maxscaleBox->setSingleStep(0.5);
    anglepliseBox->setValue(80);
    anglepliseBox->setRange(0,10000);
    anglepliseBox->setSingleStep(20);
    scalestepBox->setValue(0.05);
    scalestepBox->setRange(-1,1);
    scalestepBox->setSingleStep(0.01);
    scalethresholdBox->setValue(1000);
    scalethresholdBox->setRange(0,10000);
    scalethresholdBox->setSingleStep(100);
    posthresholdBox->setValue(100);
    posthresholdBox->setRange(0,10000);
    posthresholdBox->setSingleStep(10);

    tip1=new QLabel("最小距离");
    tip2=new QLabel("搜索层数");
    tip3=new QLabel("分辨率倒数");
    tip4=new QLabel("xi值");

    tip5=new QLabel("缓冲区大小");
    tip6=new QLabel("低阈值");
    tip7=new QLabel("高阈值");
    tip8=new QLabel("最小角度");

    tip9=new QLabel("最大角度");
    tip10=new QLabel("角度步长");
    tip11=new QLabel("角度阈值");
    tip12=new QLabel("最小缩放比");

    tip13=new QLabel("最大缩放比");
    tip14=new QLabel("角度精度");
    tip15=new QLabel("缩放步长");
    tip16=new QLabel("缩放阈值");
    tip17=new QLabel("位置阈值");

    QVBoxLayout *MainStruct=new QVBoxLayout();
    QHBoxLayout *subRow1=new QHBoxLayout();
    QHBoxLayout *subRow2=new QHBoxLayout();
    QHBoxLayout *subRow3=new QHBoxLayout();
    QHBoxLayout *subRow4=new QHBoxLayout();
    QHBoxLayout *subRow5=new QHBoxLayout();
    QHBoxLayout *subRow6=new QHBoxLayout();
    QHBoxLayout *btnRow=new QHBoxLayout();

    subRow1->addWidget(tip1);subRow1->addWidget(minDistBox);subRow1->addWidget(tip2);subRow1->addWidget(levelBox);subRow1->addWidget(tip3);subRow1->addWidget(dpBox);
    subRow2->addWidget(tip4);subRow2->addWidget(xiBox);subRow2->addWidget(tip5);subRow2->addWidget(buffersizeBox);subRow2->addWidget(tip6);subRow2->addWidget(cannylowBox);
    subRow3->addWidget(tip7);subRow3->addWidget(cannyhighBox);subRow3->addWidget(tip8);subRow3->addWidget(minangleBox);subRow3->addWidget(tip9);subRow3->addWidget(maxangleBox);
    subRow4->addWidget(tip10);subRow4->addWidget(anglestepBox);subRow4->addWidget(tip11);subRow4->addWidget(anglethresholdBox);subRow4->addWidget(tip12);subRow4->addWidget(minscaleBox);
    subRow5->addWidget(tip13);subRow5->addWidget(maxscaleBox);subRow5->addWidget(tip14);subRow5->addWidget(anglepliseBox);subRow5->addWidget(tip15);subRow5->addWidget(scalestepBox);
    subRow6->addWidget(tip16);subRow6->addWidget(scalethresholdBox);subRow6->addWidget(tip17);subRow6->addWidget(posthresholdBox);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);

    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(subRow3);
    MainStruct->addLayout(subRow4);
    MainStruct->addLayout(subRow5);
    MainStruct->addLayout(subRow6);
    MainStruct->addLayout(btnRow);

    setLayout(MainStruct);

    connect(okBtn, &QPushButton::clicked, this, &GuilDlg::onOkClicked);
    connect(cancelBtn,&QPushButton::clicked, this, &GuilDlg::onCancelClicked);

    resize(300,200);
    setWindowTitle("Guil Parameters");
}

void GuilDlg::setValue(int Mindist,int Level,double Dp,double Xi,int Buffersize,int Cannylow,int Cannyhigh,int Minangle,int Maxangle,
int Anglestep,int Anglethreshold,float Minscale,float Maxscale,float Angleplise,double Scalestep,int Scalethreshold,int Posthreshold)
{
    mindist=Mindist;
    level=Level;
    dp=Dp;
    xi=Xi;

    buffersize=Buffersize;
    cannylow=Cannylow;
    cannyhigh=Cannyhigh;
    minangle=Minangle;

    maxangle=Maxangle;
    anglestep=Anglestep;
    anglethreshold=Anglethreshold;
    minscale=Minscale;

    maxscale=Maxscale;
    angleplise=Angleplise;
    scalestep=Scalestep;
    scalethreshold=Scalethreshold;
    posthreshold=Posthreshold;
}
double GuilDlg::getDValue(int which)
{
    if(which==DP){
        return dp;
    }else if(which==XI){
        return xi;
    }else if(which==SCALESTEP){
        return scalestep;
    }else{
        return 0.0;
    }
}

float GuilDlg::getFValue(int which)
{

    if(which==MINSCALE){
        return minscale;
    }else if(which==MAXSCALE){
        return maxscale;
    }else if(which==ANGLEEPSILON){
        return angleplise;
    }else{
        return 0.0;
    }
}

int GuilDlg::getValue(int para)
{
    if(para==MINDIST){
        return mindist;
    }else if(para==LEVEL){
        return level;
    }else if(para==BUFFERSIZE){
        return buffersize;
    }else if(para==CANNYLOWTHRESHOLD){
        return cannylow;
    }else if(para==CANNYHIGHTHRESHOLD){
        return cannyhigh;
    }else if(para==MINANGLE){
        return minangle;
    }else if(para==MAXANGLE){
        return maxangle;
    }else if(para==ANGLESTEP){
        return anglestep;
    }else if(para==ANGLETHRESHOLD){
        return anglethreshold;
    }else if(para==SCALETHRESHOLD){
        return scalethreshold;
    }else if(para==POSITIONTHRESHOLD){
        return posthreshold;
    }else{
        return -1;
    }
}

void GuilDlg::onOkClicked()
{
    mindist=minDistBox->value();
    level=levelBox->value();
    dp=dpBox->value();
    xi=xiBox->value();

    buffersize=buffersizeBox->value();
    cannylow=cannylowBox->value();
    cannyhigh=cannyhighBox->value();
    minangle=minangleBox->value();

    maxangle=maxangleBox->value();
    anglestep=anglestepBox->value();
    anglethreshold=anglethresholdBox->value();
    minscale=minscaleBox->value();

    maxscale=maxscaleBox->value();
    angleplise=anglepliseBox->value();
    scalestep=scalestepBox->value();
    scalethreshold=scalethresholdBox->value();
    posthreshold=posthresholdBox->value();

    accept();
}

void GuilDlg::onCancelClicked()
{
    reject();
}
