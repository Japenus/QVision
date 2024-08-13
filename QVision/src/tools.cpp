#include "tools.h"
int rotated=0;
bool isMove= false;
Point temp1(-1,-1),temp2(-1,-1);
Point p1(-1,-1),p2(-1,-1);
Rect Box(temp1,temp2);
struct RequestResult
{
    QString url;
    bool success;
    bool isFailed;
    int statusCode;
    QByteArray data;
};
struct DataStruct
{
    Mat img;
    Scalar color;
    int size;
    int num;
};
Mat Tools::ShowHistogram(Mat src)
{
    Mat hist,gray;
    cvtColor(src,gray,COLOR_BGR2GRAY);
    int val = 256;
    float ranges[] = {0,256};
    const float* histRanges={ranges};
    calcHist(&gray,1,0,Mat(),hist,1,&val,&histRanges,true,false);
    int h = 300;
    int w = 512;
    int x = w/val;
    Mat res(h,w,CV_8UC3,QVBlack);
    normalize(hist, hist,0,h,NORM_MINMAX,-1,Mat());
    for (int i = 1; i < val; i++)
    {
        line(res,Point((i - 1) * x,h - cvRound(hist.at<float>(i - 1))),Point((i)*x,h-cvRound(hist.at<float>(i))),Scalar(0,255,0),2,8,0);
    }
    namedWindow("Histogram of Image",0);
    imshow("Histogram of Image", res);
    waitKey(0);
    return res;
}


Mat Tools::FixThreshold(Mat img, int val)
{
    Mat res(img.size(), CV_8UC1);
    for(int i = 0; i < img.rows; i++){
        for(int j = 0; j< img.cols; j++){
            Vec3b pixel = img.at<Vec3b>(i, j);
            int grayValue = (pixel[0] + pixel[1] + pixel[2])/3;
            if (grayValue >= val) {
                res.at<uchar>(i,j) = 255;
            }
            else
            {
                res.at<uchar>(i,j) = 0;
            }
        }
    }
    return res;
}


Mat Tools::AdaptThreshold(Mat src ,int block,double C)
{
    Mat gray=process.GrayTransform(src);
    Mat res(src.size(), CV_8UC1);
    adaptiveThreshold(gray,res,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,block,C);
    return res;
}


Mat Tools::RegionGrow(Mat& src, Point seedPoint, int threshold, Mat& visited)
{
    Mat res = Mat::zeros(src.size(), CV_8U);
    vector<Point> stack;
    stack.push_back(seedPoint);
    while (!stack.empty()) {
        Point currentPoint = stack.back();
        stack.pop_back();
        res.at<uchar>(currentPoint) = 255;
        vector<Point> neighbors = {
            Point(currentPoint.x + 1, currentPoint.y),Point(currentPoint.x - 1, currentPoint.y),
            Point(currentPoint.x, currentPoint.y + 1),Point(currentPoint.x, currentPoint.y - 1)
        };
        for (const auto& neighbor : neighbors) {
            if (neighbor.x >= 0 && neighbor.x < src.cols &&
                neighbor.y >= 0 && neighbor.y < src.rows &&
                visited.at<uchar>(neighbor) == 0 &&
                abs(static_cast<int>(src.at<uchar>(currentPoint)) - static_cast<int>(src.at<uchar>(neighbor))) < threshold) {
                stack.push_back(neighbor);
                visited.at<uchar>(neighbor) = 1;
            }
        }
    }
    return res;
}
Mat Tools::EdgeSobel(Mat src)
{
    Mat gray=process.GrayTransform(src);
    Mat X,Y,Xa,Ya,res;
    Sobel(gray,X,CV_16S,1,0);
    Sobel(gray,Y,CV_16S,0,1);
    convertScaleAbs(X,Xa);
    convertScaleAbs(Y,Ya);
    addWeighted(Xa, 0.5, Ya,0.5,0,res);
    return res;
}
Mat Tools::EdgeCanny(Mat src)
{
    Mat res, gray=process.GrayTransform(src);
    Canny(gray, res, 150, 100);
    return res;
}

