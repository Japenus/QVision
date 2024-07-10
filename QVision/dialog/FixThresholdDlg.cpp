#include "FixThresholdDlg.h"

FixThresholdDlg::FixThresholdDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    tip=new QLabel("固定阈值:");
    spinBox=new QSpinBox(this);
    okBtn=new QPushButton("ok",this);
    cancelBtn=new QPushButton("cancel",this);
    spinBox->setValue(50);
    spinBox->setRange(0,255);
    spinBox->setSingleStep(10);
    spinBox->setKeyboardTracking(true);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *Row1 = new QHBoxLayout(this);
    QHBoxLayout *btnRow = new QHBoxLayout(this);

    Row1->addWidget(tip);Row1->addWidget(spinBox);
    btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);
    MainStruct->addLayout(Row1);MainStruct->addLayout(btnRow);
    setLayout(MainStruct);

    connect(okBtn, &QPushButton::clicked, this, &FixThresholdDlg::onOkClicked);
    connect(cancelBtn,&QPushButton::clicked, this, &FixThresholdDlg::onCancelClicked);

    resize(100,50);
    setWindowTitle("Fix Threshold");
}
int FixThresholdDlg::getValue()
{
    return Val;
}
void FixThresholdDlg::setValue(int val)
{
    Val=val;
}

void FixThresholdDlg::onOkClicked()
{
    Val= spinBox->value();
    accept();
}

void FixThresholdDlg::onCancelClicked()
{
    reject();
}
