#ifndef QHS_H
#define QHS_H
#include "global.h"
class Draw : public QGraphicsView
{
    Q_OBJECT
public:
    Draw(QWidget *parent = nullptr);

    void setImage(const QImage &img);

protected:
    void wheelEvent(QWheelEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void drawStar(QPainter &painter, int centerX, int centerY, int size);
private:
    QImage image;
    qreal scaleFactor;
};

class Qhs : public QMainWindow
{
    Q_OBJECT

public:
    Draw *view;
    Qhs(QWidget *parent = nullptr);
    ~Qhs();

public slots:
    void openImg();
    void markPos();
    void closeQhs();

private:
    QWidget *con;
    QVBoxLayout *main;
    QPushButton *open;
    QPushButton *draw;
    QPushButton *exit;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *target;
};
#endif // QHS_H
