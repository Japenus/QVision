#include "AreaFillDlg.h"

AreaFillDlg::AreaFillDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    sizeBox=new QSpinBox(this);
    numBox=new QSpinBox(this);
    tip1=new QLabel("尺寸:");
    tip2=new QLabel("数量:");
    okBtn=new QPushButton("Ok",this);
    cancelBtn=new QPushButton("Cancel",this);

    sizeBox->setValue(10);
    sizeBox->setRange(0,50);
    sizeBox->setSingleStep(2);
    sizeBox->setFixedWidth(100);

    numBox->setValue(4);
    numBox->setRange(0,100);
    numBox->setSingleStep(1);
    numBox->setFixedWidth(100);

    okBtn->setFixedSize(50,20);
    cancelBtn->setFixedSize(50,20);

    QVBoxLayout *MainStruct = new QVBoxLayout();
    QHBoxLayout *subRow1 = new QHBoxLayout();
    QHBoxLayout *subRow2 = new QHBoxLayout();
    QHBoxLayout *btnRow = new QHBoxLayout();

    subRow1->addWidget(tip1);subRow1->addWidget(sizeBox);
    subRow2->addWidget(tip2);subRow2->addWidget(numBox);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);

    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(btnRow);

    setLayout(MainStruct);
    connect(okBtn, &QPushButton::clicked, this, &AreaFillDlg::onOkClicked);
    connect(cancelBtn, &QPushButton::clicked, this, &AreaFillDlg::onCancelClicked);
    resize(100,100);
    setWindowTitle("Area Fill");
}

void AreaFillDlg::setValue(int size,int num)
{
    PointSize=size;
    PointNum=num;
}

int AreaFillDlg::getValue(int para)
{
    if(para==1){
        return PointNum;
    }else if(para==2){
        return PointSize;
    }else{
        return -1;
    }
}

void AreaFillDlg::onOkClicked()
{
    PointSize=sizeBox->value();
    PointNum=numBox->value();
    accept();
}

void AreaFillDlg::onCancelClicked()
{
    reject();
}
