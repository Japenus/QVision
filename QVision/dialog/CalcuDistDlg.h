#ifndef CalcuDistDlg_H
#define CalcuDistDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class CalcuDistDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue(int para);
    CalcuDistDlg(QWidget *parent=nullptr);
    void setValue(int a,int b,int c,int d);
    static CalcuDistDlg& ins(){static CalcuDistDlg g;return g;}
public:
    int x1;
    int y1;
    int x2;
    int y2;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QLabel *tip1;
    QLabel *tip2;
    QSpinBox *valX1;
    QSpinBox *valX2;
    QSpinBox *valY1;
    QSpinBox *valY2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // CalcuDistDlg_H
