#ifndef BallardDlg_H
#define BallardDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class BallardDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue(int which);
    BallardDlg(QWidget *parent=nullptr);
    static BallardDlg& ins(){static BallardDlg g;return g;}
    void setValue(int a,int b,double c,int d,int e,int f,int g);
public:
    int mindist;
    int level;
    double dp;
    int buffersize;
    int vote;
    int cannylow;
    int cannyhigh;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QSpinBox *minDistBox;
    QSpinBox *levelBox;
    QSpinBox *dpBox;
    QSpinBox *buffersizeBox;
    QSpinBox *voteBox;
    QSpinBox *cannylowBox;
    QSpinBox *cannyhighBox;
    QLabel *tip1;
    QLabel *tip2;
    QLabel *tip3;
    QLabel *tip4;
    QLabel *tip5;
    QLabel *tip6;
    QLabel *tip7;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // BallardDlg_H
