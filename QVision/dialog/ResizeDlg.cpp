#include "ResizeDlg.h"

ResizeDlg::ResizeDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    tip1=new QLabel("指定宽度:");
    tip2=new QLabel("指定高度:");
    widthBox=new QSpinBox(this);
    heightBox=new QSpinBox(this);
    okBtn=new QPushButton("ok",this);
    cancelBtn=new QPushButton("cancel",this);
    okBtn->setFixedSize(100,20);
    cancelBtn->setFixedSize(100,20);

    widthBox->setValue(100);
    widthBox->setRange(0,1000);
    widthBox->setSingleStep(50);
    widthBox->setFixedWidth(100);

    heightBox->setValue(100);
    heightBox->setRange(0,1000);
    heightBox->setSingleStep(50);
    heightBox->setFixedWidth(100);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *subRow1=new QHBoxLayout(this);
    QHBoxLayout *subRow2 = new QHBoxLayout(this);
    QHBoxLayout *btnRow=new QHBoxLayout(this);

    subRow1->addWidget(tip1);subRow1->addWidget(widthBox);
    subRow2->addWidget(tip2);subRow2->addWidget(heightBox);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);
    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);
    connect(okBtn, &QPushButton::clicked,this, &ResizeDlg::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked,this, &ResizeDlg::onCancelClicked);
    resize(200,100);
    setWindowTitle("Resize Images");
}
int ResizeDlg::getValue(int para)
{
    if(para==1){
        return w;
    }else if(para==2){
        return h;
    }else{
        return 0;
    }
}
void ResizeDlg::setValue(int a,int b)
{
    w=a;
    h=b;
}

void ResizeDlg::onOkClicked()
{
    w=widthBox->value();
    h=heightBox->value();
    accept();
}

void ResizeDlg::onCancelClicked()
{
    reject();
}
