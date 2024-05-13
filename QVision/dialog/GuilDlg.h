#ifndef GuilDlg_H
#define GuilDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class GuilDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue(int which);
    float getFValue(int which);
    double getDValue(int which);
    GuilDlg(QWidget *parent=nullptr);
    static GuilDlg& ins(){static GuilDlg g;return g;}
    void setValue(int Mindist,int Level,double Dp,double Xi,int Buffersize,int Cannylow,int Cannyhigh,int Minangle,int Maxangle,int Anglestep,
                  int Anglethreshold,float Minscale,float Maxscale,float Angleplise,double Scalestep,int Scalethreshold,int Posthreshold);
public:
    int mindist;
    int level;
    double dp;
    double xi;

    int buffersize;
    int cannylow;
    int cannyhigh;
    int minangle;

    int maxangle;
    int anglestep;
    int anglethreshold;
    float minscale;

    float maxscale;
    float angleplise;
    double scalestep;
    int scalethreshold;
    int posthreshold;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QSpinBox *minDistBox;
    QSpinBox *levelBox;
    QSpinBox *dpBox;
    QSpinBox *xiBox;

    QSpinBox *buffersizeBox;
    QSpinBox *cannylowBox;
    QSpinBox *cannyhighBox;
    QSpinBox *minangleBox;

    QSpinBox *maxangleBox;
    QDoubleSpinBox *anglestepBox;
    QSpinBox *anglethresholdBox;
    QDoubleSpinBox *minscaleBox;

    QDoubleSpinBox *maxscaleBox;
    QSpinBox *anglepliseBox;
    QDoubleSpinBox *scalestepBox;
    QSpinBox *scalethresholdBox;
    QSpinBox *posthresholdBox;

    QLabel *tip1;
    QLabel *tip2;
    QLabel *tip3;
    QLabel *tip4;

    QLabel *tip5;
    QLabel *tip6;
    QLabel *tip7;
    QLabel *tip8;

    QLabel *tip9;
    QLabel *tip10;
    QLabel *tip11;
    QLabel *tip12;

    QLabel *tip13;
    QLabel *tip14;
    QLabel *tip15;
    QLabel *tip16;
    QLabel *tip17;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // GuilDlg_H
