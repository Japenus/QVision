#include "database.h"
DataBase::DataBase(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("ico.png");
    QMenuBar *menubar = new QMenuBar();
    QMenu *menulist0 = menubar->addMenu("File");
    QMenu *menulist = menubar->addMenu("Connection");
    QAction *connSqlServer = new QAction("SQL Server", this);
    QAction *SQLiteFile = new QAction("SQLite File", this);
    QAction *TransferToTxt = new QAction("Transfer", this);
    QAction *connMySql = new QAction("MySQL", this);
    QAction *connSQLite = new QAction("SQLite", this);
    menulist0->addSeparator();
    menulist0->addAction(SQLiteFile);
    menulist0->addAction(TransferToTxt);

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
    refreshItem = new QPushButton("更新");
    findDataItem = new QPushButton("查找");
    closeCurWin = new QPushButton("关闭");
    insertNullRow = new QPushButton("插入");
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
    addDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    delDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    refreshItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    findDataItem->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    cleanTips->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    disConn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    insertNullRow->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    closeCurWin->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    databaseListBox->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    datatableListsBox->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");


    databaseLists->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    datatableLists->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    tip1->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    tip2->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    showInfo->setStyleSheet("border: 2px solid purple;padding: 5px;color: "+color1+";border-radius: 5px;font-weight: bold;");
    dataList->setStyleSheet("border: 1px solid purple;color:"+color1+";");


    QVBoxLayout *MainStruct =new  QVBoxLayout;
    QHBoxLayout *Row = new QHBoxLayout;
    QHBoxLayout *Row1 = new QHBoxLayout;
    QHBoxLayout *Row2 = new QHBoxLayout;
    QHBoxLayout *Row3 = new QHBoxLayout;
    QHBoxLayout *Row4 = new QHBoxLayout;
    QHBoxLayout *Row5 = new QHBoxLayout;
    QHBoxLayout *Row6 = new QHBoxLayout;
    QHBoxLayout *Row7 = new QHBoxLayout;
    QWidget *central=new QWidget;

    Row->addWidget(databaseLists);Row->addWidget(datatableLists);
    Row1->addWidget(tip1);Row1->addWidget(tip2);
    Row2->addWidget(dataList);Row2->addWidget(showInfo);
    Row3->addWidget(addDataItem);Row3->addWidget(delDataItem);
    Row4->addWidget(refreshItem);Row4->addWidget(findDataItem);
    Row5->addWidget(disConn);Row5->addWidget(cleanTips);
    Row6->addWidget(databaseListBox);Row6->addWidget(datatableListsBox);
    Row7->addWidget(insertNullRow);Row7->addWidget(closeCurWin);

    MainStruct->addLayout(Row);
    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row6);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(Row3);
    MainStruct->addLayout(Row4);
    MainStruct->addLayout(Row5);
    MainStruct->addLayout(Row7);
    MainStruct->setStretch(0,10);

    central->setLayout(MainStruct);
    setCentralWidget(central);

    connect(connMySql,&QAction::triggered,this,&DataBase::ConnectMySQL);
    connect(connSQLite,&QAction::triggered,this,&DataBase::ConnectSQLite);
    connect(connSqlServer,&QAction::triggered,this,&DataBase::ConnectSQLServer);
    connect(TransferToTxt,&QAction::triggered,this,&DataBase::TransDBToText);
    connect(SQLiteFile,&QAction::triggered,this,&DataBase::OpenSQLiteFile);
    connect(databaseLists, &QPushButton::clicked, this, &DataBase::curDatabases);
    connect(datatableLists, &QPushButton::clicked, this, &DataBase::curDataTables);
    connect(addDataItem, &QPushButton::clicked, this, &DataBase::addItem);
    connect(delDataItem, &QPushButton::clicked, this, &DataBase::deleteItem);
    connect(refreshItem, &QPushButton::clicked, this, &DataBase::updateItem);
    connect(findDataItem, &QPushButton::clicked, this, &DataBase::findItem);
    connect(disConn, &QPushButton::clicked, this, &DataBase::disConnection);
    connect(cleanTips, &QPushButton::clicked, this, &DataBase::clearTips);

    connect(insertNullRow, &QPushButton::clicked, this, &DataBase::insert);
    connect(closeCurWin, &QPushButton::clicked, this, &DataBase::closeWin);

    resize(w/2,h/2);
    setWindowIcon(icon);
    setWindowTitle("DataBase Management");
}


