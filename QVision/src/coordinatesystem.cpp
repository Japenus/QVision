#include "coordinatesystem.h"
CoordinateSystem::CoordinateSystem(QWidget *parent) : QWidget(parent)
{
    QPen p(Qt::cyan);
    QRect DeviceSize=QGuiApplication::screens().at(0)->geometry();
    int w=DeviceSize.width();
    int h=DeviceSize.height();
    label = new QLabel;
    drawShape =new QLabel;
    menu = new QHBoxLayout;
    main = new QVBoxLayout;
    precison = new QComboBox;
    box = new QPixmap(w/3,h/2);
    box->fill(Qt::transparent);
    painter = new QPainter(box);
    exit = new QPushButton("关闭");
    fallback = new QPushButton("重绘");
    label->setText("精度");
    menu->addWidget(fallback);
    menu->addWidget(exit);
    menu->addWidget(label);
    menu->addWidget(precison);

    QPoint origin = QPoint(this->width() / 2, this->height() / 2);
    QPoint axisXfrom(0,origin.y());
    QPoint axisXto(width(), origin.y());
    QPoint axisYfrom(origin.x(), 0);
    QPoint axisYto(origin.x(), height());

    p.setWidth(3);
    painter->setPen(p);
    painter->drawLine(axisXfrom,axisXto);
    painter->drawLine(axisYfrom,axisYto);
    for (int x = origin.x() + step; x < width(); x += step) {
        painter->drawLine(x, origin.y()-5, x, origin.y());
        painter->drawText(x-10, origin.y() + offset/6, QString::number(x - origin.x()));
    }
    for (int x = origin.x() - step; x > 0; x -= step) {
        painter->drawLine(x, origin.y()-5, x, origin.y());
        painter->drawText(x - 10, origin.y() + offset/6, QString::number(x - origin.x()));
    }
    for (int y = origin.y() - step; y > 0; y -= step) {
        painter->drawLine(origin.x(), y, origin.x() + 5, y);
        painter->drawText(origin.x()-offset/4, y + 5, QString::number(origin.y()-y));
    }
    for (int y = origin.y() + step; y < height(); y += step) {
        painter->drawLine(origin.x(), y, origin.x() + 5, y);
        painter->drawText(origin.x()-offset/4, y + 5, QString::number(origin.y()-y));
    }
    QFont font;
    font.setBold(true);
    font.setItalic(true);
    font.setPointSize(12);
    painter->setFont(font);

    painter->drawText(10,20,"n阶贝塞尔曲线模拟");
    painter->drawText(QPoint(width()/2-15,height()/2+15),"O");
    painter->drawText(QPoint(width()/2+offset*3,height()/2+offset/5),"X");
    painter->drawText(QPoint(width()/2-offset/5,height()/2-offset*2-20),"Y");


    drawShape->setPixmap(*box);
    drawShape->show();

    main->addWidget(drawShape);
    main->addLayout(menu);

    this->setStyleSheet("border: 1px solid gray;border-radius:5px;background-color: rgba(0, 0, 0, 0.4);color:cyan");
    label->setFixedSize(50,20);
    fallback->setFixedHeight(20);
    exit->setFixedHeight(20);
    precison->addItem(QString::number(0.1));
    precison->addItem(QString::number(0.01));
    precison->addItem(QString::number(0.001));
    connect(precison, QOverload<int>::of(&QComboBox::activated), this, [=](int index) {
        precision = precison->itemText(index).toDouble();
        bezierCurve(controlPnts, pntsOnCurve, precision);
        update();
    });
    connect(fallback, &QPushButton::clicked, this, &CoordinateSystem::redraw);
    connect(exit, &QPushButton::clicked, this, &CoordinateSystem::exitCurWin);
    resize(600, 400);
    this->setLayout(main);
    QIcon icon("ico.png");
    setWindowIcon(icon);
    setWindowTitle("坐标系");
}


