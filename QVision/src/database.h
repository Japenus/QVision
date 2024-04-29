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
    void showCurData();
private slots:
    void addItem();
    void findItem();
    void clearTips();
    void insert();
    void closeWin();
    void updateItem();
    void deleteItem();
    void ConnectMySQL();
    void ConnectSQLite();
    void curDatabases();
    void disConnection();
    void curDataTables();
    void ConnectSQLServer();
private:
    QString temp;
    QString sql;
    QLabel *tip1;
    QLabel *tip2;

    QSqlDatabase qDB;
    int fixHeight=30;
    int curSelectedRow;
    bool isUpdate=false;
    QString selectedData;
    int curSelectedColumn;

    QStringList qslist;
    QStringList geTable;
    QStringList tablElement;

    QPushButton *disConn;
    QPushButton *cleanTips;
    QPushButton *addDataItem;
    QPushButton *delDataItem;
    QPushButton *refreshItem;
    QPushButton *findDataItem;
    QPushButton *closeCurWin;
    QPushButton *insertNullRow;
    QPushButton *databaseLists;
    QPushButton *datatableLists;

    QComboBox *databaseListBox;
    QComboBox *datatableListsBox;

    QTextEdit *showInfo;
    QTableView *dataList;
    QTableWidgetItem *item;
    QStandardItem *tableCols;
    QModelIndexList curDataIndex;
    QStandardItemModel *tableData;
    QList<QList<QString>> dataItem;
    // QItemSelectionModel *selectedItem;
};

#endif // DATABASE_H
