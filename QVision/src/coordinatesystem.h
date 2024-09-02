#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H
#include"global.h"
class CoordinateSystem:public QMainWindow
{
public:
    CoordinateSystem(QWidget *parent = nullptr);
    static CoordinateSystem& ins(){static CoordinateSystem c;return c;}
    void BezierCurve(const QList<QPointF> &src, QList<QPointF> &dest, qreal precision);
protected:
    virtual void paintEvent(QPaintEvent *e) override;
    virtual void wheelEvent(QWheelEvent *e) override;
    bool eventFilter(QObject *obj, QEvent *e) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
    virtual void mousePressEvent(QMouseEvent *e) override;
    virtual void mouseReleaseEvent(QMouseEvent *e) override;
public slots:
    void redraw();
    void exitCurWin();
private:
    QPixmap *box;
    QLabel *label;
    QLabel *drawShape;
    QPainter *painter;
    QWidget *container;
    QPushButton *reDraw;
    QPushButton *exitSubWin;
    QComboBox *selectPrecison;
private:
    int step=40;
    int offset=100;
    int curIndex = -1;
    qreal precision = 0.1;
    bool iscompleted = false;
    bool mousePressed = false;
    QList<QPointF> controlPnts;
    QList<QPointF> pntsOnCurve;
};

#endif // COORDINATESYSTEM_H
