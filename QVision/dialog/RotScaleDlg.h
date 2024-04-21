#ifndef RotScaleDlg_H
#define RotScaleDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class RotScaleDlg:public QDialog
{
    Q_OBJECT
public:
    RotScaleDlg(QWidget *parent=nullptr);
    int getValue(int which);
    void setValue(int a,int b);
public:
    int rotate;
    int scale;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QSpinBox*rotateBox;
    QSpinBox *scaleBox;
    QLabel *tip1;
    QLabel *tip2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // RotScaleDlg_H
