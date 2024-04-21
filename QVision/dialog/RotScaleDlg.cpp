#include "RotScaleDlg.h"

RotScaleDlg::RotScaleDlg(QWidget *parent):QDialog(parent)
{
    rotateBox=new QSpinBox(this);
    scaleBox=new QSpinBox(this);
    okBtn=new QPushButton("ok",this);
    cancelBtn=new QPushButton("cancel",this);

    tip1=new QLabel("旋转角度");
    tip2=new QLabel("缩放比例");

    rotateBox->setValue(90);
    rotateBox->setRange(0,360);
    rotateBox->setSingleStep(5);

    scaleBox->setValue(1);
    scaleBox->setRange(-5,5);
    scaleBox->setSingleStep(1);

    QVBoxLayout *Mainstruct = new QVBoxLayout(this);
    QHBoxLayout *subRow1=new QHBoxLayout(this);
    QHBoxLayout *subRow2 = new QHBoxLayout(this);
    QHBoxLayout *btnRow= new QHBoxLayout(this);

    subRow1->addWidget(tip1);subRow1->addWidget(rotateBox);
    subRow2->addWidget(tip2);subRow2->addWidget(scaleBox);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);

    Mainstruct->addLayout(subRow1);
    Mainstruct->addLayout(subRow2);
    Mainstruct->addLayout(btnRow);
    setLayout(Mainstruct);
    connect(okBtn, &QPushButton::clicked, this, &RotScaleDlg::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked,this,&RotScaleDlg::onCancelClicked);
    resize(100,50);
    setWindowTitle("Rotate And scale");

}
int RotScaleDlg::getValue(int para)
{
    if(para==1){
        return rotate;
    }else if(para==2){
        return scale;
    }else{
        return -1;
    }
}
void RotScaleDlg::setValue(int a,int b)
{
   rotate=a;
   scale=b;
}
void RotScaleDlg::onOkClicked()
{
    rotate=rotateBox->value();
    scale=scaleBox->value();
    accept();
}

void RotScaleDlg::onCancelClicked()
{
    reject();
}
