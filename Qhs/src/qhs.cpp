#include "qhs.h"

Qhs::Qhs(QWidget *parent): QMainWindow(parent)
{
    con=new QWidget;
    main=new QVBoxLayout;
    view = new Draw;
    scene=new QGraphicsScene;
    open=new QPushButton("Start");
    main->addWidget(view);
    main->addWidget(open);
    setCentralWidget(con);
    con->setLayout(main);
    view->show();
    view->setScene(scene);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    connect(open,&QPushButton::clicked,this,&Qhs::start);
    setWindowTitle("Qhs");
    resize(800,600);
}

Qhs::~Qhs()
{

}

void Qhs::start()
{
    QString img=QFileDialog::getOpenFileName(this,"Open Image","","Images (All files(*.*);;*.png;;*.jpg;;*.bmp)");
    QImage src(img);
    QPixmap add=QPixmap::fromImage(src);
    scene->addPixmap(add.scaled(view->size(),Qt::IgnoreAspectRatio));
}

Draw::Draw(QWidget *parent) : QGraphicsView(parent)
{

}

void Draw::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
        scale(1.1, 1.1);
    } else {
        scale(0.9, 0.9);
    }
    event->accept();
}
