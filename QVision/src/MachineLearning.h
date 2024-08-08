#ifndef MACHINELEARNING_H
#define MACHINELEARNING_H

#include <Global.h>
class MachineLearning:public QMainWindow
{
public:
    MachineLearning(QWidget *parent=nullptr);
    ~MachineLearning();
    static MachineLearning & ins(){static MachineLearning m;return m;}

public slots:
    void modifyBackground();
    void closeWin();

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawStar(QPainter *painter, int x, int y, int outerRadius, int innerRadius, int points);

private:
    QImage bgImg;
    QString srcBg;
    QPushButton *lbtn;
    QPushButton *rbtn;
    QWidget *left;
    QWidget *right;
    QWidget *center;
    QHBoxLayout *main;
    QVBoxLayout *pLeft;
    QVBoxLayout *pRight;

};

#endif // MACHINELEARNING_H