void DataBase::TransDBToText()
{
    dbPath=QFileDialog::getOpenFileName(nullptr,tr("选择数据库文件"),".db",tr("DataBase (*.db *.sqlite3)"));
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if(!dbPath.isEmpty() && db.open()){
        QString sql="select * from "+QString(db.tables().first());
        QSqlQuery que(sql);
        QFile f("Transferred.txt");
        if(!f.open(QIODevice::WriteOnly|QIODevice::Text)){
            QMessageBox::warning(nullptr,"警告","写入文件失败!");
            return;
        }
        QTextStream out(&f);
        while(que.next()){
            QString data;
            for(int i=0;i<que.record().count();i++){
                data+=que.value(i).toString()+"\t";
            }
            out<<data.trimmed()<<"\t";
        }
        f.close();
        db.close();
        QMessageBox::information(nullptr,"Tip","转换完成!");
    }else{
        QMessageBox::warning(nullptr,"警告","转换失败!");
        return;
    }
}

void DataBase::OpenSQLiteFile()
{
    dbPath=QFileDialog::getOpenFileName(nullptr,tr("Choose File"),".db",tr("DataBase (*.db *.sqlite3)"));
    if(!dbPath.isNull()){
        databaseListBox->insertItem(0, dbPath);
        showInfo->setText("已添加数据库文件");
    }else{
        showInfo->setText("添加数据库文件失败");
        return;
    }
}


void DataBase::ConnectSQLServer()
{
    if(!qDB.isOpen()){
        qDB=Tools::ins().SqlServer();
        showInfo->setText("已连接");
    }else{
        showInfo->setText("重复的连接");
    }
}

void DataBase::ConnectMySQL()
{
    if(!qDB.isOpen()){
        qDB=Tools::ins().MySql();
        if(qDB.isOpen()){
            showInfo->setText("已连接");
        }else{
            showInfo->setText("配置错误");
            return;
        }
    }else{
        showInfo->setText("重复的连接");
    }
}


void DataBase::ConnectSQLite()
{
    if(!qDB.isOpen()){
        if(!dbPath.isNull()){
            qDB=Tools::ins().SQLite(dbPath);
            if(qDB.isOpen()){
                showInfo->setText("已连接");
            }else{
                showInfo->setText("配置错误");
                return;
            }
        }else{
            showInfo->setText("先选择SQLite数据库文件");
        }
    }else{
        showInfo->setText("重复的连接");
    }
}

