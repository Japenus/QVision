#include "TemplateMatchDlg.h"

TemplateMatchDlg::TemplateMatchDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    matchThresval=new QSpinBox(this);
    tip=new QLabel("模板匹配阈值:");
    okBtn=new QPushButton("Ok",this);
    cancelBtn=new QPushButton("Cancel",this);

    matchThresval->setValue(90);
    matchThresval->setRange(0,255);
    matchThresval->setSingleStep(5);
    matchThresval->setKeyboardTracking(true);

    QVBoxLayout*layout= new QVBoxLayout(this);
    QHBoxLayout*inputRow= new QHBoxLayout(this);
    QHBoxLayout*btnRow = new QHBoxLayout(this);

    inputRow->addWidget(tip);
    inputRow->addWidget(matchThresval);
    btnRow->addWidget(okBtn);
    btnRow->addWidget(cancelBtn);
    layout->addLayout(inputRow);
    layout->addLayout(btnRow);
    setLayout(layout);

    connect(okBtn, &QPushButton::clicked, this, &TemplateMatchDlg::onOkClicked);
    connect(cancelBtn,&QPushButton::clicked, this, &TemplateMatchDlg::onCancelClicked);
    resize(100,50);
    setWindowTitle("Template Match");

}
int TemplateMatchDlg::getValue()
{
    return thresh;
}
void TemplateMatchDlg::setValue(int val)
{
    thresh=val;
}
void TemplateMatchDlg::onOkClicked()
{
    thresh= matchThresval->value();
    accept();
}

void TemplateMatchDlg::onCancelClicked()
{
    reject();
}