Mat Tools::EdgeCanny(Mat src,int low,int high)
{
    Mat res,gray=process.GrayTransform(src);
    Canny(gray,res,low,high);
    return res;
}



Mat Tools::Edgescharr(Mat src)
{
    Mat res;
    GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);
    Scharr(src, res, CV_16S,1, 0);
    convertScaleAbs(res, res);
    res=ThresholdProcess(res,30);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    morphologyEx(res,res,MORPH_CLOSE,kernel);
    return res;
}
Mat Tools::ThresholdProcess(Mat src,int val,int type)
{
    Mat dst=process.GrayTransform(src);
    threshold(src, dst, val, 255, type);
    return dst;
}
Mat Tools::ThresholdProcess(Mat src,int val)
{
    Mat dst=process.GrayTransform(src);
    threshold(src,dst,val,255,THRESH_BINARY);
    return dst;
}
Mat Tools::ThresholdProcess(Mat src,int val,int maxVal,int type)
{
    Mat dst;
    threshold(src,dst, val, maxVal, type);
    return dst;
}
Mat Tools::ShowOutline(Mat src,int val)
{
    Mat gray,bin;
    gray = process.GrayTransform(src);
    bin = ThresholdProcess(gray,val,255,0);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(bin,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE);//CHAIN_APPROX_SIMp1E
    for(int i = 0; i < contours.size(); i++)
    {
        drawContours(src, contours,i,QVPurple,2,LINE_8,hierarchy);
    }
    return src;
}


int Tools::Statistic(Mat img, int pixVal)
{
    Mat temp,gray=process.GrayTransform(img);
    compare(gray,pixVal,temp,CMP_EQ);
    int count = countNonZero(temp);
    return count;
}

double Tools::CalcDist(int X1, int Y1, int X2, int Y2)
{
    Point p1(X1,Y1);
    Point p2(X2,Y2);
    double distance=norm(p2 - p1);
    return distance;
}

static void CoverArea(int e, int x,int y, int flags, void* recData)
{
    Mat* src = (Mat*)recData;
    if (e == EVENT_LBUTTONDOWN){
    isMove = true;
    p1 = Point(x,y);
    }
    else if (e == EVENT_MOUSEWHEEL){
        QMessageBox::information(nullptr,"提示","右键保存此区域");
    }
    else if (e == EVENT_MOUSEMOVE){
    if (isMove){
            p2 = Point(x,y);
            Mat s = src->clone();
            rectangle(s,p1,p2, QVGreen,1);
            rectangle(s,p1,p2, QVGreen,-1);
            namedWindow("Area Cover",0);
            imshow("Area Cover",s);
        }
    }
    else if (e == EVENT_LBUTTONUP)
    {
        isMove = false;
    }
    else if (e == EVENT_RBUTTONUP)
    {
        if(p1 != Point(-1,-1) && p2 != Point(-1,-1))
        {
            Rect Area(p1,p2);
            Mat curArea = (*src)(Area);
            namedWindow("Area Cover",0);
            imshow("Area Cover", curArea);
            imwrite("CoverArea.png", curArea);
        }
    }
}

static void fillEvent(int e, int x, int y, int flags, void* recData)
{
    Mat res;
    Scalar fillColor;
    static int clickCount = 0;
    static vector<Point> shapes;
    vector<vector<Point>> VArea;
    DataStruct* data = static_cast<DataStruct*>(recData);
    res=data->img;
    fillColor=data->color;
    if(e== EVENT_LBUTTONUP && clickCount < data->num)
    {
        Point p(x,y);
        shapes.push_back(p);
        clickCount++;
        for (int i = 0; i < shapes.size(); i++)
        {
            circle(res,shapes[i],data->size,fillColor,-1);
        }
        imshow("Mark Area",res);
    }
    if(clickCount == data->num && e == EVENT_RBUTTONUP)
    {
        VArea.push_back(shapes);
        polylines(res,VArea,true,fillColor,2,LINE_8);
        imshow("Mark Area", res);
        imwrite("FillArea.png", res);
        shapes.clear();
        VArea.clear();
        clickCount = 0;
    }
}