void DataBase::curDatabases()
{
    if(qDB.isOpen()){
        databaseListBox->clear();
        QStringList databases=Tools::ins().GetDataBases(&qDB);
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
    if(qDB.isOpen())
    {
        geTable=Tools::ins().GetTables(&qDB);
        for(int i=0;i<geTable.size();i++)
        {
            temp=geTable.at(i);
            showInfo->setText("获取表名:"+geTable.at(i));
            datatableListsBox->addItem(geTable.at(i));
            tablElement=Tools::ins().GetTableFields(&qDB,geTable.at(i));
            qslist<<tablElement;
            tableData->setHorizontalHeaderLabels(qslist);
            dataItem=Tools::ins().GetTableData(&qDB,geTable.at(i));
            for(int i = 0; i < dataItem.size(); i++)
            {
                QList<QStandardItem*> rowData;
                for(int j = 0; j < dataItem[i].size(); j++)
                {
                    rowData.append(new QStandardItem(dataItem[i][j]));
                }
                int rowNum = tableData->rowCount();
                tableData->insertRow(rowNum);
                for(int col = 0; col < rowData.size(); col++)
                {
                    tableData->setItem(rowNum, col, rowData.at(col));
                }
            }
        }
        showInfo->setText("获取数据成功");
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::showCurData()
{
    curDataIndex=dataList->selectionModel()->selectedIndexes();
    for(auto &index:curDataIndex){
        curSelectedRow=index.row();
        curSelectedColumn=index.column();
    }
    selectedData = tableData->data(tableData->index(curSelectedRow, curSelectedColumn)).toString();
    qInfo()<<selectedData;
}

void DataBase::addItem()
{
    if(qDB.isOpen()){
        QString lastRowData1 = tableData->index(tableData->rowCount() - 1, 0).data().toString();
        QString lastRowData2 = tableData->index(tableData->rowCount() - 1, 1).data().toString();
        QString lastRowData3 = tableData->index(tableData->rowCount() - 1, 2).data().toString();
        QString lastRowData4 = tableData->index(tableData->rowCount() - 1, 3).data().toString();
        QString sql = QString("insert into userData(userName,gender,age,userId) values('%1','%2','%3','%4')")
                          .arg(lastRowData1).arg(lastRowData2).arg(lastRowData3).arg(lastRowData4);
        QSqlQuery query;
        query.exec(sql);
        showInfo->setText("添加成功");
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::deleteItem()
{
    if(qDB.isOpen()){
        curDataIndex=dataList->selectionModel()->selectedIndexes();
        for(auto &index:curDataIndex){
            curSelectedRow=index.row();
            curSelectedColumn=index.column();
        }
        selectedData = tableData->data(tableData->index(curSelectedRow, curSelectedColumn)).toString();
        sql = QString("delete from userData where userName = '%1'").arg(selectedData);
        QSqlQuery query;
        query.exec(sql);
        showInfo->setText("已删除("+selectedData+")");
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::updateItem()
{
    if(qDB.isOpen()){
        qslist.clear();
        tableData->clear();
        curDataTables();
        showInfo->setText("数据更新成功");
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::findItem()
{
    if(qDB.isOpen())
    {
        searchField = QInputDialog::getText(nullptr, "查找", "请输入姓名：", QLineEdit::Normal, "", nullptr, Qt::WindowFlags());
        if(!searchField.isEmpty())
        {
            QSqlQuery query;
            QStringList searchList;
            sql=QString("select * from userData where userName='%1'").arg(searchField);
            QList<QStandardItem*> items = tableData->findItems(searchField, Qt::MatchExactly, 0);
            for (auto &d : items)
            {
                int rowIndex = d->row();
                int columnIndex = d->column();
                searchList.append("<行" + FormatTransfer::ins().Int2QString(rowIndex+1) + ",列" + FormatTransfer::ins().Int2QString(columnIndex+1) + ">");
            }
            if (!searchList.isEmpty()) {
                temp=searchField + "在表中的位置:" + searchList.join(",");
            } else {
                showInfo->setText("未找到:" + searchField);
            }
            if (query.exec(sql) && query.next()) {
                QString recordInDB = query.value("userName").toString();
                showInfo->setText(temp+",数据库中存在记录:" + recordInDB);
            } else {
                showInfo->setText("未找到数据:" + searchField);
            }
        }else{
            showInfo->setText("未输入查询字段");
        }
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::disConnection()
{
    if(qDB.isOpen()){
        qDB.close();
        qslist.clear();
        tableData->clear();
        databaseListBox->clear();
        datatableListsBox->clear();
        showInfo->setText("连接已关闭");
    }else{
        showInfo->setText("无连接");
    }
}


void DataBase::insert()
{
    if(qDB.isOpen()){
        int rowCount = tableData->rowCount();
        tableData->insertRow(rowCount);
        showInfo->setText("添加空行成功");
    }else{
        showInfo->setText("未连接");
    }
}

void DataBase::closeWin()
{
    this->close();
}


void DataBase::clearTips()
{
    showInfo->clear();
}
