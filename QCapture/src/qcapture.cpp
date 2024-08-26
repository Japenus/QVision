#include "qcapture.h"
QCapture::QCapture(QWidget *parent): QMainWindow(parent)
{
    c=new QPushButton("click");
    QVBoxLayout *d=new QVBoxLayout;
    d->addWidget(c);
    QWidget *fd=new QWidget;
    setCentralWidget(fd);
    fd->setLayout(d);
    connect(c,&QPushButton::clicked,this,&QCapture::test);
    setWindowTitle("Dlib");
    resize(800,600);
}

void QCapture::test()
{
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        QMessageBox::warning(nullptr,"警告","无法打开摄像头!");
        return ;
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
            // rectangle(frame, Point(face.left(), face.top()), Point(face.right(), face.bottom()), Scalar(255,0,0), 2);
        }
        namedWindow("Face Feature", WINDOW_AUTOSIZE);
        imshow("Face Feature", frame);
        if (waitKey(1) == 27) {
            break;
        }
    }
    cap.release();
    destroyAllWindows();
}

QCapture::~QCapture()
{

}
