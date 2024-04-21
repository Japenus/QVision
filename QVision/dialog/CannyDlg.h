#ifndef CannyDlg_H
#define CannyDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class CannyDlg:public QDialog
{
    Q_OBJECT
public:
    CannyDlg(QWidget *parent=nullptr);
    int getValue(int whichval);
    void setValue(int h,int l);
public:
    int high,low;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QLabel *tip1;
    QLabel *tip2;
    QSpinBox *CannyHigh;
    QSpinBox *CannyLow;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // CannyDlg_H
