#include "RenameDlg.h"

RenameDlg::RenameDlg(QWidget *parent):QDialog(parent)
{
    tip1=new QLabel("文件夹路径:");
    tip2=new QLabel("输入前缀:");
    tip3=new QLabel("起始编号:");
    tip4=new QLabel("新扩展名:");

    dirBox=new QLineEdit(this);
    prefixBox=new QLineEdit(this);
    extenBox=new QLineEdit(this);
    increBox=new QSpinBox(this);

    okBtn=new QPushButton("OK",this);
    cancelBtn=new QPushButton("Cancel",this);
    selectDirBtn=new QPushButton("GetDir",this);

    dirBox->setPlaceholderText("C:/Users/Desktop");
    prefixBox->setPlaceholderText("eg:sample");
    extenBox->setPlaceholderText("jpg");

    increBox->setValue(1);
    increBox->setRange(0,1000);
    increBox->setSingleStep(1);
    dirBox->setMaximumWidth(200);
    extenBox->setMaximumWidth(200);
    increBox->setMaximumWidth(200);
    prefixBox->setMaximumWidth(200);
    dirBox->setMinimumWidth(200);
    extenBox->setMinimumWidth(200);
    increBox->setMinimumWidth(200);
    prefixBox->setMinimumWidth(200);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *subRow1=new QHBoxLayout(this);
    QHBoxLayout *subRow2 =new QHBoxLayout(this);
    QHBoxLayout *subRow3= new QHBoxLayout(this);
    QHBoxLayout *subRow4 = new QHBoxLayout(this);
    QHBoxLayout *btnRow = new QHBoxLayout(this);

    subRow1->addWidget(tip1);subRow1->addWidget(dirBox);
    subRow2->addWidget(tip2);subRow2->addWidget(prefixBox);
    subRow3->addWidget(tip3);subRow3->addWidget(increBox);
    subRow4->addWidget(tip4);subRow4->addWidget(extenBox);
    btnRow->addWidget(selectDirBtn);btnRow->addWidget(okBtn);btnRow->addWidget(cancelBtn);
    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(subRow3);
    MainStruct->addLayout(subRow4);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);

    connect(okBtn,&QPushButton::clicked,this,&RenameDlg::onOkClicked);
    connect(cancelBtn,&QPushButton::clicked,this,&RenameDlg::onCancelClicked);
    connect(selectDirBtn,&QPushButton::clicked,this,&RenameDlg::onselectclicked);
    resize(300,100);
    setWindowTitle("Rename File");

}
int RenameDlg::getValue()
{
    return incre;
}

QString RenameDlg::getValue(int para)
{
    if(para==1){
        return dir;
    }else if(para==2){
        return exten;
    }else if(para==3){
        return prefix;
    }else{
        return "";
    }
}
void RenameDlg::setValue(int a,QString b,QString c,QString d)
{
    incre=a;
    dir=b;
    exten=c;
    prefix=d;
}
void RenameDlg::onselectclicked()
{
    QString directory = QFileDialog::getExistingDirectory(this,tr("选择文件夹"),QDir::homePath());
    if(!directory.isEmpty()) dirBox->setText(directory);
}

void RenameDlg::onOkClicked()
{
    incre=increBox->value();
    dir=dirBox->text();
    exten=extenBox->text();
    prefix=prefixBox->text();
    accept();
}

void RenameDlg::onCancelClicked()
{
    reject();
}
