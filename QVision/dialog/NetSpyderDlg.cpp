#include "netspyderdlg.h"
NetSpyderDlg::NetSpyderDlg(QWidget *parent):QDialog(parent)
{

    tip1=new QLabel("输入链接:");
    tip2=new QLabel("图片格式:");
    tip3=new QLabel("搜索结果:");
    tip4=new QLabel("保存路径:");
    tip5=new QLabel("解析页面:");

    urlBox=new QLineEdit(this);
    searchBox=new QLineEdit(this);
    htmlCodeBox=new QTextEdit(this);
    savePathBox=new QLineEdit(this);

    displayUrls=new QTableView(this);
    progress=new QProgressBar(this);

    Stop=new QPushButton("Stop");
    Start=new QPushButton("Start");
    Pause=new QPushButton("Pause");
    Cancel=new QPushButton("Cancel");
    GetPath=new QPushButton("GetPath");
    Continue=new QPushButton("Continue");

    Rows=new QStandardItem();
    tableData=new QStandardItemModel();


    displayUrls->setModel(tableData);
    tableStyle=displayUrls->verticalHeader();
    tableStyle->setDefaultSectionSize(20);
    tableStyle=displayUrls->horizontalHeader();
    tableStyle->setDefaultSectionSize(150);

    tableStyle->resizeSection(0,450);
    tableStyle->resizeSection(1,50);
    tableStyle->resizeSection(2,50);

    searchBox->setMaxLength(1000);
    progress->setValue(0);
    tip3->setFixedHeight(10);
    displayUrls->setFixedHeight(100);

    QHBoxLayout *mid = new QHBoxLayout;
    QVBoxLayout *subRow1=new QVBoxLayout;
    QVBoxLayout *subRow2 =new QVBoxLayout;
    QVBoxLayout *subRow3= new QVBoxLayout;
    QHBoxLayout *btnRow = new QHBoxLayout;
    QVBoxLayout *MainStruct = new QVBoxLayout;

    subRow1->addWidget(tip1);
    subRow1->addWidget(tip2);
    subRow1->addWidget(tip4);

    subRow2->addWidget(urlBox);
    subRow2->addWidget(searchBox);
    subRow2->addWidget(savePathBox);

    mid->addLayout(subRow1);
    mid->addLayout(subRow2);

    subRow3->addWidget(tip3);
    subRow3->addWidget(displayUrls);
    subRow3->addWidget(tip5);
    subRow3->addWidget(htmlCodeBox);
    subRow3->addWidget(progress);

    btnRow->addWidget(Start);
    btnRow->addWidget(Pause);
    btnRow->addWidget(Stop);
    btnRow->addWidget(Continue);
    btnRow->addWidget(GetPath);
    btnRow->addWidget(Cancel);

    MainStruct->addLayout(mid);
    MainStruct->addLayout(subRow3);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);

    connect(Stop,&QPushButton::clicked,this,&NetSpyderDlg::onStopClicked);
    connect(Start,&QPushButton::clicked,this,&NetSpyderDlg::onStartClicked);
    connect(Pause,&QPushButton::clicked,this,&NetSpyderDlg::onPauseClicked);
    connect(Cancel,&QPushButton::clicked,this,&NetSpyderDlg::onCancelClicked);
    connect(Continue,&QPushButton::clicked,this,&NetSpyderDlg::onContinueClicked);
    connect(GetPath,&QPushButton::clicked,this,&NetSpyderDlg::onGetSavePathClicked);


    resize(600,600);
    QIcon icon("ico.png");
    setWindowIcon(icon);
    setWindowTitle("Network Spyder");
}
QString NetSpyderDlg::getValue(int para)
{
    if(para==1){
        return url;
    }else if(para==2){
        return keyword;
    }else if(para==3){
        return savePath;
    }else if(para==4){
        return htmlCode;
    }else{
        return "";
    }
}
void NetSpyderDlg::setValue(QString link,QString txt,QString path,QString html)
{
    url=link;
    keyword=txt;
    savePath=path;
    htmlCode=html;
}
void NetSpyderDlg::onStopClicked()
{
    reject();
}

void NetSpyderDlg::onStartClicked()
{
    url=urlBox->text();
    if(url.isEmpty()) return;
    keyword=searchBox->text();
    savePath=savePathBox->text();
    htmlCode=htmlCodeBox->toHtml();
    QElapsedTimer *curTime=new QElapsedTimer();
    code=tools.NetSpyder(url,progress,curTime);
    htmlCodeBox->setText(code);
}

void NetSpyderDlg::onPauseClicked()
{
    reject();
}

void NetSpyderDlg::onCancelClicked()
{
    reject();
}

void NetSpyderDlg::onContinueClicked()
{
    reject();
}

void NetSpyderDlg::onGetSavePathClicked()
{
    QString folderPath=QFileDialog::getExistingDirectory(this,tr("Select Folder"),"",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    if(!folderPath.isEmpty()) savePathBox->setText(folderPath);
}
