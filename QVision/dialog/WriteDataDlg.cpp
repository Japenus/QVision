#include "WriteDataDlg.h"

WriteDataDlg::WriteDataDlg(QWidget *parent):QDialog(parent)
{
    tip1=new QLabel("文件路径:");
    tip2=new QLabel("写入数量:");
    tip3=new QLabel("写入内容:");
    tip4=new QLabel("起始编号:");
    tip5=new QLabel("附加内容:");
    writeBox=new QSpinBox(this);
    increBox=new QSpinBox(this);
    dirBox=new QLineEdit(this);
    otherBox=new QLineEdit(this);
    contextBox=new QLineEdit(this);

    okBtn=new QPushButton("Ok",this);
    getDirBtn=new QPushButton("GetFilePath",this);
    cancelBtn=new QPushButton("Cancel",this);

    writeBox->setValue(10);
    writeBox->setRange(0,10000);
    writeBox->setSingleStep(10);
    writeBox->setFixedWidth(200);

    increBox->setValue(1);
    increBox->setRange(0,100);
    increBox->setSingleStep(1);
    increBox->setFixedWidth(200);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *subRow1=new QHBoxLayout(this);
    QHBoxLayout *subRow2=new QHBoxLayout(this);
    QHBoxLayout *subRow3=new QHBoxLayout(this);
    QHBoxLayout *subRow4=new QHBoxLayout(this);
    QHBoxLayout *subRow5=new QHBoxLayout(this);
    QHBoxLayout *btnRow=new QHBoxLayout(this);

    subRow1->addWidget(tip1);subRow1->addWidget(dirBox);
    subRow2->addWidget(tip2);subRow2->addWidget(writeBox);
    subRow3->addWidget(tip3);subRow3->addWidget(contextBox);
    subRow4->addWidget(tip4);subRow4->addWidget(increBox);
    subRow5->addWidget(tip5);subRow5->addWidget(otherBox);
    btnRow->addWidget(getDirBtn);btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);

    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(subRow3);
    MainStruct->addLayout(subRow4);
    MainStruct->addLayout(subRow5);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);
    connect(okBtn, &QPushButton::clicked, this, &WriteDataDlg::onOkClicked);
    connect(getDirBtn,&QPushButton::clicked, this, &WriteDataDlg::onChooseClicked);
    connect(cancelBtn,&QPushButton::clicked, this, &WriteDataDlg::onCancelClicked);
    resize(200,100);
    setWindowTitle("Write Data To File");

}
void WriteDataDlg::setValue(int a,int b,QString c,QString d,QString e)
{
    wnum=a;
    increvar=b;
    dir=c;
    context=d;
    other=e;
}

int WriteDataDlg::getValue(int para)
{
    if(para==1){
        return wnum;
    }else if(para==2){
        return increvar;
    }else{
        return 0;
    }
}
QString WriteDataDlg::getInfo(int para)
{
    if(para==1){
        return dir;
    }else if(para==2){
        return context;
    }else if(para==3){
        return other;
    }else{
        return "";
    }
}
void WriteDataDlg::onChooseClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择文件"),QDir::homePath());
    if(!filePath.isEmpty()) dirBox->setText(filePath);
}
void WriteDataDlg::onOkClicked()
{
    wnum=writeBox->value();
    increvar=increBox->value();
    dir=dirBox->text();
    context=contextBox->text();
    other=otherBox->text();
    accept();
}

void WriteDataDlg::onCancelClicked()
{
    reject();
}
