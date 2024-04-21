#ifndef FixThresholdDlg_H
#define FixThresholdDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class FixThresholdDlg:public QDialog
{
    Q_OBJECT
public:
    FixThresholdDlg(QWidget *parent=nullptr);
    int getValue();
    void setValue(int val);
public:
    int Val;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QLabel *tip;
    QSpinBox *spinBox;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // FixThresholdDlg_H
