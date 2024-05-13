#ifndef StatisticPixelDlg_H
#define StatisticPixelDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class StatisticPixelDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue();
    void setValue(int val);
    StatisticPixelDlg(QWidget *parent=nullptr);
    static StatisticPixelDlg& ins() {static StatisticPixelDlg s;return s;}
public:
    int pixelval;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QLabel *tip;
    QSpinBox *pixel;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // StatisticPixelDlg_H