Mat Tools::AreaFill(Mat whichImg,const Scalar &fillColor,int psize,int pnum)
{
    DataStruct DS;
    DS.size = psize;
    DS.num = pnum;
    DS.img = whichImg;
    DS.color = fillColor;
    namedWindow("Mark Area",0);
    setMouseCallback("Mark Area",fillEvent,&DS);
    cout << "Color Data: " << fillColor << endl;
    imshow("Mark Area", whichImg);
    waitKey(0);
    return whichImg;
}

Mat Tools::AreaCover(Mat img)
{
    namedWindow("Area Cover",0);
    setMouseCallback("Area Cover",CoverArea,&img);
    imshow("Area Cover",img);
    waitKey(0);
    return img;
}

Mat Tools::PersTransform(Mat src,Mat target)
{
    Mat hMatrix,transformed,output,Hmatrix;
    vector<DMatch> best;
    vector<Point2f> points1, points2;
    Ptr<Feature2D> sift = SIFT::create();
    vector<KeyPoint> kp1,kp2;
    Mat deSrc,desTar;
    sift->detectAndCompute(src,noArray(), kp1, deSrc);
    sift->detectAndCompute(target,noArray(), kp2,desTar);
    drawMatches(src,kp1, target,kp2, best, output);
    for (const auto& kp : kp1)
    {
        points1.push_back(kp.pt);
    }
    for(const auto& kp : kp2)
    {
        points2.push_back(kp.pt) ;
    }
    try
    {
       hMatrix=findHomography(points2, points1,RANSAC);
    }
    catch(const exception& e)
    {
        QString eMsg ="无法计算H矩阵!\n";
        eMsg += e.what();
        QMessageBox::critical(nullptr,"错误",eMsg,QMessageBox::Ok);
        return Mat();
    }
    warpPerspective(target, transformed,hMatrix,src.size());
    waitKey(0);
    return transformed;
}
static int base = 0;
static void func(int e,int x,int y,int flags, void* userdata)
{
    static Mat image=*(Mat*)userdata,zoom;
    static bool cutting= false;
    static Point LT(-1,-1),RB(-1, -1);
    static int cutNumber=1;
    int val,w=image.cols,h=image.rows;
    if (e == EVENT_LBUTTONDOWN){
        if(!cutting){
            cutting = true;
            LT = Point(x,y);
        }
    }else if (e==EVENT_MOUSEWHEEL){
        val=getMouseWheelDelta(flags)/10;
        if(val>0){
            ++base;
            resize(image,zoom,Size(h*val*base,w*val*base),0,0,INTER_LINEAR);
            w*=val*base;h*=val*base;
            imshow("Bigger", zoom);
        }else{
            ++base;
            val=abs(val);
            resize(image,zoom,Size(h/(val*base),w/(val*base)),0,0,INTER_LINEAR);
            w/=val*base;h/=val*base;
            imshow("Bigger", zoom);
        }
    }else if (e == EVENT_MOUSEMOVE){
        if(cutting){
            RB = Point(x,y);
            Mat s = image.clone();
            Rect area(LT,RB);
            rectangle(s,area,QVGreen,3);
            imshow("Bigger", s);
        }
    }else if (e== EVENT_LBUTTONUP){
        cutting = false;
        Rect Area(LT,RB);
        Tools::ins().ShowOutline(image(Area),150);
    }else if (e == EVENT_RBUTTONUP){
        if (LT != Point(-1,-1) && RB != Point(-1,-1)){
            Rect Area(LT,RB);
            Box=Area;
            Mat curArea = image(Area);
            QMessageBox::information(nullptr,"提示",QString("截图已保存:cutArea%1.jpg").arg(cutNumber));
            imwrite("ScreenShot" + to_string(cutNumber) + ".jpg",curArea);
            cutNumber++;
            waitKey(0);
        }
    }
}

