#include "database.h"
DataBase::DataBase(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("Spyder.png");
    QMenuBar *menubar = new QMenuBar();
    QMenu *menulist = menubar->addMenu("Connection");
    QAction *connSqlServer = new QAction("SQL Server", this);
    menulist->addSeparator();
    menulist->addAction(connSqlServer);
    setMenuBar(menubar);
    QRect DeviceSize=QGuiApplication::screens().at(0)->geometry();
    int w=DeviceSize.width();
    int h=DeviceSize.height();
    tip1=new QLabel("数据表");
    tip2=new QLabel("状态字");
    tip1->setAlignment(Qt::AlignCenter);
    tip2->setAlignment(Qt::AlignCenter);
    addDataItem= new QPushButton("添加");
    delDataItem= new QPushButton("删除");
    fixDataItem = new QPushButton("修改");
    findDataItem = new QPushButton("查找");
    cleanTips = new QPushButton("清除");
    disConn = new QPushButton("断开");
    databaseLists = new QPushButton("数据库列表");
    datatableLists = new QPushButton("数据表列表");
    showInfo=new QTextEdit();
    dataList=new QTableView();

    QStandardItem *cells=new QStandardItem();
    QStandardItemModel *tableData=new QStandardItemModel(20,3,this);
    tableData->setHorizontalHeaderLabels(QStringList()<<"请求地址"<<"状态"<<"结果");
    for (int var = 1; var < 20; ++var) {
        cells->appendRow(new QStandardItem(QString::number(var)));
    }
    tableData->setVerticalHeaderItem(0,cells);
    dataList->setModel(tableData);

    tip1->setFixedHeight(tipHeight);
    tip2->setFixedHeight(tipHeight);

    //style
    addDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    delDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    fixDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    findDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    cleanTips->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    disConn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");

    databaseLists->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    datatableLists->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    tip1->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    tip2->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    showInfo->setStyleSheet("border: 2px solid purple;padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    dataList->setStyleSheet("border: 1px solid purple;color:blue;");


    QVBoxLayout *MainStruct =new  QVBoxLayout;
    QHBoxLayout *Row = new QHBoxLayout;
    QHBoxLayout *Row1 = new QHBoxLayout;
    QHBoxLayout *Row2 = new QHBoxLayout;
    QHBoxLayout *Row3 = new QHBoxLayout;
    QHBoxLayout *Row4 = new QHBoxLayout;
    QHBoxLayout *Row5 = new QHBoxLayout;
    QWidget *central=new QWidget;

    Row->addWidget(databaseLists);Row->addWidget(datatableLists);
    Row1->addWidget(tip1);Row1->addWidget(tip2);
    Row2->addWidget(dataList);Row2->addWidget(showInfo);
    Row3->addWidget(addDataItem);Row3->addWidget(delDataItem);
    Row4->addWidget(fixDataItem);Row4->addWidget(findDataItem);
    Row5->addWidget(disConn);Row5->addWidget(cleanTips);

    MainStruct->addLayout(Row);
    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(Row3);
    MainStruct->addLayout(Row4);
    MainStruct->addLayout(Row5);
    MainStruct->setStretch(0,10);

    central->setLayout(MainStruct);
    setCentralWidget(central);

    connect(connSqlServer,&QAction::triggered,this,&DataBase::ConnectSQLServer);

    connect(databaseLists, &QPushButton::clicked, this, &DataBase::curDatabases);
    connect(datatableLists, &QPushButton::clicked, this, &DataBase::curDataTables);
    connect(addDataItem, &QPushButton::clicked, this, &DataBase::addItem);
    connect(delDataItem, &QPushButton::clicked, this, &DataBase::deleteItem);
    connect(fixDataItem, &QPushButton::clicked, this, &DataBase::updateItem);
    connect(findDataItem, &QPushButton::clicked, this, &DataBase::findItem);
    connect(disConn, &QPushButton::clicked, this, &DataBase::disConnection);
    connect(cleanTips, &QPushButton::clicked, this, &DataBase::clearTips);

    resize(w/2,h/2);
    setWindowIcon(icon);
    setWindowTitle("DataBase Management");
}

void DataBase::ConnectSQLServer()
{
    if(!qDB.isOpen()){
        qDB=ts.SqlServer();
        showInfo->setText("已连接");
    }else{
        showInfo->setText("<warning>重复的连接");
    }
}

void DataBase::curDatabases()
{
    if(qDB.isOpen()){
        QStringList databases=ts.GetDataBases(&qDB);
        for(int i=0;i<databases.size();i++){
            showInfo->setText(databases.at(i));
        }
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::curDataTables()
{
    if(qDB.isOpen()){
        QStringList tables=ts.GetTables(&qDB);
        for(int i=0;i<tables.size();i++){
            showInfo->setText(tables.at(i));
        }
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::addItem()
{
    if(qDB.isOpen()){
        showInfo->setText(ts.addData());
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::deleteItem()
{
    if(qDB.isOpen()){
        showInfo->setText(ts.delData());
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::updateItem()
{
    if(qDB.isOpen()){
        showInfo->setText(ts.updateData());
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::findItem()
{
    if(qDB.isOpen()){
        showInfo->setText(ts.findData());
    }else{
        showInfo->setText("未连接");
    }
}
void DataBase::disConnection()
{
    if(qDB.isOpen()){
        qDB.close();
        showInfo->setText("连接已关闭");
    }
}
void DataBase::clearTips()
{
    showInfo->clear();
}
