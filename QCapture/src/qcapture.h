#ifndef QCAPTURE_H
#define QCAPTURE_H
#include <src/global.h>
class Draw : public QGraphicsView
{
    Q_OBJECT
public:
    Draw(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPointF startPoint;
    QGraphicsRectItem *rectItem;
};

class QCapture : public QMainWindow
{
    Q_OBJECT

public:
    Draw *view;
    bool isPause;
    QCapture(QWidget *parent = nullptr);
    ~QCapture();

public slots:
    void closeDlib();
    void pauseDlib();
    void beginDetect();

private:
    VideoCapture cap;
    QVBoxLayout *main;
    QWidget *container;
    QPushButton *exit;
    QPushButton *pause;
    QPushButton *detect;
    QGraphicsScene *scene;
};
#endif // QCAPTURE_H
