#include "BallardDlg.h"
BallardDlg::BallardDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    minDistBox=new QSpinBox(this);
    levelBox=new QSpinBox(this);
    dpBox=new QSpinBox(this);
    buffersizeBox=new QSpinBox(this);
    voteBox=new QSpinBox(this);
    cannylowBox=new QSpinBox(this);
    cannyhighBox=new QSpinBox(this);
    okBtn=new QPushButton("Ok",this);
    cancelBtn=new QPushButton("Cancel",this);

    tip1=new QLabel("最小距离");
    tip2=new QLabel("搜索层数");

    tip3=new QLabel("分辨率倒数");
    tip4=new QLabel("缓冲区大小");

    tip5=new QLabel("投票阈值");
    tip6=new QLabel("低阈值");
    tip7=new QLabel("高阈值");

    minDistBox->setValue(90);
    minDistBox->setRange(0,10000);
    minDistBox->setSingleStep(10);

    levelBox->setValue(80);
    levelBox->setRange(0,10000);
    levelBox->setSingleStep(100);

    dpBox->setValue(1);
    dpBox->setRange(0,5);
    dpBox->setSingleStep(1);

    buffersizeBox->setValue(50);
    buffersizeBox->setRange(0,10000);
    buffersizeBox->setSingleStep(100);

    voteBox->setValue(40);
    voteBox->setRange(0,360);
    voteBox->setSingleStep(10);

    cannylowBox->setValue(80);
    cannylowBox->setRange(0,255);
    cannylowBox->setSingleStep(10);

    cannyhighBox->setValue(90);
    cannyhighBox->setRange(0,255);
    cannyhighBox->setSingleStep(10);
    cannyhighBox->setFixedWidth(200);

    QVBoxLayout *Mainstruct=new QVBoxLayout();
    QHBoxLayout *subRow1=new QHBoxLayout();
    QHBoxLayout *subRow2=new QHBoxLayout();
    QHBoxLayout *subRow3=new QHBoxLayout();
    QHBoxLayout *subRow4=new QHBoxLayout();
    QHBoxLayout *btnRow=new QHBoxLayout();

    subRow1->addWidget(tip1);subRow1->addWidget(minDistBox);subRow1->addWidget(tip2);subRow1->addWidget(levelBox);
    subRow2->addWidget(tip3);subRow2->addWidget(dpBox);subRow2->addWidget(tip4);subRow2->addWidget(buffersizeBox);

    subRow3->addWidget(tip5);subRow3->addWidget(voteBox);
    subRow3->addWidget(tip6);subRow3->addWidget(cannylowBox);
    subRow4->addWidget(tip7);subRow4->addWidget(cannyhighBox);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);

    Mainstruct->addLayout(subRow1);
    Mainstruct->addLayout(subRow2);
    Mainstruct->addLayout(subRow3);
    Mainstruct->addLayout(subRow4);
    Mainstruct->addLayout(btnRow);
    setLayout(Mainstruct);

    connect(okBtn, &QPushButton::clicked, this, &BallardDlg::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked, this, &BallardDlg::onCancelClicked);

    resize(200,100);
    setWindowTitle("Ballard Parameters");
}
int BallardDlg::getValue(int para)
{
    if(para==1){
        return mindist;
    }else if(para==2){
        return level;
    }else if(para==3){
        return dp;
    }else if(para==4){
        return buffersize;
    }else if(para==5){
        return vote;
    }else if(para==6){
        return cannylow;
    }else if(para==7){
        return cannyhigh;
    }else{
        return -1;
    }
}
void BallardDlg::setValue(int a,int b,double c,int d,int e,int f,int g)
{
    mindist=a;
    level=b;
    dp=c;
    buffersize=d;
    vote=e;
    cannylow=f;
    cannyhigh=g;
}
void BallardDlg::onOkClicked()
{
    mindist=minDistBox->value();
    level=levelBox->value();
    dp=dpBox->value();
    buffersize=buffersizeBox->value();
    vote=voteBox->value();
    cannylow=cannylowBox->value();
    cannyhigh=cannyhighBox->value();
    accept();
}

void BallardDlg::onCancelClicked()
{
    reject();
}
