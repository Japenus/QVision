#include "ThresholdDlg.h"

ThresholdDlg::ThresholdDlg(QWidget *parent):QDialog(parent)
{
    tip1=new QLabel("模式:");
    tip2=new QLabel("阈值:");
    thval=new QSpinBox(this);
    thtype=new QSpinBox(this);
    okBtn=new QPushButton("Ok");
    cancelBtn=new QPushButton("Cancel");
    thval->setValue(80);
    thval->setRange(0,255);
    thval->setSingleStep(10);
    thval->setFixedWidth(100);

    thtype->setValue(0);
    thtype->setRange(0,20);
    thtype->setSingleStep(1);
    thtype->setFixedWidth(100);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *Row1 = new QHBoxLayout(this);
    QHBoxLayout *Row2 = new QHBoxLayout(this);
    QHBoxLayout *btnRow = new QHBoxLayout(this);

    Row1->addWidget(tip1);Row1->addWidget(thtype);
    Row2->addWidget(tip2);Row2->addWidget(thval);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);

    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(btnRow);

    setLayout(MainStruct);
    connect(okBtn, &QPushButton::clicked, this, &ThresholdDlg::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked, this, &ThresholdDlg::onCancelClicked);
    resize(100,50);
    setWindowTitle("Threshold Process");
}
void ThresholdDlg::setValue(int val,int type)
{
    thresval=val;
    threstype=type;
}
int ThresholdDlg::getValue(int para)
{
    if(para==1){
        return threstype;
    }else if(para==2){
        return thresval;
    }else{
        return -1;
    }
}

void ThresholdDlg::onOkClicked()
{
    thresval = thval->value();
    threstype=thtype->value();
    accept();
}

void ThresholdDlg::onCancelClicked()
{
    reject();
}
