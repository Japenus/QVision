#ifndef DATABASE_H
#define DATABASE_H
#include "tools.h"
#include "global.h"
#include "formattransfer.h"
class DataBase:public QMainWindow
{
public:
    DataBase(QWidget *parent = nullptr);
    static DataBase & ins(){static DataBase db;return db;}
    void showCurData();
private slots:
    void insert();
    void addItem();
    void closeWin();
    void findItem();
    void clearTips();
    void updateItem();
    void deleteItem();
    void curDatabases();
    void ConnectMySQL();
    void ConnectSQLite();
    void disConnection();
    void curDataTables();
    void TransDBToText();
    void OpenSQLiteFile();
    void ConnectSQLServer();
private:
    QString sql;
    QString temp;
    QLabel *tip1;
    QLabel *tip2;
    QString dbPath;
    QString searchField;
    QString color1="yellow";
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