static void mouseErase(int e,int x,int y,int f,void *data)
{
    Mat* im=(Mat*)data;
    DataStruct* dts=static_cast<DataStruct*>(data);
    Point pt(x,y);
    if(e==EVENT_LBUTTONUP||!(f&EVENT_FLAG_LBUTTON)) temp1=Point(-1,-1);
    else if(e==EVENT_LBUTTONDOWN) temp1=Point(x,y);
    else if(e==EVENT_MOUSEMOVE&&(f&EVENT_FLAG_LBUTTON)){
        if(temp1.x<0) temp1=pt;
        line(*im,temp1,pt,dts->color,dts->size,LINE_AA,0);
        temp1=pt;
        imshow("Erase",*im);
    }
    if(e==EVENT_RBUTTONUP){
        imwrite("Erased.png",*im);
        QMessageBox::information(nullptr,"提示",QString("擦除区域已保存"));
    }
}


Mat Tools::EraseArea(Mat src,Scalar c,int s)
{
    DataStruct ds;
    ds.img=src;
    ds.color=c;
    ds.size=s;
    namedWindow("Erase",0);
    setMouseCallback("Erase",mouseErase,&ds);
    imshow("Erase",src);
    waitKey(0);
    return src;
}

void Tools::MakeBig(Mat src)
{
    if (!src.empty()){
        namedWindow("Bigger",0);
        imshow("Bigger", src);
        setMouseCallback("Bigger",func,&src);
        waitKey(0);
    }
}

Rect Tools::GetCoordinate()
{
    Rect whereTemp;
    whereTemp = Box;
    return whereTemp;
}

void Tools::SetHoughParas(Ptr<GeneralizedHoughBallard> ballard,double a,int b,double c,int d,int e,int f,int g)
{
    ballard->setMinDist(a);
    ballard->setLevels(b);
    ballard->setDp(c);
    ballard->setMaxBufferSize(d);
    ballard->setVotesThreshold(e);
    ballard->setCannyLowThresh(f);
    ballard->setCannyHighThresh(g);
}

void Tools::SetHoughParas(Ptr<GeneralizedHoughGuil> guil,double mindist, int level, double dp, double xi,
    int buffersize,int cannylow,int cannyhigh,int minangle, int maxangle, int anglestep, int anglethreshold,
    float minscale,float maxscale,double angleeplise,int scalestep,int scalethreshold,float positionthreshold)
{
    guil->setMinDist(mindist);
    guil->setLevels(level);
    guil->setDp(dp);
    guil->setXi(xi);

    guil->setMaxBufferSize(buffersize);
    guil->setCannyLowThresh(cannylow);
    guil->setCannyHighThresh(cannyhigh);
    guil->setMinAngle(minangle);

    guil->setMaxAngle(maxangle);
    guil->setAngleStep(anglestep);
    guil->setAngleThresh(anglethreshold);
    guil->setMinScale(minscale);

    guil->setMaxScale(maxscale);
    guil->setAngleEpsilon(angleeplise);
    guil->setScaleStep(scalestep);
    guil->setScaleThresh(scalethreshold);
    guil->setPosThresh(positionthreshold);
}

double Tools::CalcIOU(const Rect& rectA, const Rect& rectB)
{
    int areaA= rectA.width * rectA.height;
    int areaB = rectB.width * rectB.height;
    if (areaA<= 0||areaB <= 0) return 0.0;
    int intersectionWidth = max(0,min(rectA.x + rectA.width, rectB.x + rectB.width) - max(rectA.x,rectB.x));
    int intersectionHeight = max(0,min(rectA.y + rectA.height, rectB.y + rectB.height)- max(rectA.y,rectB.y));
    int intersectionArea = intersectionWidth * intersectionHeight;
    return double(intersectionArea)/(areaA + areaB - intersectionArea);
}

vector<Rect> Tools::NonMaxSuppress(const vector<Rect>& boxes, const vector<double>& scores,double threshold)
{
    vector<int> indices(boxes.size());
    iota(indices.begin(), indices.end(), 0) ;
    sort(indices.begin(), indices.end(), [&scores](int i, int j){return scores[i] > scores[j];});
    vector<Rect> nmsBoxes;
    while (!indices.empty())
    {
        int curr= indices.front();
        nmsBoxes.push_back(boxes[curr]);
        indices.erase(indices.begin()) ;
        indices.erase(remove_if(indices.begin(),indices.end(),
        [this,&boxes, &curr,threshold](int i)
        {
            return CalcIOU(boxes[curr], boxes[i])>threshold;
        }), indices.end());
    }
    return nmsBoxes;
}

