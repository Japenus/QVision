#ifndef ThresholdDlg_H
#define ThresholdDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class ThresholdDlg:public QDialog
{
    Q_OBJECT
public:
    ThresholdDlg(QWidget *parent=nullptr);
    void setValue(int val);
    int getValue(int whichpara);
    void setValue(int val,int type);
    static ThresholdDlg& ins(){static ThresholdDlg g;return g;}
public:
    int thresval,threstype;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QLabel *tip1;
    QLabel *tip2;
    QSpinBox *thtype;
    QSpinBox *thval;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QVBoxLayout *MainStruct;
    QHBoxLayout *Row1;
    QHBoxLayout *Row2;
    QHBoxLayout *btnRow;

};

#endif // ThresholdDlg_H
