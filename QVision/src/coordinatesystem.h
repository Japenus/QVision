#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include"global.h"

class CoordinateSystem:public QMainWindow
{
public:
    CoordinateSystem(QWidget *parent = nullptr);
    static CoordinateSystem& ins(){static CoordinateSystem c;return c;}
protected:
    void paintEvent(QPaintEvent *event) override;
public slots:
    void exitCurWin();
private:
    QWidget *box;
    QPainter *painter;
    QWidget *container;
    QPushButton *exitSubWin;
};

#endif // COORDINATESYSTEM_H
