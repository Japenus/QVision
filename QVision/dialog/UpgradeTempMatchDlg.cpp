#include "UpgradeTempMatchDlg.h"

UpgradeTempMatchDlg::UpgradeTempMatchDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    tip1=new QLabel("图像阈值:");
    tip2=new QLabel("缩放步长:");
    tip3=new QLabel("最小缩放比例:");
    tip4=new QLabel("最大缩放比例:");
    tip5=new QLabel("预处理阈值:");
    tip6=new QLabel("重叠度阈值:");

    ImgThresBox=new QSpinBox(this);
    ScalestepBox=new QDoubleSpinBox(this);
    MaxScaleRatioBox=new QDoubleSpinBox(this);
    MinScaleRatioBox=new QDoubleSpinBox(this);
    PreProcessThresBox=new QDoubleSpinBox(this);
    OverlapThresBox=new QDoubleSpinBox(this);

    okBtn=new QPushButton("Ok",this);
    cancelBtn=new QPushButton("cancel",this);

    ImgThresBox->setValue(90);
    ImgThresBox->setRange(0,255);
    ImgThresBox->setSingleStep(10);

    ScalestepBox->setValue(0.5);
    ScalestepBox->setRange(0,1);
    ScalestepBox->setSingleStep(0.01);

    MinScaleRatioBox->setValue(1);
    MinScaleRatioBox->setRange(-2,2);
    MinScaleRatioBox->setSingleStep(0.5);

    MaxScaleRatioBox->setValue(1);
    MaxScaleRatioBox->setRange(-2,2);
    MaxScaleRatioBox->setSingleStep(0.5);

    PreProcessThresBox->setValue(0.2);
    PreProcessThresBox->setRange(0,1);
    PreProcessThresBox->setSingleStep(0.01);

    OverlapThresBox->setValue(0.995);
    OverlapThresBox->setRange(0,2);
    OverlapThresBox->setSingleStep(0.001);
    OverlapThresBox->setDecimals(3);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *subRow1= new QHBoxLayout(this);
    QHBoxLayout *subRow2=new QHBoxLayout(this);
    QHBoxLayout *subRow3=new QHBoxLayout(this);
    QHBoxLayout *btnRow = new QHBoxLayout(this);

    subRow1->addWidget(tip1);
    subRow1->addWidget(ImgThresBox);
    subRow1->addWidget(tip2);
    subRow1->addWidget(ScalestepBox);

    subRow2->addWidget(tip3);
    subRow2->addWidget(MinScaleRatioBox);
    subRow2->addWidget(tip4);
    subRow2->addWidget(MaxScaleRatioBox);

    subRow3->addWidget(tip5);
    subRow3->addWidget(PreProcessThresBox);
    subRow3->addWidget(tip6);
    subRow3->addWidget(OverlapThresBox);

    btnRow->addWidget(okBtn);
    btnRow->addWidget(cancelBtn);

    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(subRow3);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);
    connect(okBtn, &QPushButton::clicked, this, &UpgradeTempMatchDlg::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked, this, &UpgradeTempMatchDlg::onCancelClicked);
    resize(200,100);
    setWindowTitle("Upgrade Template Match");

}
void UpgradeTempMatchDlg::setValue(int a,double b,double c,double d,double e,double f)
{
    ImgThres=a;
    ScaleStep=b;
    OverlapThres=c;
    MinScaleRatio=d;
    MaxScaleRatio=e;
    PreProcessThres=f;
}
int UpgradeTempMatchDlg::getValue()
{
    return ImgThres;
}
double UpgradeTempMatchDlg::getValue(int para)
{
    if(para==1){
        return ScaleStep;
    }else if(para==2){
        return OverlapThres;
    }else if(para==3){
        return MinScaleRatio;
    }else if(para==4){
        return MaxScaleRatio;
    }else if(para==5){
        return PreProcessThres;
    }else{
        return 0;
    }
}

void UpgradeTempMatchDlg::onOkClicked()
{
    ImgThres = ImgThresBox->value();
    ScaleStep=ScalestepBox->value();
    OverlapThres = OverlapThresBox->value();
    MinScaleRatio= MinScaleRatioBox->value();
    MaxScaleRatio= MaxScaleRatioBox->value();
    PreProcessThres=PreProcessThresBox->value();
    accept();
}
void UpgradeTempMatchDlg::onCancelClicked()
{
    reject();
}
