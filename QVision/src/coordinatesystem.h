#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include"global.h"

class CoordinateSystem:public QMainWindow
{
public:
    CoordinateSystem(QWidget *parent = nullptr);
    static CoordinateSystem& ins(){static CoordinateSystem c;return c;}
public:
    void BezierCurve(const QList<QPointF> &src, QList<QPointF> &dest, qreal precision);
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
public slots:
    void exitCurWin();
private:
    QPixmap *box;
    QLabel *label;
    QLabel *drawShape;
    QPainter *painter;
    QWidget *container;
    QPushButton *exitSubWin;
    QComboBox *selectPrecison;
private:
    int step=20;
    bool iscompleted = false;
    bool mousePressed = false;
    int curIndex = -1;
    qreal precision = 0.1;
    QList<QPointF> controlPnts;
    QList<QPointF> pntsOnCurve;
};

#endif // COORDINATESYSTEM_H
