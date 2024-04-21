#ifndef AreaFillDlg_H
#define AreaFillDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class AreaFillDlg:public QDialog
{
    Q_OBJECT
public:
    AreaFillDlg(QWidget *parent=nullptr);
    int getValue(int para);
    void setValue(int size,int num);
public:
    int PointSize;
    int PointNum;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QSpinBox *sizeBox;
    QSpinBox *numBox;
    QLabel *tip1;
    QLabel *tip2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // AreaFillDlg_H
