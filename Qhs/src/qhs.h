#ifndef QHS_H
#define QHS_H
#include "global.h"
class Draw : public QGraphicsView
{
    Q_OBJECT
public:
    Draw(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) override;
};

class Qhs : public QMainWindow
{
    Q_OBJECT

public:
    Draw *view;
    Qhs(QWidget *parent = nullptr);
    ~Qhs();

public slots:
    void start();

private:
    QWidget *con;
    QVBoxLayout *main;
    QPushButton *open;
    QGraphicsScene *scene;
};
#endif // QHS_H
