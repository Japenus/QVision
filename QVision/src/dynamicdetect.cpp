#include "dynamicdetect.h"
void DynamicDetect::detectLine()
{
    VideoCapture capture(0);
    namedWindow("Detect Lines",0);
    while (true)
    {
        Mat frame;
        int key = waitKey(10);
        vector<Vec2f> lines;
        capture.read(frame);
        lines=IAM.DynamicDetectLine(frame);
        for (int i = 0; i < lines.size(); i++)
        {
            float rho = lines[i][0];
            float theta = lines[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a * rho, y0 = b * rho;
            pt1.x = cvRound(x0 + 1000 * (-b));
            pt1.y = cvRound(y0 + 1000 * (a));
            pt2.x = cvRound(x0 - 1000 * (-b));
            pt2.y = cvRound(y0 - 1000 * (a));
            line(frame, pt1, pt2, QVGreen, 2, LINE_AA);
        }
        imshow("Detect Lines",frame);
        if(key ==27)
        {
            break;
        }
        else if (key != 27 && key!= -1)
        {
            QMessageBox::information(nullptr,QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}

void DynamicDetect::detectCircle()
{
    VideoCapture capture(0);
    namedWindow("Detect Circle",0);
    while (true)
    {
        Mat frame,gray;
        int key = waitKey(10);
        vector<Vec3f> circles;
        capture.read(frame);
        circles=IAM.DynamicDetectcir(frame);
        for (int i = 0; i < circles.size(); i++)
        {
            Vec3i c = circles[i];
            int radius = c[2];
            Point center = Point(c[0], c[1]);
            circle(frame, center, 5, QVRed, -1, 8,0);
            circle(frame, center, radius, QVGreen, 3, 8,0);
        }
        imshow("Detect Circle",frame);
        if(key ==27)
        {
            break;
        }
        else if (key != 27 && key!= -1)
        {
            QMessageBox::information(nullptr,QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}

void DynamicDetect::detectEllpise()
{
    VideoCapture capture(0);
    namedWindow("Detect Ellpise",0);
    while (true)
    {
        Mat frame,gray;
        int key = waitKey(10);
        vector<Vec3f> ellpises;
        capture.read(frame);
        ellpises=IAM.DynamicDetectEll(frame);
        for (size_t i = 0; i < ellpises.size(); i++)
        {
            Point center(cvRound(ellpises[i][0]), cvRound(ellpises[i][1]));
            int radius = cvRound(ellpises[i][2]);
            circle(frame, center, radius, QVGreen, 2, LINE_AA);
        }
        imshow("Detect Ellpise",frame);
        if(key ==27)
        {
            break;
        }
        else if (key != 27 && key!= -1)
        {
            QMessageBox::information(nullptr,QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}

void DynamicDetect::detectTriangle()
{
    VideoCapture capture(0);
    namedWindow("Detect Triangles",0);
    while (true)
    {
        Mat frame,gray;
        int key = waitKey(10);
        capture.read(frame);
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, Size(9, 9), 2, 2);
        vector<vector<Point>> contours;
        findContours(gray, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        for (size_t i = 0; i < contours.size(); i++)
        {
            vector<Point> approx;
            approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);
            if (approx.size() == 3)
            {
                drawContours(frame, vector<vector<Point>>{approx}, -1, Scalar(0, 255, 0), 2);
            }
        }
        imshow("Detect Triangles",frame);
        if(key ==27)
        {
            break;
        }
        else if (key != 27 && key!= -1)
        {
            QMessageBox::information(nullptr,QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}

double DynamicDetect::angle(Point pt1, Point pt2, Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1 * dx2 + dy1 * dy2) / sqrt((dx1 * dx1 + dy1 * dy1) * (dx2 * dx2 + dy2 * dy2) + 1e-10);
}

void DynamicDetect::detectSquare()
{
    VideoCapture capture(0);
    namedWindow("Detect Square", 0);
    while (true)
    {
        Mat frame, gray;
        int key = waitKey(10);
        capture.read(frame);
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, gray, Size(9, 9), 2, 2);
        vector<vector<Point>> contours;
        findContours(gray, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        for (size_t i = 0; i < contours.size(); i++)
        {
            vector<Point> approx;
            approxPolyDP(contours[i], approx, arcLength(contours[i], true) * 0.02, true);
            if (approx.size() == 4)
            {
                double maxCosine = 0;
                for (int j = 2; j < 5; j++)
                {
                    double cosine = fabs(angle(approx[j % 4], approx[j - 2], approx[j - 1]));
                    maxCosine = MAX(maxCosine, cosine);
                }
                if (maxCosine < 0.3)
                {
                    drawContours(frame, vector<vector<Point>>{approx}, -1, Scalar(0, 255, 0), 2);
                }
            }
        }
        imshow("Detect Square", frame);
        if (key == 27)
        {
            break;
        }
        else if (key != 27 && key != -1)
        {
            QMessageBox::information(nullptr, QString("提示"), QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}

void DynamicDetect::detectCharacter()
{
    VideoCapture capture(0);
    if(!capture.isOpened())
    {
        QMessageBox::information(nullptr,QString("提示"),QString("无法打开摄像头!"));
        return;
    }
    namedWindow("Detect Char",0);
    while (true){
        Mat frame,gray;
        int key = waitKey(10);
        capture.read(frame);
        gray = Process.GrayTransform(frame);
        QString result = tool.CharRecognize(frame);
        // qDebug()<<"识别结果:"<< result;
        QMessageBox::information(nullptr,"提示","识别结果:"+result);
        imshow("Detect Char",frame);
        if(key ==27){
            break;
        }else if (key != 27 && key!=-1){
            QMessageBox::information(nullptr, QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}

void DynamicDetect::detectEye()
{
    VideoCapture capture(0);
    CascadeClassifier faceCascade;
    if(!faceCascade.load("haarcascade_eye.xml"))
    {
        QMessageBox::information(nullptr,QString("提示"),QString("无法加载检测器!"));
        return;
    }
    if(!capture.isOpened()){
        QMessageBox::information(nullptr,QString("提示"),QString("无法打开摄像头!"));
        return;
    }
    namedWindow("Detect Eyes",0);
    while (true)
    {
        Mat frame , gray;
        int key = waitKey(10);
        vector<Rect> eyes;
        capture.read(frame);
        gray = Process.GrayTransform(frame);
        faceCascade.detectMultiScale(gray, eyes,1.1,3,0,Size(30,30));
        for (int i = 0; i < eyes.size(); i++)
        {
            rectangle(frame,eyes[i], QVGreen,2);
            putText(frame,"eye",Point(eyes[i].x,eyes[i].y),16,0.8,QVGreen,2,LINE_AA);
        }
        imshow("Detect Eyes",frame);
        if(key ==27)
        {
            break;
        }
        else if (key != 27 && key!= -1)
        {
            QMessageBox::information(nullptr,QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}


void DynamicDetect::detectFace()
{
    VideoCapture capture(0);
    CascadeClassifier faceCascade;
    if(!faceCascade.load("haarcascade_frontalface_alt.xml"))
    {
        QMessageBox::information(nullptr,QString("提示"),QString("无法加载人脸检测器!"));
        return;
    }
    if(!capture.isOpened()){
        QMessageBox::information(nullptr,QString("提示"),QString("无法打开摄像头!"));
        return;
    }
    namedWindow("Detect Face",0);
    while (true)
    {
        Mat frame , gray;
        int key = waitKey(10);
        vector<Rect> faces;
        capture.read(frame);
        gray = Process.GrayTransform(frame);
        faceCascade.detectMultiScale(gray, faces,1.1,3,0,Size(30,30));
        for (int i = 0; i < faces.size(); i++)
        {
            rectangle(frame,faces[i], QVGreen,2);
        }
        imshow("Detect Face",frame);
        if(key ==27)
        {
            break;
        }
        else if (key != 27 && key!= -1)
        {
            QMessageBox::information(nullptr,QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}


void DynamicDetect::detectByUserCreateModel(const QString &modelPath)
{
    VideoCapture capture(0);
    CascadeClassifier usermodel;
    if(!usermodel.load(modelPath.toStdString()))
    {
        QMessageBox::information(nullptr,QString("提示"),QString("导入模型失败!"));
        return;
    }
    if(!capture.isOpened()){
        QMessageBox::information(nullptr,QString("提示"),QString("无法打开摄像头!"));
        return;
    }
    namedWindow("User Model",0);
    while (true)
    {
        Mat frame,gray;
        int key = waitKey(10);
        vector<Rect> shapes;
        capture.read(frame);
        gray = Process.GrayTransform(frame);
        usermodel.detectMultiScale(gray,shapes,1.1,3,0,Size(30,30));
        for (int i = 0; i < shapes.size(); i++)
        {
            rectangle(frame,shapes[i], QVGreen,2);
        }
        imshow("User Model",frame);
        if(key ==27)
        {
            break;
        }
        else if (key != 27 && key!= -1)
        {
            QMessageBox::information(nullptr,QString("提示"),QString("按ESC退出"));
        }
    }
    capture.release();
    destroyAllWindows();
}