void CoordinateSystem::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.save();
    painter.setBrush(QBrush(Qt::blue));
    QFontMetrics metrics(painter.font());
    for (auto i = 0; i < controlPnts.size(); i++) {
        painter.setPen(Qt::blue);
        painter.drawEllipse(controlPnts.at(i),10,10);
        painter.setPen(Qt::yellow);
        QString number = QString::number(i);
        auto rect = metrics.boundingRect(number);
        painter.drawText(controlPnts.at(i) + QPointF(-rect.width() / 2, rect.height() / 2 - 1.0), number);
    }
    painter.restore();
    if (controlPnts.size() >= 2) {
        QPainterPath curve;
        curve.moveTo(pntsOnCurve.at(0));
        for (auto i = 1; i < pntsOnCurve.size(); i++) curve.lineTo(pntsOnCurve.at(i));
        auto pen = painter.pen();
        pen.setColor(Qt::green);
        pen.setWidth(2.0);
        painter.setPen(pen);
        painter.drawPath(curve);
        painter.end();
    }
}

void CoordinateSystem::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton && e->pos().y() > 50) {
        mousePressed = true;
        if (iscompleted) {
            curIndex = -1;
            auto pos = e->pos();
            for (auto i = 0; i < controlPnts.size(); i++) {
                auto point = controlPnts.at(i);
                if (qAbs(qSqrt(qPow(pos.x() - point.x(), 2) + qPow(pos.y() - point.y(), 2))) < 10.0000) {
                    curIndex = i;
                    break;
                }
            }
        } else {
            controlPnts.append(e->pos());
            bezierCurve(controlPnts, pntsOnCurve, precision);
            update();
        }
    } else if (e->buttons() & Qt::RightButton) iscompleted = true;
}

void CoordinateSystem::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::LeftButton && mousePressed && curIndex != -1 && e->pos().y() > 50) {
        if (curIndex < controlPnts.size()) {
            controlPnts[curIndex] = e->pos();
            bezierCurve(controlPnts, pntsOnCurve, precision);
            update();
        }
    }
}

void CoordinateSystem::mouseReleaseEvent(QMouseEvent *e)
{
    curIndex = -1;
    if (e->buttons() & Qt::LeftButton) {
        mousePressed = false;
    }
}


bool CoordinateSystem::eventFilter(QObject *obj, QEvent *e)
{
    if (obj == drawShape) {
        if (e->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(e);
            QApplication::sendEvent(this, mouseEvent);
            return true;
        }
    }
    return eventFilter(obj, e);
}


void CoordinateSystem::wheelEvent(QWheelEvent *e)
{
    int delta = e->angleDelta().y();
    QMessageBox::information(this,"提示","右键结束添加控制点");
    if (delta > 0) {
        QRect currentRect = painter->window();
        int newWidth = currentRect.width() * 1.1;
        int newHeight = currentRect.height() * 1.1;
        painter->setViewport(QRect(currentRect.x(), currentRect.y(), newWidth, newHeight));
    } else {
        QRect currentRect = painter->window();
        int newWidth = currentRect.width() * 0.9;
        int newHeight = currentRect.height() * 0.9;
        painter->setViewport(QRect(currentRect.x(), currentRect.y(), newWidth, newHeight));
    }
    update();
}


void CoordinateSystem::bezierCurve(const QList<QPointF> &src, QList<QPointF> &dest, qreal precision)
{
    if (src.size() <= 0) return;
    QList<QPointF>().swap(dest);
    for (qreal t = 0; t < 1.0000; t += precision) {
        int size = src.size();
        QVector<qreal> coefficient(size, 0);
        coefficient[0] = 1.000;
        qreal u1 = 1.0 - t;

        for (int j = 1; j <= size - 1; j++) {
            qreal saved = 0.0;
            for (int k = 0; k < j; k++){
                qreal temp = coefficient[k];
                coefficient[k] = saved + u1 * temp;
                saved = t * temp;
            }
            coefficient[j] = saved;
        }
        QPointF resultPoint;
        for (int i = 0; i < size; i++) {
            QPointF point = src.at(i);
            resultPoint = resultPoint + point * coefficient[i];
        }
        dest.append(resultPoint);
    }
}


void CoordinateSystem::redraw()
{
    iscompleted=false;
    QList<QPointF>().swap(controlPnts);
    QList<QPointF>().swap(pntsOnCurve);
    update();
}


void CoordinateSystem::exitCurWin()
{
    this->close();
}
