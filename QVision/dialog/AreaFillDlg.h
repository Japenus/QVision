#ifndef AreaFillDlg_H
#define AreaFillDlg_H
#include <QObject>
#include "tools.h"
#include "global.h"
class AreaFillDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue(int para);
    void setValue(int size,int num);
    AreaFillDlg(QWidget *parent=nullptr);
    static AreaFillDlg& ins(){static AreaFillDlg g;return g;}
public:
    int PointSize;
    int PointNum;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QLabel *tip2;
    QLabel *tip1;
    QSpinBox *numBox;
    QSpinBox *sizeBox;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // AreaFillDlg_H
