#ifndef NETSPYDERDLG_H
#define NETSPYDERDLG_H
#include <QObject>
#include"tools.h"
#include"global.h"
class NetSpyderDlg:public QDialog
{
    Q_OBJECT
public:
    NetSpyderDlg(QWidget *parent=nullptr);
    QString getValue(int para);
    void setValue(QString link,QString txt,QString path,QString html);
public:
    Tools tools;
    QString url;
    QString keyword;
    QString savePath;
    QString htmlCode;
private slots:
    void onStopClicked();
    void onStartClicked();
    void onPauseClicked();
    void onCancelClicked();
    void onContinueClicked();
    void onGetSavePathClicked();
private:
    QLabel *tip1;
    QLabel *tip2;
    QLabel *tip3;
    QLabel *tip4;
    QLabel *tip5;
    QString code;
    QLineEdit *urlBox;
    QLineEdit *searchBox;
    QTextEdit *htmlCodeBox;
    QLineEdit *savePathBox;
    QTableView *displayUrls;
    QStandardItem *Rows;
    QProgressBar *progress;
    QHeaderView *tableStyle;
    QPushButton *Stop;
    QPushButton *Start;
    QPushButton *Pause;
    QPushButton *Cancel;
    QPushButton *GetPath;
    QPushButton *Continue;
    QStandardItemModel *tableData;
};

#endif // NETSPYDERDLG_H