vector<pair<Rect, double>> Tools::TotalArea(const Mat& src, const Mat& temp,double step,double min, double max,int threshold)
{
    Mat scaledTempl;
    Mat result;
    vector<pair<Rect,double>> matchRes;
    for(double scale=min; scale <= max; scale += step)
    {
        resize(temp, scaledTempl, Size(), scale, scale);
        matchTemplate(src,scaledTempl, result,TM_CCORR_NORMED);
        normalize(result, result,0,1,NORM_MINMAX);
        for (int y = 0; y < result.rows; y++)
        {
            for (int x = 0; x < result.cols; x++)
            {
                double score = result.at<float>(y, x);
                if (score>threshold)
                {
                    Rect rect(x,y,scaledTempl.cols,scaledTempl.rows);
                    matchRes.push_back(make_pair(rect,score));
                }
            }
        }
    }
    return matchRes;
}

void Tools::DrawRotRect(Mat whichimg,const Point2f& rCenter,const Size2f& rSize,float rAngle, Scalar rColor,int rwidth)
{
    RotatedRect rEct(rCenter,rSize,rAngle);
    Point2f v[4];
    rEct.points(v);
    for(int i=0; i < 4; i++)
    {
        line(whichimg, v[i], v[(i + 1) % 4], rColor, rwidth,LINE_8);
    }
}

Mat Tools::RotateScale(Mat src, double angle, double scale)
{
    Mat res;
    Point2f center(src.cols/2,src.rows/2);
    Mat rotMat=getRotationMatrix2D(center,angle,scale);
    warpAffine(src,res,rotMat,Size(src.cols,src.rows),INTER_LINEAR,BORDER_CONSTANT,QVBlack);
    imwrite("Rotated"+to_string(rotated) + ".png", res);
    rotated++;
    waitKey(0);
    return res;
}

int Tools::Pyramid(Mat src)
{
    vector<Mat> Pyramid;
    buildPyramid(src, Pyramid,4);
    for (int i = 0; i < Pyramid.size(); i++)
    {
        imshow("Image Pyramid", Pyramid[i]);
        imwrite("Pyramid" + to_string(i) + ".png",Pyramid[i]);
        waitKey(0);
    }
    return 0;
}

void Tools::recognizeFace()
{
    // VideoCapture cap(0);
    // if (!cap.isOpened()) {
    //     QMessageBox::information(this,tr("提示"),tr("无法打开摄像头"));
    //     return ;
    // }
    // while (true) {
    //     Mat frame;
    //     cap >> frame;
    //     detector = dlib::get_frontal_face_detector();
    //     dlib::deserialize("shape_predictor_68_face_landmarks.dat") >> predictor;

    //     dlib::cv_image<dlib::bgr_pixel> img(frame);
    //     vector<dlib::rectangle> faces = detector(img);

    //     for (dlib::rectangle face : faces) {
    //         rectangle(frame, Point(face.left(), face.top()), Point(face.right(), face.bottom()), QVGreen, 2);
    //     }

    //     namedWindow("Face Recognition",0);
    //     imshow("Face Recognition", frame);
    //     if (waitKey(1) == 27) {
    //         break;
    //     }
    // }
}

Scalar Tools::PickColor()
{
    QColor defaultColor(Qt::black);
    int r=defaultColor.red();
    int g=defaultColor.green();
    int b=defaultColor.blue();
    Scalar Default(b,g,r);
    QColor selectColor=QColorDialog::getColor(defaultColor,nullptr,tr("Choose Color"));
    if(selectColor.isValid()){
        r=selectColor.red();
        g=selectColor.green();
        b=selectColor.blue();
        Scalar res(b,g,r);
        return res;
    }else{
        return Default;
    }
}
#include<QThread>
QString Tools::NetSpyder(QString &url,QProgressBar *bar,QElapsedTimer *t)
{
    // http://dlib.net/
    QUrl link(url);
    QEventLoop loop;
    RequestResult RR;
    QString htmlcode;
    QNetworkRequest request(link);
    QRegularExpression regExp("<img src=\"([^\"]+)\"");
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::downloadProgress, [=](qint64 rec,qint64 total){
        bar->setValue((rec*100)/total);
        double speed=rec/(t->elapsed()/1000.0);
        qInfo()<<speed;
    });
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
    RR.url=url;
    RR.statusCode=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    RR.success=(reply->error()==QNetworkReply::NoError);
    RR.isFailed=(reply->error()!=QNetworkReply::NoError);
    if (RR.success) {
        RR.data=reply->readAll();
        htmlcode=QString(RR.data);
        MatchImgPath(regExp,htmlcode);
        reply->deleteLater();
        QThread::msleep(2000);
        bar->setValue(0);
        manager->deleteLater();
        return htmlcode;
    }
    qInfo()<<"success:"<<RR.success<<"RR.isFailed:"<<RR.isFailed;
    if(RR.isFailed){
        return htmlcode = "Error: " + reply->errorString();
    }
}

