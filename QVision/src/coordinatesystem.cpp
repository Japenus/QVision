#include "coordinatesystem.h"
CoordinateSystem::CoordinateSystem(QWidget *parent) : QMainWindow(parent)
{
    container = new QWidget(this);
    exitSubWin = new QPushButton("关闭");
    QRect DeviceSize=QGuiApplication::screens().at(0)->geometry();
    int w=DeviceSize.width();
    int h=DeviceSize.height();
    QHBoxLayout *MainStruct = new QHBoxLayout();
    QVBoxLayout *all = new QVBoxLayout();
    selectPrecison = new QComboBox();
    label = new QLabel("精度:");
    drawShape =new QLabel(this);
    box=new QPixmap(w/3,h/2);
    MainStruct->addWidget(label);
    MainStruct->addWidget(exitSubWin);
    MainStruct->addWidget(selectPrecison);

    box->fill(Qt::transparent);
    painter=new QPainter(box);
    QPoint origin = QPoint(this->width() / 2, this->height() / 2);
    painter->drawLine(0, origin.y(), width(), origin.y());
    painter->drawLine(origin.x(), 0, origin.x(), height());
    for (int x = origin.x() + step; x < width(); x += step) {
        painter->drawLine(x, origin.y() - 5, x, origin.y() + 5);
    }
    for (int x = origin.x() - step; x > 0; x -= step) {
        painter->drawLine(x, origin.y() - 5, x, origin.y() + 5);
    }
    for (int y = origin.y() + step; y < height(); y += step) {
        painter->drawLine(origin.x() - 5, y, origin.x() + 5, y);
    }
    for (int y = origin.y() - step; y > 0; y -= step) {
        painter->drawLine(origin.x() - 5, y, origin.x() + 5, y);
    }

    painter->setPen(Qt::red);
    painter->drawRect(10, 10, 80, 80);

    painter->end();

    drawShape->setPixmap(*box);
    drawShape->show();

    all->addWidget(drawShape);
    all->addLayout(MainStruct);
    container->setStyleSheet("border: 1px solid red;border-radius:5px;");
    drawShape->setStyleSheet("border: 1px solid blue;border-radius:5px;");

    label->setFixedSize(100,20);
    exitSubWin->setFixedWidth(100);
    selectPrecison->addItem(QString::number(0.1));
    selectPrecison->addItem(QString::number(0.01));
    selectPrecison->addItem(QString::number(0.001));

    container->setLayout(all);
    setCentralWidget(container);

    connect(selectPrecison, QOverload<int>::of(&QComboBox::activated), this, [=](int index) {
        precision = selectPrecison->itemText(index).toDouble();
        BezierCurve(controlPnts, pntsOnCurve, precision);
        update();
    });
    connect(exitSubWin, &QPushButton::clicked, this, &CoordinateSystem::exitCurWin);
    resize(600, 400);
    setWindowTitle("二维坐标系");
}


void CoordinateSystem::paintEvent(QPaintEvent *event)
{

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.save();
    painter.setBrush(QBrush(Qt::red));
    QFontMetrics metrics(painter.font());
    for (auto i = 0; i < controlPnts.size(); i++) {
        painter.setPen(Qt::red);
        painter.drawEllipse(controlPnts.at(i), 10.0, 10.0);
        painter.setPen(Qt::white);
        QString number = QString::number(i);
        auto rect = metrics.boundingRect(number);
        painter.drawText(controlPnts.at(i) + QPointF(-rect.width() / 2, rect.height() / 2 - 1.0), number);
    }
    painter.restore();

    if (controlPnts.size() >= 2) {
        QPainterPath curve;
        curve.moveTo(pntsOnCurve.at(0));
        for (auto i = 1; i < pntsOnCurve.size(); i++) {
            curve.lineTo(pntsOnCurve.at(i));
        }
        auto pen = painter.pen();
        pen.setColor(Qt::blue);
        pen.setWidth(2.0);
        painter.setPen(pen);
        painter.drawPath(curve);
    }
}

void CoordinateSystem::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && event->pos().y() > 50) {
        mousePressed = true;
        if (iscompleted) {
            curIndex = -1;
            auto pos = event->pos();
            for (auto i = 0; i < controlPnts.size(); i++) {
                auto point = controlPnts.at(i);
                if (qAbs(qSqrt(qPow(pos.x() - point.x(), 2) + qPow(pos.y() - point.y(), 2))) < 10.0000) {
                    curIndex = i;
                    break;
                }
            }
        } else {
            controlPnts.append(event->pos());
            BezierCurve(controlPnts, pntsOnCurve, precision);
            update();
        }
    } else if (event->buttons() & Qt::RightButton) {
        iscompleted = true;
    }
}

void CoordinateSystem::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton && mousePressed && curIndex != -1 && event->pos().y() > 50) {
        if (curIndex < controlPnts.size()) {
            controlPnts[curIndex] = event->pos();
            BezierCurve(controlPnts, pntsOnCurve, precision);
            update();
        }
    }
}

void CoordinateSystem::mouseReleaseEvent(QMouseEvent *event)
{
    curIndex = -1;
    if (event->buttons() & Qt::LeftButton) {
        mousePressed = false;
    }
}

void CoordinateSystem::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        iscompleted = false;
        QList<QPointF>().swap(controlPnts);
        QList<QPointF>().swap(pntsOnCurve);
        update();
    }
}


void CoordinateSystem::BezierCurve(const QList<QPointF> &src, QList<QPointF> &dest, qreal precision)
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


void CoordinateSystem::exitCurWin()
{
    this->close();
}
