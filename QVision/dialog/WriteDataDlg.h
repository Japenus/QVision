#ifndef WriteDataDlg_H
#define WriteDataDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class WriteDataDlg:public QDialog
{
    Q_OBJECT
public:
    WriteDataDlg(QWidget *parent=nullptr);
    int getValue(int which);QString getInfo(int which);
    void setValue(int a,int b,QString c,QString d,QString e);
    static WriteDataDlg& ins(){static WriteDataDlg g;return g;}
public:
    int wnum;
    int increvar;
    QString dir;
    QString context;
    QString other;
private slots:
    void onOkClicked();
    void onCancelClicked();
    void onChooseClicked();
private:
    QSpinBox *writeBox;
    QSpinBox *increBox;
    QLineEdit *dirBox;
    QLineEdit *otherBox;
    QLineEdit *contextBox;
    QLabel *tip1;
    QLabel *tip2;
    QLabel *tip3;
    QLabel *tip4;
    QLabel *tip5;
    QPushButton *okBtn;
    QPushButton *getDirBtn;
    QPushButton *cancelBtn;
};

#endif // WriteDataDlg_H
