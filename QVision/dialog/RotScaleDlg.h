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
    double getValue();
    double getDValue();
    void setValue(double rot,double scal);
public:
    double rotate;
    double scale;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QDoubleSpinBox *rotateBox;
    QDoubleSpinBox *scaleBox;
    QLabel *tip1;
    QLabel *tip2;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // RotScaleDlg_H
