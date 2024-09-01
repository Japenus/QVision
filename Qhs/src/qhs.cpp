#include "qhs.h"
Qhs::Qhs(QWidget *parent): QMainWindow(parent)
{
    con=new QWidget;
    main=new QVBoxLayout;
    view = new Draw;
    scene=new QGraphicsScene;
    target=new QGraphicsEllipseItem;
    open=new QPushButton("Open");
    draw=new QPushButton("Draw");
    exit=new QPushButton("Close");
    main->addWidget(view);
    main->addWidget(open);
    main->addWidget(draw);
    main->addWidget(exit);
    setCentralWidget(con);
    con->setLayout(main);
    view->show();
    view->setScene(scene);
    scene->addItem(target);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    connect(open,&QPushButton::clicked,this,&Qhs::openImg);
    connect(draw,&QPushButton::clicked,this,&Qhs::markPos);
    connect(exit,&QPushButton::clicked,this,&Qhs::closeQhs);
    setWindowTitle("Qhs");
    resize(800,600);
}

Qhs::~Qhs()
{

}

void Qhs::openImg()
{
    QString img=QFileDialog::getOpenFileName(this,"Open Image","","Images (All files(*.*);;*.png;;*.jpg;;*.bmp)");
    QImage src(img);
    QPixmap add=QPixmap::fromImage(src);
    scene->addPixmap(add.scaled(view->size(),Qt::IgnoreAspectRatio));
    view->setImage(src);
    view->update();
}

void Qhs::markPos()
{
    int circleX = 100;
    int circleY = 100;
    int circleDiameter = 50;
    target = scene->addEllipse(circleX, circleY, circleDiameter, circleDiameter, QPen(Qt::red), QBrush(Qt::transparent));
    target->setZValue(1);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [this, circleDiameter]() {
        target->moveBy(1, 1);
    });
    timer->start(100);
}
void Qhs::closeQhs()
{
    QCoreApplication::quit();
}

Draw::Draw(QWidget *parent) : QGraphicsView(parent)
{

}

void Draw::setImage(const QImage &img)
{
    image = img;
}

void Draw::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);
    if (!image.isNull()) {
        QPainter painter(viewport());
        painter.drawImage(QPoint(0, 0), image.scaled(this->size()/5, Qt::KeepAspectRatio));
        drawStar(painter, 150, 150, 50 * 2);
    }
}

void Draw::drawStar(QPainter &painter, int centerX, int centerY, int size)
{
    QPolygonF starPolygon;
    starPolygon << QPointF(centerX, centerY - size)
                << QPointF(centerX + size * 0.3, centerY - size * 0.3)
                << QPointF(centerX + size, centerY - size * 0.3)
                << QPointF(centerX + size * 0.5, centerY + size * 0.1)
                << QPointF(centerX + size * 0.6, centerY + size)
                << QPointF(centerX, centerY + size * 0.4)
                << QPointF(centerX - size * 0.6, centerY + size)
                << QPointF(centerX - size * 0.5, centerY + size * 0.1)
                << QPointF(centerX - size, centerY - size * 0.3)
                << QPointF(centerX - size * 0.3, centerY - size * 0.3);

    painter.setPen(Qt::yellow);
    painter.setBrush(Qt::yellow);
    painter.drawPolygon(starPolygon);
}

void Draw::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
        scale(1.1, 1.1);
        scaleFactor *= 1.1;
    } else {
        scale(0.9, 0.9);
        scaleFactor *= 0.9;
    }
    update();
    event->accept();
}
