#ifndef RenameDlg_H
#define RenameDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class RenameDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue();
    QString getValue(int which);
    RenameDlg(QWidget *parent=nullptr);
    void setValue(int a,QString b,QString c,QString d);
    static RenameDlg& ins(){static RenameDlg g;return g;}
public:
   int incre;
   QString dir;
   QString exten;
   QString prefix;
private slots:
   void onOkClicked();
   void onCancelClicked();
   void onselectclicked();
private:
    QLineEdit *dirBox;
    QLineEdit *prefixBox;
    QLineEdit *extenBox;
    QSpinBox *increBox;
    QLabel *tip1;
    QLabel *tip2;
    QLabel *tip3;
    QLabel *tip4;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QPushButton *selectDirBtn;
};

#endif // RenameDlg_H
