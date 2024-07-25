#include "screencut.h"
ScreenCut::ScreenCut(QWidget *parent)
{
    QRegion virBox;
    setCursor(Qt::CrossCursor);
    QWidget widget(nullptr, Qt::Desktop);
    QScreen *screen = QApplication::primaryScreen();
    const QRect &rect = screen->availableGeometry();
    setWindowFlags(Qt::Widget | Qt::FramelessWindowHint);
    const QList<QScreen*> &screens = QApplication::screens();
    for(auto *screen : screens) virBox += screen->geometry();
    setFixedSize(virBox.boundingRect().size());
    widget.setVisible(false);
    widget.setGeometry(geometry());
    captured = screen->grabWindow(0,rect.x(), rect.y(), width(), height());
}

void ScreenCut::CutArea(QPixmap &pix)
{
    CurrentArea=FormatTransfer::ins().QPixmap2Mat(pix);
    imwrite("ScreenShot.png",CurrentArea);
}


void ScreenCut::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    Cursor.setX(event->pos().x());
    Cursor.setY(event->pos().y());
    update();
}

void ScreenCut::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    QPen pen(Cyan,2);
    painter.setPen(pen);
    painter.drawPixmap(0, 0, width(), height(), captured);
    int w = 0, h = 0;
    if(drawing)
    {
        w = Cursor.x() - Start.x();
        h = Cursor.y() - Start.y();
        painter.drawRect(Start.x() - 1, Start.y() - 1, w + 1, h + 1);
    }
    else if(End != Start)
    {
        w = End.x() - Start.x();
        h = End.y() - Start.y();
        painter.drawRect(Start.x() - 1, Start.y() - 1, w + 1, h + 1);
    }
    pen.setWidth(4);
    pen.setColor(Magenta);
    painter.setPen(pen);
}

void ScreenCut::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        Start = event->pos();
        Cursor = Start;
        drawing = true;
    }
    update();
}

void ScreenCut::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    if(event->button() == Qt::LeftButton)
    {
        End = event->pos();
        drawing = false;
    }
    if(event->button() == Qt::RightButton)
    {
        const int width = End.x() - Start.x();
        const int height = End.y() - Start.y();
        QScreen *screen = QApplication::primaryScreen();
        const QRect &rect = screen->availableGeometry();
        QPixmap pix = screen->grabWindow(0,Start.x() + rect.x(), Start.y() + rect.y(), width, height);
        CutArea(pix);
        close();
    }
    if(event->button() == Qt::MiddleButton)
    {
        close();
    }
}
