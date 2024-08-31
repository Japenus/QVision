#include "qcapture.h"
QCapture::QCapture(QWidget *parent): QMainWindow(parent)
{
    view = new Draw;
    main=new QVBoxLayout;
    container=new QWidget;
    scene=new QGraphicsScene;
    exit=new QPushButton("Exit");
    detect=new QPushButton("Start");
    main->addWidget(view);
    main->addWidget(exit);
    main->addWidget(detect);
    setCentralWidget(container);
    container->setLayout(main);
    view->setDragMode(QGraphicsView::ScrollHandDrag);
    connect(detect,&QPushButton::clicked,this,&QCapture::beginDetect);
    connect(exit,&QPushButton::clicked,this,&QCapture::closeDlib);
    setWindowTitle("Dlib");
    resize(800,600);
}

void QCapture::beginDetect()
{
    cap.open(0);
    if (!cap.isOpened()) {
        QMessageBox::warning(nullptr,"警告","无法打开摄像头!");
        return;
    }
    dlib::frontal_face_detector detector = dlib::get_frontal_face_detector();
    dlib::shape_predictor predictor;
    dlib::deserialize("shape_predictor_68_face_landmarks.dat") >> predictor;
    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;
        dlib::cv_image<dlib::bgr_pixel> img(frame);
        vector<dlib::rectangle> faces = detector(img);
        for (const dlib::rectangle &face : faces) {
            dlib::full_object_detection s=predictor(img,face);
            for (uint i = 0; i < s.num_parts(); i++) {
                int x = s.part(i).x();
                int y = s.part(i).y();
                circle(frame, Point(x, y), 2, Scalar(0, 255, 0), FILLED);
            }
            rectangle(frame, Point(face.left(), face.top()), Point(face.right(), face.bottom()), Scalar(255,0,0), 2);
        }
        QImage qimg(frame.data, frame.cols, frame.rows, frame.step[0], QImage::Format_BGR888);
        QPixmap pixmap = QPixmap::fromImage(qimg);
        scene->clear();
        scene->addPixmap(pixmap);
        view->setScene(scene);
        view->show();
        if (waitKey(1) == 27) {
            break;
        }
    }
    cap.release();
    destroyAllWindows();
}

void QCapture::closeDlib()
{
    if(cap.isOpened()) cap.release();
    QCoreApplication::quit();
}

Draw::Draw(QWidget *parent) : QGraphicsView(parent)
{
    rectItem=nullptr;
}

void Draw::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        startPoint = mapToScene(event->pos());
        rectItem = new QGraphicsRectItem(QRectF(startPoint, QSizeF()));
        rectItem->setPen(QPen(Qt::green, 2));
        scene()->addItem(rectItem);
    }
}

void Draw::mouseMoveEvent(QMouseEvent *event)
{
    if (rectItem) {
        QPointF currentPoint = mapToScene(event->pos());
        QRectF rect(startPoint, currentPoint);
        rectItem->setRect(rect.normalized());
    }
}

void Draw::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && rectItem) {
        rectItem = nullptr;
    }
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

QCapture::~QCapture()
{
    cap.release();
    delete view;
    delete main;
    delete exit;
    delete scene;
    delete detect;
    delete container;
}
