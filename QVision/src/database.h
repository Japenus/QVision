#ifndef DATABASE_H
#define DATABASE_H
#include <QTabWidget>
#include "tools.h"
#include "global.h"
class DataBase:public QMainWindow
{
public:
    Tools ts;
    DataBase(QWidget *parent = nullptr);
private slots:
    void addItem();
    void findItem();
    void clearTips();
    void updateItem();
    void deleteItem();
    void curDatabases();
    void disConnection();
    void curDataTables();
    void ConnectSQLServer();
private:
    int tipHeight=30;
    QLabel *tip1;
    QLabel *tip2;
    QSqlDatabase qDB;
    QTextEdit *showInfo;
    QTableView *dataList;
    QPushButton *addDataItem;
    QPushButton *delDataItem;
    QPushButton *fixDataItem;
    QPushButton *findDataItem;
    QPushButton *databaseLists;
    QPushButton *datatableLists;
    QPushButton *cleanTips;
    QPushButton *disConn;
};

#endif // DATABASE_H