void Tools::MatchImgPath(QRegularExpression re,QString context)
{
    QStringList res;
    QRegularExpressionMatchIterator reslist=re.globalMatch(context);
    while (reslist.hasNext()) {
        QRegularExpressionMatch match=reslist.next();
        res.append(match.captured(1));
    }
    if(!res.isEmpty()){
        QFile file("ImgPath.txt");
        file.open(QIODevice::WriteOnly|QIODevice::Text);
        QTextStream out(&file);
        for(auto &match:res) {
            out<<match<<"\n";
        }
        file.close();
    }else{
        QMessageBox::information(nullptr,tr("提示"),tr("当前页面未发现图片资源!"));
        return;
    }
}

QString Tools::CharRecognize(QString imgPath)
{
    TessBaseAPI *ocr = new TessBaseAPI();
    ocr->Init(NULL, "eng", OEM_LSTM_ONLY);
    ocr->SetPageSegMode(PSM_AUTO);
    Mat im = imread(imgPath.toStdString(), IMREAD_COLOR);
    ocr->SetImage(im.data, im.cols, im.rows, 3, im.step);
    res=ocr->GetUTF8Text();
    ocr->End();
    if(!res.isEmpty()){
        return res;
    }else{
        return "输入图像中没有字符!";
    }
}

QString Tools::CharRecognize(Mat img)
{
    TessBaseAPI *ocr = new TessBaseAPI();
    ocr->Init(NULL, "eng", OEM_LSTM_ONLY);
    ocr->SetPageSegMode(PSM_AUTO);
    ocr->SetImage(img.data, img.cols, img.rows, 3, img.step);
    res=ocr->GetUTF8Text();
    ocr->End();
    if(!res.isEmpty()){
        return res;
    }else{
        return "输入图像中没有字符!";
    }
}

QString Tools::recognizeQRCode(Mat img)
{
    Mat res,mask;
    QRCodeDetector qrDecoder;
    string data = qrDecoder.detectAndDecode(img, mask, res);
    if(data.length()>0){
        return QString::fromStdString(data);
    }else{
        return "输入图像中未检测到二维码！";
    }

}

// #include<zbar.h>
// using namespace zbar;

struct barCodeData{
    QString type;
    QString data;
    QVector <QPoint> pos;
};

QString Tools::recognizeBarCode(Mat img)
{
    QVector<barCodeData> bcd;

    // ImageScanner scanner;

    // vector<decodedObject> decodedObjects;
    // ImageScanner scanner;
    // scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
    // Mat imGray;
    // cvtColor(img, imGray,COLOR_BGR2GRAY);
    // Image image(img.cols, img.rows, "Y800", (uchar *)imGray.data, img.cols * img.rows);
    // int n = scanner.scan(image);
    // for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
    // {
    //     decodedObject obj;
    //     obj.type = symbol->get_type_name();
    //     obj.data = symbol->get_data();
    //     cout << "Type : " << obj.type << endl;
    //     cout << "Data : " << obj.data << endl << endl;
    //     for(int i = 0; i< symbol->get_location_size(); i++)
    //     {
    //         obj.location.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));
    //     }
    //     decodedObjects.push_back(obj);
    // }

    // for(int i = 0; i < decodedObjects.size(); i++)
    // {
    //     vector<Point> points = decodedObjects[i].location;
    //     vector<Point> hull;
    //     if(points.size() > 4)
    //         convexHull(points, hull);
    //     else
    //         hull = points;
    //     int n = hull.size();
    //     for(int j = 0; j < n; j++)
    //     {
    //         line(img, hull[j], hull[ (j+1) % n], Scalar(255,0,0), 3);
    //     }

    // }
    // imshow("Results", img);
    return "未实现!";
}

