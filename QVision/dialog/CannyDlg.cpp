#include "CannyDlg.h"

CannyDlg::CannyDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    tip1=new QLabel("低阈值:");
    tip2=new QLabel("高阈值:");

    CannyLow=new QSpinBox(this);
    CannyHigh=new QSpinBox(this);
    okBtn=new QPushButton("ok",this);
    cancelBtn=new QPushButton("cancel",this);

    CannyLow->setValue(50);
    CannyLow->setRange(0,255);
    CannyLow->setSingleStep(10);
    CannyLow->setFixedWidth(100);
    CannyHigh->setValue(80);
    CannyHigh->setRange(0,255);
    CannyHigh->setSingleStep(10);
    CannyHigh->setFixedWidth(100);

    QVBoxLayout *MainStruct = new QVBoxLayout();
    QHBoxLayout *subRow1 = new QHBoxLayout();
    QHBoxLayout *subRow2 = new QHBoxLayout();
    QHBoxLayout *btnRow = new QHBoxLayout();

    subRow1->addWidget(tip1);subRow1->addWidget(CannyLow);
    subRow2->addWidget(tip2);subRow2->addWidget(CannyHigh);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);

    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);

    connect(okBtn, &QPushButton::clicked, this, &CannyDlg::onOkClicked);
    connect(cancelBtn,&QPushButton::clicked, this,&CannyDlg::onCancelClicked);

    resize(160,100);
    setWindowTitle("Canny Para");

}
int CannyDlg::getValue(int para)
{
    if(para==1){
        return low;;
    }else if(para==2){
        return high;
    }else{
        return -1;
    }
}
void CannyDlg::setValue(int h,int l)
{
    high=h;
    low=l;
}

void CannyDlg::onOkClicked()
{
    low=CannyLow->value();
    high=CannyHigh->value();
    accept();
}

void CannyDlg::onCancelClicked()
{
    reject();
}
