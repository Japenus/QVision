#include "database.h"
DataBase::DataBase(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("Spyder.png");
    QMenuBar *menubar = new QMenuBar();
    QMenu *menulist = menubar->addMenu("Connection");
    QAction *connSqlServer = new QAction("SQL Server", this);
    QAction *connMySql = new QAction("MySQL", this);
    QAction *connSQLite = new QAction("SQLite", this);
    menulist->addSeparator();
    menulist->addAction(connSqlServer);
    menulist->addAction(connSQLite);
    menulist->addAction(connMySql);
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
    databaseListBox=new QComboBox;
    datatableListsBox=new QComboBox;

    databaseListBox->setEditable(true);
    datatableListsBox->setEditable(true);

    showInfo=new QTextEdit();
    dataList=new QTableView();

    tableCols=new QStandardItem();
    tableData=new QStandardItemModel();
    item = new QTableWidgetItem();

    dataList->setModel(tableData);

    tip1->setFixedHeight(fixHeight);
    tip2->setFixedHeight(fixHeight);
    showInfo->setReadOnly(true);

    //style
    addDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    delDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    fixDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    findDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    cleanTips->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    disConn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    databaseListBox->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    datatableListsBox->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");


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
    QHBoxLayout *Row6 = new QHBoxLayout;
    QWidget *central=new QWidget;

    Row->addWidget(databaseLists);Row->addWidget(datatableLists);
    Row1->addWidget(tip1);Row1->addWidget(tip2);
    Row2->addWidget(dataList);Row2->addWidget(showInfo);
    Row3->addWidget(addDataItem);Row3->addWidget(delDataItem);
    Row4->addWidget(fixDataItem);Row4->addWidget(findDataItem);
    Row5->addWidget(disConn);Row5->addWidget(cleanTips);
    Row6->addWidget(databaseListBox);Row6->addWidget(datatableListsBox);

    MainStruct->addLayout(Row);
    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row6);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(Row3);
    MainStruct->addLayout(Row4);
    MainStruct->addLayout(Row5);
    MainStruct->setStretch(0,10);

    central->setLayout(MainStruct);
    setCentralWidget(central);

    connect(connMySql,&QAction::triggered,this,&DataBase::ConnectMySQL);
    connect(connSQLite,&QAction::triggered,this,&DataBase::ConnectSQLite);
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

void DataBase::ConnectMySQL()
{
    if(!qDB.isOpen()){
        qDB=ts.MySql();
        if(qDB.isOpen()){
            showInfo->setText("已连接");
        }else{
            showInfo->setText("配置错误");
            return;
        }
    }else{
        showInfo->setText("<warning>重复的连接");
    }
}


void DataBase::ConnectSQLite()
{
    if(!qDB.isOpen()){
        qDB=ts.SQLite();
        if(qDB.isOpen()){
            showInfo->setText("已连接");
        }else{
            showInfo->setText("配置错误");
            return;
        }
    }else{
        showInfo->setText("<warning>重复的连接");
    }
}

void DataBase::curDatabases()
{
    if(qDB.isOpen()){
        databaseListBox->clear();
        QStringList databases=ts.GetDataBases(&qDB);
        for(int i=0;i<databases.size();i++){
            showInfo->setText(databases.at(i));
            databaseListBox->addItem(databases.at(i));
        }
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::curDataTables()
{
    if(qDB.isOpen()){
        geTable=ts.GetTables(&qDB);
        for(int i=0;i<geTable.size();i++){
            temp=geTable.at(i);
            showInfo->setText("获取表名:"+geTable.at(i));
            datatableListsBox->addItem(geTable.at(i));
            tablElement=ts.GetTableFields(&qDB,geTable.at(i));
            qslist<<tablElement;
            tableData->setHorizontalHeaderLabels(qslist);
            dataItem=ts.GetTableData(&qDB,geTable.at(i));
            for(int i = 0; i < dataItem.size(); i++){
                QList<QStandardItem*> rowData;
                for(int j = 0; j < dataItem[i].size(); j++){
                    rowData.append(new QStandardItem(dataItem[i][j]));
                }
                int rowNum = tableData->rowCount();
                tableData->insertRow(rowNum);
                for(int col = 0; col < rowData.size(); col++){
                    tableData->setItem(rowNum, col, rowData.at(col));
                }
            }
        }
        showInfo->setText("获取数据成功");
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::addItem()
{
    if(qDB.isOpen()){
        QString res=ts.AddData(&qDB,temp);
        showInfo->setText(res);
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::deleteItem()
{
    if(qDB.isOpen()){
        QString res=ts.DelData(&qDB,temp);
        showInfo->setText(res);
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::updateItem()
{
    if(qDB.isOpen()){
        QString res=ts.UpdateData(&qDB,temp);
        showInfo->setText(res);
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::findItem()
{
    if(qDB.isOpen()){
        QString res=ts.FindData(&qDB,temp);
        showInfo->setText(res);
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
