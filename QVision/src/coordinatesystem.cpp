#include "coordinatesystem.h"

CoordinateSystem::CoordinateSystem(QWidget *parent) : QMainWindow(parent)
{
    container = new QWidget(this);
    exitSubWin = new QPushButton("关闭", this);
    exitSubWin->setFixedWidth(50);

    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    MainStruct->addWidget(exitSubWin);
    container->setStyleSheet("QWidget{"
                             "border: 1px solid red;"
                             "border-radius: 5px;"
                             "}");

    container->setContentsMargins(10, 10, 10, 10);
    container->setLayout(MainStruct);
    setCentralWidget(container);

    connect(exitSubWin, &QPushButton::clicked, this, &CoordinateSystem::exitCurWin);
    resize(600, 400);
    setWindowTitle("二维坐标系");
}


void CoordinateSystem::paintEvent(QPaintEvent *event)
{
    int step = 20;
    QPainter painter(this);
    QPoint origin = QPoint(this->width() / 2, this->height() / 2);
    painter.drawLine(0, origin.y(), width(), origin.y());
    painter.drawLine(origin.x(), 0, origin.x(), height());
    for (int x = origin.x() + step; x < width(); x += step) {
        painter.drawLine(x, origin.y() - 5, x, origin.y() + 5);
    }
    for (int x = origin.x() - step; x > 0; x -= step) {
        painter.drawLine(x, origin.y() - 5, x, origin.y() + 5);
    }
    for (int y = origin.y() + step; y < height(); y += step) {
        painter.drawLine(origin.x() - 5, y, origin.x() + 5, y);
    }
    for (int y = origin.y() - step; y > 0; y -= step) {
        painter.drawLine(origin.x() - 5, y, origin.x() + 5, y);
    }
}


void CoordinateSystem::exitCurWin()
{
    this->close();
}
