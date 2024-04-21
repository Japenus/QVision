#include "StatisticPixelDlg.h"

StatisticPixelDlg::StatisticPixelDlg(QWidget *parent):QDialog(parent)
{
    tip=new QLabel("像素值:");
    pixel=new QSpinBox(this);
    okBtn=new QPushButton("Ok",this);
    cancelBtn=new QPushButton("Cancel",this);

    pixel->setValue(80);
    pixel->setRange(0,255);
    pixel->setSingleStep(20);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *Row = new QHBoxLayout(this);
    QHBoxLayout *btnRow = new QHBoxLayout(this);
    Row->addWidget(tip);Row->addWidget(pixel);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);
    MainStruct->addLayout(Row);MainStruct->addLayout(btnRow);
    setLayout(MainStruct);

    connect(okBtn, &QPushButton::clicked, this, &StatisticPixelDlg::onOkClicked);
    connect(cancelBtn,&QPushButton::clicked, this, &StatisticPixelDlg::onCancelClicked);

    resize(100,50);
    setWindowTitle("Statistic Pixels");
}
int StatisticPixelDlg::getValue()
{
    return pixelval;
}

void StatisticPixelDlg::setValue(int val)
{
    pixelval=val;
}

void StatisticPixelDlg::onOkClicked()
{
    pixelval=pixel->value();
    accept();
}

void StatisticPixelDlg::onCancelClicked()
{
    reject();
}
