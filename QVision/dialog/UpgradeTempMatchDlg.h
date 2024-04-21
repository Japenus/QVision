#ifndef UpgradeTempMatchDlg_H
#define UpgradeTempMatchDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class UpgradeTempMatchDlg:public QDialog
{
    Q_OBJECT
public:
    UpgradeTempMatchDlg(QWidget *parent=nullptr);
    int getValue();
    double getValue(int whichpara);
    void setValue(int a,double b,double c,double d,double e,double f);
public:
    int ImgThres;
    double ScaleStep;
    double OverlapThres;
    double MinScaleRatio;
    double MaxScaleRatio;
    double PreProcessThres;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QLabel  *tip1;
    QLabel  *tip2;
    QLabel  *tip3;
    QLabel  *tip4;
    QLabel  *tip5;
    QLabel  *tip6;
    QSpinBox *ImgThresBox;
    QDoubleSpinBox  *ScalestepBox;
    QDoubleSpinBox  *MinScaleRatioBox;
    QDoubleSpinBox  *MaxScaleRatioBox;
    QDoubleSpinBox  *PreProcessThresBox;
    QDoubleSpinBox  *OverlapThresBox;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // UpgradeTempMatchDlg_H