// operation database
QSqlDatabase Tools::SqlServer()
{
    QString info="";
    QSqlDatabase qDB = QSqlDatabase::addDatabase("QODBC");/*SQL Server*/
    QString dataSource = QString::fromLocal8Bit("Locasery");
    if(qDB.isValid()){
        qDB.setHostName("JERRYLEE");/*localhost*/
        qDB.setDatabaseName(dataSource);
        qDB.setUserName("sa");
        qDB.setPassword("Jerrylee");
    }
    if(!qDB.open())
    {
        info = qDB.lastError().text();
        QMessageBox::critical(0, QObject::tr("无法连接数据库:"), info);
    }else{
        QMessageBox::information(nullptr, tr("提示"),tr("数据库连接成功！"));
    }
    return qDB;
}


QSqlDatabase Tools::MySql()
{
    QCoreApplication::addLibraryPath("path/to/mysql/driver");
    QString info = "";
    QSqlDatabase qDB = QSqlDatabase::addDatabase("QMYSQL");/*MySQL*/
    QString hostName = "localhost";
    class QString databaseName = "mysql";
    QString userName = "root";
    QString password = "Locaserylory0621";

    qDB.setHostName(hostName);
    qDB.setDatabaseName(databaseName);
    qDB.setUserName(userName);
    qDB.setPassword(password);

    if (!qDB.open())
    {
        info = qDB.lastError().text();
        QMessageBox::critical(0, QObject::tr("无法连接数据库:"), info);
    }
    else
    {
        QMessageBox::information(nullptr, tr("提示"), tr("数据库连接成功！"));
    }
    return qDB;
}

QSqlDatabase Tools::SQLite(QString dbfile)
{
    QString info = "";
    QSqlDatabase qDB = QSqlDatabase::addDatabase("QSQLITE"); // SQLite
    qDB.setDatabaseName(dbfile);
    if (!qDB.open())
    {
        info = qDB.lastError().text();
        QMessageBox::critical(0, QObject::tr("无法连接数据库:"), info);
    }
    else
    {
        QMessageBox::information(nullptr, tr("提示"), tr("数据库连接成功！"));
    }
    return qDB;
}


QStringList Tools::GetTables(QSqlDatabase *qDB)
{
    QStringList tables;
    if (qDB->isOpen()) tables = qDB->tables();
    return tables;
}


QStringList Tools::GetTableFields(QSqlDatabase *db, const QString& tableName)
{
    QStringList fields;
    if(db->isOpen()){
        QSqlQuery query(*db);
        query.prepare("PRAGMA table_info(" + tableName + ")");
        if(query.exec()){
            while(query.next()){
                fields.append(query.value(1).toString());
            }
        } else {
            QMessageBox::warning(nullptr,tr("警告"),tr("无法获取表头数据:%s").arg(query.lastError().text()));
        }
    }
    return fields;
}

QList<QList<QString>> Tools::GetTableData(QSqlDatabase *db, const QString& tableName)
{
    QList<QList<QString>> tableData;
    if(db->isOpen()){
        QSqlQuery query(*db);
        query.prepare("SELECT * FROM " + tableName);
        if(query.exec()){
            while(query.next()){
                QList<QString> rowData;
                for(int i = 0; i < query.record().count(); i++){
                    rowData.append(query.value(i).toString());
                }
                tableData.append(rowData);
            }
        } else {
            QMessageBox::warning(nullptr,tr("警告"),tr("获取数据失败:%s").arg(query.lastError().text()));
        }
    }
    return tableData;
}


QStringList Tools::GetDataBases(QSqlDatabase *qDB)
{
    QStringList dbs;
    if(qDB->isOpen()) dbs = qDB->tables(QSql::Tables);
    return dbs;
}
