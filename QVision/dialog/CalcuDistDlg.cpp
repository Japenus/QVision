#include "CalcuDistDlg.h"
CalcuDistDlg::CalcuDistDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    tip1=new QLabel("起点:");
    tip2=new QLabel("终点:");
    valX1=new QSpinBox(this);
    valX2=new QSpinBox(this);
    valY1=new QSpinBox(this);
    valY2=new QSpinBox(this);
    okBtn=new QPushButton("Ok",this);
    cancelBtn=new QPushButton("Cancel",this);

    valX1->setValue(0);
    valX1->setRange(0,10000);
    valX1->setSingleStep(20);

    valX2->setValue(0);
    valX2->setRange(0,10000);
    valX2->setSingleStep(20);

    valY1->setValue(100);
    valY1->setRange(0,10000);
    valY1->setSingleStep(20);

    valY2->setValue(100);
    valY2->setRange(0,10000);
    valY2->setSingleStep(20);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *Row1 = new QHBoxLayout(this);
    QHBoxLayout *Row2 = new QHBoxLayout(this);
    QHBoxLayout *btnRow = new QHBoxLayout(this);
    Row1->addWidget(tip1);Row1->addWidget(valX1);Row1->addWidget(valX2);
    Row2->addWidget(tip2);Row2->addWidget(valY1);Row2->addWidget(valY2);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);
    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);
    connect(okBtn, &QPushButton::clicked, this, &CalcuDistDlg::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked, this, &CalcuDistDlg::onCancelClicked);

    resize(200,80);
    setWindowTitle("Calculate Distance");
}
int CalcuDistDlg::getValue(int para)
{
    if(para==1){
        return x1;
    }else if(para==2){
        return y1;
    }else if(para==3){
        return x2;
    }else if(para==4){
        return y2;
    }else{
        return -1;
    }
}
void CalcuDistDlg::setValue(int a,int b,int c,int d)
{
    x1=a;
    y1=b;
    x2=c;
    y2=d;
}

void CalcuDistDlg::onOkClicked()
{
    x1=valX1->value();
    x2=valX2->value();
    y2=valY1->value();
    y2=valY2->value();
    accept();
}

void CalcuDistDlg::onCancelClicked()
{
    reject();
}
