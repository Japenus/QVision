#include "ImgAlgorithm.h"
int matchRes=1;
int recongizedNum=1;
Mat ImgAlgorithm::GetFeature(Mat src)
{
    Mat res,gray = Preprocess::ins().GrayTransform(src);
    int nfeatures = 0;
    int nLayers = 4;
    double contrastThreshold = 0.04;
    double edgeThreshold = 10;
    double sigma = 1.6;
    bool preciseUpscale = true;
    Ptr<Feature2D> sift = SIFT::create(nfeatures, nLayers, contrastThreshold, edgeThreshold, sigma,preciseUpscale);
    vector<KeyPoint> keypoints;
    Mat descriptors;
    sift->detectAndCompute(gray,Mat(), keypoints, descriptors, false);
    drawKeypoints(src, keypoints, res, QVGreen);
    QMessageBox::information(nullptr,QString("提示"),QString("特征点数量: %1").arg(keypoints.size()));
    waitKey(0);
    return res;
}


Mat ImgAlgorithm::FloodFill(Mat src)
{
    Point seedPoint(50,50);
    Scalar newVal(0,255,0);
    Rect rect;
    Scalar loDiff(120,120,120);
    Scalar upDiff(20,20,20);
    int flags = 4;
    int connectivity = 4;
    int numFilled = floodFill(src, seedPoint, newVal, &rect, loDiff, upDiff, flags|connectivity<<8);
    QMessageBox::information(nullptr,QString("提示"),QString("漫水填充像素数量:%1").arg(numFilled));
    waitKey(0);
    destroyAllWindows();
    return src;
}

int ImgAlgorithm::WrapAffine(Mat src)
{
    vector<Point2f> srcPoints;
    srcPoints.push_back(Point2f(50,50));
    srcPoints.push_back(Point2f(200,50));
    srcPoints.push_back(Point2f(50,200));
    //定义目标图像上的三个点
    vector<Point2f> dstPoints;
    dstPoints.push_back(Point2f(70,100));
    dstPoints.push_back(Point2f(220,50));
    dstPoints.push_back(Point2f(150,200));
    //计算仿射变换矩阵
    Mat Matrix = getAffineTransform(srcPoints, dstPoints);
    Mat res;
    warpAffine(src,res, Matrix, src.size());
    waitKey(0);
    destroyAllWindows();
    return 0;
}


Mat ImgAlgorithm::SURF(Mat src)
{
    Mat res,descriptors;
    vector<KeyPoint> keypoints;
    //Feature2D方法测试
    //Ptr<KAZE> kaze = KAZE::create();//适用于仿射变换
    Ptr<AKAZE> akaze= AKAZE::create();//KAZE的加速版本
    //kaze->detectAndCompute(src,noArray(), keypoints,descriptors);
    akaze->detectAndCompute(src,noArray(),keypoints,descriptors);
    drawKeypoints(src, keypoints, res);
    QMessageBox::information(nullptr,QString("提示"),QString("关键点数量:%1").arg(keypoints.size()));
    waitKey(0);
    return res;
}



int ImgAlgorithm::MatchKPoint(Mat temp, Mat src)
{
    Mat des1, des2 , res;
    int nfeatures = 10000;
    int Layers=4;
    double contrastThres=0.04;
    double edgeThres = 20;
    double sigma = 1.6;
    bool upScale = true;
    vector<KeyPoint> kp1, kp2;
    vector<DMatch>matches;
    Ptr<SIFT> sift = SIFT::create(nfeatures, Layers, contrastThres, edgeThres, sigma, upScale);
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
    sift->detectAndCompute(temp, noArray() , kp1, des1) ;
    sift->detectAndCompute(src,noArray(), kp2, des2) ;
    matcher->match(des1, des2,matches , noArray());
    drawMatches(temp , kp1, src, kp2, matches , res);
    QMessageBox::information(nullptr, QString("提示"),QString("关键点数量:%1").arg(matches.size()));
    waitKey(0);
    destroyAllWindows();
    return 0;
}

Mat ImgAlgorithm::HoughLine(Mat src)
{
    Mat edges;
    vector<Vec4i> lines;
    if(CannyDlg::ins().exec()== QDialog::Accepted){
        int newL=CannyDlg::ins().getValue(0);
        int newH=CannyDlg::ins().getValue(1);
        CannyDlg::ins().setValue(newH,newL);
        CannyDlg::ins().low= CannyDlg::ins().getValue(0);
        CannyDlg::ins().high =CannyDlg::ins().getValue(1);
        edges = Tools::ins().EdgeCanny(src,newL,newH);
        HoughLinesP(edges, lines, 1, CV_PI/180, (newL+newH)/2, 100, 5);
    }
    for (int i = 0; i < lines.size(); i++) {
        Vec4i l = lines[i];
        line(src, Point(l[0], l[1]), Point(l[2], l[3]), QVGreen, 2, 8);
    }
    waitKey(0);
    destroyAllWindows();
    return src;
}

Mat ImgAlgorithm::HoughTriangle(Mat src)
{
    Mat edges = Tools::ins().EdgeCanny(src);
    vector<Vec2f> lines;
    HoughLines(edges, lines , 1, CV_PI/180,100);
    for (int i = 0; i < lines.size(); ++i)
    {
        float rho = lines[i][0];
        float theta = lines[i][1];
        Point p1, p2;
        double a = cos(theta), b = sin(theta) ;
        double x0= a * rho,y0=b*rho;
        p1.x = cvRound(x0+1000* (-b));
        p1.y = cvRound(y0+1000* (a));
        p2.x = cvRound(x0-1000* (-b));
        p2.y = cvRound(y0-1000* (a));
        line(src, p1, p2,Scalar(0,255,0), 2);
    }
    waitKey(0);
    return src;
}

Mat ImgAlgorithm::HoughRectangle(Mat src)
{
    Mat edges = Tools::ins().EdgeCanny(src);
    Mat res = src.clone();
    vector<Vec2f> lines;
    if(ThresholdDlg::ins().exec()== QDialog::Accepted){
        int newtype=ThresholdDlg::ins().getValue(1);
        int newval=ThresholdDlg::ins().getValue(2);
        ThresholdDlg::ins().setValue(newval,newtype);
        ThresholdDlg::ins().thresval=newval;
        HoughLines(edges,lines,1,CV_PI/180,newval,0,0);
    }
    for (int i = 0; i < lines.size(); ++i)
    {
        float rho = lines[i][0];
        float theta = lines[i][1];
        Point p1, p2;
        double a = cos(theta), b = sin(theta);
        double x0= a*rho, y0 = b * rho;
        p1.x = cvRound(x0 + 1000 * (-b));
        p1.y = cvRound(y0 + 1000* (a));
        p2.x = cvRound(x0 -1000*(-b));
        p2.y = cvRound(y0 -1000*(a));
        line(res, p1, p2,QVGreen,2,LINE_AA);
    }
    waitKey(0);
    destroyAllWindows();
    return res;
}


Mat ImgAlgorithm::HoughCircle(Mat src)
{
    Mat gray = Preprocess::ins().GrayTransform(src);
    Mat blur = Preprocess::ins().GaussFilter(gray);
    vector<Vec3f> circles;
    HoughCircles(blur, circles, HOUGH_GRADIENT, 1, 50, 150, 20, 20,100);
    for(int i = 0; i < circles.size(); ++i)
    {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(src, center, 3,QVRed, 3,8,0);
        circle(src,center, radius, QVGreen,5,8,0);
    }
    QMessageBox::information(nullptr,QString("提示"),QString("检测到圆的数量:%1").arg(circles.size()));
    waitKey(0);
    destroyAllWindows();
    return src;
}

Mat ImgAlgorithm::HoughEllipse(Mat src)
{
    Mat gray = Preprocess::ins().GrayTransform(src);
    vector<Vec3f> ellipses;
    HoughCircles(gray,ellipses, HOUGH_GRADIENT,1, 50,150,40,20,100);
    for (int i =0 ; i < ellipses.size(); ++i)
    {
        Point center(cvRound(ellipses[i][0]),cvRound(ellipses[i][1]));
        ellipse(src, center, Size(cvRound(ellipses[i][2]), cvRound(ellipses[i][2])),0 ,0, 360, QVCyan,5,LINE_8);
    }
    QMessageBox::information(nullptr,QString("提示"),QString("检测到椭圆的数量:%1").arg(ellipses.size()));
    waitKey(0);
    return src;
}

vector<Vec2f> ImgAlgorithm::DynamicDetectLine(Mat frame)
{
    Mat edges = Tools::ins().EdgeCanny(frame);
    vector<Vec2f> lines;
    HoughLines(edges, lines, 1, CV_PI/180,100);
    return lines;
}

vector<Vec2f> ImgAlgorithm::DynamicDetectTriangle(Mat frame)
{
    Mat edges = Tools::ins().EdgeCanny(frame);
    vector<Vec2f> triangle;
    HoughLines(edges, triangle,1, CV_PI/180,100);
    return triangle;
}


vector<Vec3f> ImgAlgorithm::DynamicDetectcir(Mat frame)
{
    vector<Vec3f> circles;
    Mat gray = Preprocess::ins().GrayTransform(frame);
    Mat blur = Preprocess::ins().GaussFilter(gray);
    HoughCircles(blur, circles, HOUGH_GRADIENT, 1, blur.rows/2, 100, 30, 30,100);
    return circles;
}


vector<Vec3f> ImgAlgorithm::DynamicDetectEll(Mat frame)
{
    vector<Vec3f> ellipses;
    Mat gray = Preprocess::ins().GrayTransform(frame);
    HoughCircles(gray, ellipses, HOUGH_GRADIENT,1, gray.rows/8,100, 50,10,100);
    return ellipses;
}


Mat ImgAlgorithm::MatchTemp(Mat src, Mat target, int thresVal)
{
    auto start=chrono::high_resolution_clock::now();
    Rect cutBox=Tools::ins().GetCoordinate();
    Mat res,output,diff;
    pyrDown(src,src);
    pyrDown(target, target);
    matchTemplate(src, target, res ,TM_CCOEFF_NORMED);
    normalize(res, res,0,1,NORM_MINMAX,-1, Mat());
    double minVal, maxVal;
    Point minLoc, maxLoc, matchLoc;
    minMaxLoc(res,&minVal,&maxVal,&minLoc,&maxLoc,Mat());
    TM_SQDIFF == TM_CCOEFF_NORMED||TM_SQDIFF_NORMED == TM_CCOEFF_NORMED ? matchLoc = matchLoc : matchLoc;
    maxVal >= 0.95 ? matchLoc = maxLoc : matchLoc = Point(0,0);
    Point rb(matchLoc.x + target.cols, matchLoc.y + target.rows);
    Rect outputRoi(matchLoc, rb);
    Mat roi = src(outputRoi).clone();
    output = Tools::ins().ThresholdProcess(roi,thresVal);
    absdiff(output, target, diff) ;
    diff.convertTo(diff,CV_32F);
    Scalar mse=sum(diff.mul(diff))/(output.rows * output.cols * output.channels());
    double psnr= 10.0 * log10((255 * 255)/mse[0]);
    string Correlation = format("%.2f", maxVal);
    string psnRatio = format("%.2f", psnr);
    rectangle(src,cutBox,QVPurple,1,8,0);
    rectangle(src,matchLoc,rb,QVPurple,1,8,0);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    QMessageBox::information(nullptr, QString("提示"),QString("模板匹配用时:%1(ms)").arg(duration.count()));
    putText(src,"Correlation:" + Correlation, Point(matchLoc.x, rb.y+20),16,0.8,QVGreen,1,8);
    putText(src,"PSNR:"+psnRatio,Point(matchLoc.x,rb.y + 45),16,0.8,QVGreen,1,16);
    imwrite("matchTemplate"+ to_string(matchRes)+".png",src);
    matchRes++;
    waitKey(0);
    destroyAllWindows();
    return src;
}


Mat ImgAlgorithm::FeaturePointMatch(Mat m1, Mat m2)
{
    auto start = chrono::high_resolution_clock::now();
    pyrDown(m1,m1);
    pyrDown(m2,m2);
    vector<DMatch> best;
    vector<KeyPoint> p1,p2;
    vector<Point2f> targetArea;
    vector<vector<DMatch>>twoPoint;
    Mat d1,d2,res,thM1,thM2;
    Point2f tempBest,srcBest;
    Ptr<SIFT> sift = SIFT::create();
    thM1 = Preprocess::ins().GrayTransform(m1);
    thM2 = Preprocess::ins().GrayTransform(m2);
    sift->detectAndCompute(thM1, noArray(), p1, d1);
    sift->detectAndCompute(thM2,noArray(), p2,d2);
    BFMatcher matcher(NORM_L2);
    matcher.knnMatch(d1, d2, twoPoint,2, noArray(), true) ;
    for (int i = 0; i < twoPoint.size(); i++)
    {
        if (twoPoint[i][0].distance < 0.6 * twoPoint[i][1].distance)
        {
            best.push_back(twoPoint[i][0]);
        }
    }
    drawMatches(m1, p1, m2, p2, best, res);
    for (const auto& match : best)
    {
        tempBest = p1[match.queryIdx].pt;
        srcBest = p2[match.trainIdx].pt;
        circle(res,tempBest,5,QVGreen, 2);
        circle(res,srcBest+ Point2f(m1.cols,0),5,QVGreen, 2);
    }
    Rect srcRect = boundingRect(targetArea);
    srcRect.x-=srcRect.width/4;
    srcRect.y-=srcRect.height/2;
    srcRect.width *= 1.5;
    srcRect.height *= 2;
    rectangle(res, srcRect,QVGreen,2,LINE_8);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    //Info.MsgBox("检测到旋转角度(度)",angle);
    QMessageBox::information(nullptr, QString("提示"),QString("已匹配关键点:%1(个)").arg(best.size()));
    QMessageBox::information(nullptr,QString("提示"),QString("特征点匹配耗时:%1(ms)").arg(duration.count()));
    imwrite("featureMatch"+to_string(matchRes)+".png",res);
    matchRes++;
    waitKey(0);
    return res;
}


Mat ImgAlgorithm::UpgradeMatchTemp(Mat temp, Mat src,int a,double b,double c, double d,double e,double f)
{
    auto start = chrono::high_resolution_clock::now();
    Mat tempEdge,srcEdge ;
    Mat thSrc, thTemp;
    thSrc =Tools::ins().ThresholdProcess(src,a,255,0);
    thTemp =Tools::ins().ThresholdProcess(temp,a,255,0);
    Canny(thSrc,srcEdge,100,200);
    Canny(thTemp, tempEdge,100,200);
    vector<pair<Rect, double>> matches = Tools::ins().TotalArea(srcEdge,tempEdge,b,c,d,e);
    vector<Rect>rects;
    vector<double>matchScores;
    for(const auto& match:matches)
    {
        rects.push_back(match.first);
        matchScores.push_back(match.second);
    }
    vector<Rect>nmsRects = Tools::ins().NonMaxSuppress(rects, matchScores,f);
    for (const auto& nmsRect : nmsRects)
    {
        Scalar colorful(rand() % 256, rand() % 256, rand() % 256);
        int centerX = nmsRect.x + nmsRect.width/2;
        int centerY = nmsRect.y + nmsRect.height/2;
        Point cirCen(centerX, centerY);
        rectangle(src, nmsRect, colorful, 1);
        circle(src,cirCen,1,colorful,-1);
    }
    auto end= chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    QMessageBox::information(nullptr,QString("提示"),QString("改进模板匹配用时:%1(ms)").arg(duration.count()));
    imwrite("UpgradeTemplate"+ to_string(matchRes) +".png",src);
    matchRes++;
    waitKey(0);
    return src;
}

Mat ImgAlgorithm::HoughBallard(Mat src,Mat temp,double mindist, int level, double dp, int buffer, int vote, int low, int high)
{
    Rect tempArea= Tools::ins().GetCoordinate();
    if (tempArea.width == 0||tempArea.height == 0)
    {
        QMessageBox::warning(nullptr,QString("提示"),QString("未获取到截图区域坐标"));
        goto NullCoord;
    }
    else
    {
        Mat whereTemp = src(tempArea).clone();
        Point2f center(tempArea.x + tempArea.width/2.0,tempArea.y + tempArea.height/2.0);
        float Outcir = sqrt(pow(tempArea.width/2.0, 2) + pow(tempArea.height/2.0, 2));
        float InCir = min(tempArea.width, tempArea.height)/2.0;
        circle(src, center,Outcir, QVCyan,10,8,0);
        circle(src,center,InCir, QVYellow,5,8,0);
        circle(src,center,5,QVPurple,-1);
    }
NullCoord:
    auto start=chrono::high_resolution_clock::now();
    pyrDown(src,src);
    pyrDown(temp,temp);
    Mat gray,templ;
    int lineWidth = 1;
    gray= Tools::ins().EdgeCanny(src);
    templ = Tools::ins().EdgeCanny(temp);
    vector<Vec4f> Positions;
    int w = templ.cols;
    int h = templ.rows;
    Ptr<GeneralizedHoughBallard> ballard = createGeneralizedHoughBallard();
    Tools::ins().SetHoughParas(ballard,mindist,level,dp,buffer,vote,low,high);
    ballard->setTemplate(templ);
    ballard->detect(gray,Positions);
    for(const auto& p : Positions)
    {
        Tools::ins().DrawRotRect(src, Point2f(p[0], p[1]), Size2f(w * p[2], h * p[2]), p[3], QVGreen,lineWidth);
    }
    auto end=chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    QMessageBox::information(nullptr, QString("提示"),QString("Ballard匹配用时:%1(ms)").arg(duration.count()));
    QMessageBox::information(nullptr, QString("提示"),QString("目标区域:%1(个)").arg(Positions.size()));
    imwrite("HoughBallard"+ to_string(matchRes) +".png",src);
    waitKey(0);
    matchRes++;
    return src;
}


Mat ImgAlgorithm::HoughGuil(Mat src, Mat temp, double mindist, int level, double dp, double xi,
    int buffersize,int cannylow,int cannyhigh,int minangle, int maxangle, int anglestep,
    int anglethreshold,float minscale,float maxscale,double angleeplise,int scalestep,int scalethreshold,float positionthreshold)
{
    auto start = chrono::high_resolution_clock::now();
    int lineWidth = 1;
    pyrDown(src,src);
    pyrDown(temp,temp);
    Mat graySrc = Preprocess::ins().GrayTransform(src);
    Mat grayTemp = Preprocess::ins().GrayTransform(temp);
    vector<Vec4f> Positions;
    int w= grayTemp.cols;
    int h= grayTemp.rows;
    Ptr<GeneralizedHoughGuil> guil = createGeneralizedHoughGuil();
    try
    {
        Tools::ins().SetHoughParas(guil, mindist, level, dp, xi,buffersize, cannylow, cannyhigh, minangle, maxangle, anglestep, anglethreshold,
                            minscale,maxscale,angleeplise,scalestep,scalethreshold,positionthreshold);
    }
    catch(const exception& e)
    {
        QString eMsg ="参数设置错误!\n";
        eMsg += e.what();
        QMessageBox::critical(nullptr,"错误",eMsg,QMessageBox::Ok);
        return Mat();
    }
    guil->setTemplate(grayTemp, Point(temp.cols/2,temp.rows/2));
    guil->detect(grayTemp, Positions);
    for(const auto& p : Positions)
    {
        Tools::ins().DrawRotRect(src,Point2f(p[0], p[1]),Size2f(w * p[2], h * p[2]), p[3],QVGreen,lineWidth);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    QMessageBox::information(nullptr,QString("提示"),QString("广义霍夫(Guil)匹配用时:%1(ms)").arg(duration.count()));
    QMessageBox::information(nullptr,QString("提示"),QString("检测到的目标区域:%1(个)").arg(Positions.size()));
    imwrite("HoughGuil"+ to_string(matchRes) +".png",src);
    matchRes++;
    waitKey(0);
    return src;
}


//shi-Tomasi 角点检测器(抗噪声)
Mat ImgAlgorithm::ShiTomasiDetect(Mat src)
{
    Mat gray = Preprocess::ins().GrayTransform(src);
    vector<Point2f> corners;
    goodFeaturesToTrack(gray, corners, 1000,0.5,10);
    for (int i = 0; i < corners.size(); i++)
    {
        circle(src, corners[i], 10, Scalar(0,255, 0), 2);
    }
    QMessageBox::information(nullptr,QString("提示"),QString("检测到角点数量:%1").arg(corners.size()));
    waitKey(0);
    return src;
}


Mat ImgAlgorithm::HarrisDetect(Mat src)
{
    Mat gray,corners,res;
    gray = Preprocess::ins().GrayTransform(src);
    cornerHarris(gray,corners,10,3,0.04);
    normalize(corners,corners,0,255,NORM_MINMAX,CV_32FC1);
    vector<Point2f> HarrisRes;
    int val = 245;
    src.convertTo(res,CV_8U);
    for(int i = 0; i < corners.rows; ++i){
        for (int j = 0; j< corners.cols; ++j){
            float response = static_cast<int>(corners.at<float>(i,j));
            if (response > val)
            {
                circle(res,Point(j,i),20,QVGreen,5,LINE_8);
                HarrisRes.push_back(Point(j,i));
            }
        }
    }
    QMessageBox::information(nullptr, QString("提示"),tr("检测到角点数量:%1").arg(HarrisRes.size()));
    waitKey(0);
    destroyAllWindows();
    return res;
}


//FAST角占检测器(通过在圆周上选择像素占并快速判断是否为角占)
Mat ImgAlgorithm::FASTDetect(Mat src)
{
    Mat res,gray = Preprocess::ins().GrayTransform(src);
    int val = 25;
    Ptr<FastFeatureDetector> detector=FastFeatureDetector::create(val, true,FastFeatureDetector::TYPE_5_8);
    vector<KeyPoint> keypoints;
    detector->detect(gray, keypoints);
    drawKeypoints(src, keypoints,res,QVGreen,DrawMatchesFlags::DEFAULT);
    QMessageBox::information(nullptr,QString("提示"),QString("检测到角点数量:%1").arg(keypoints.size()));
    waitKey(0);
    return res;
}


//ORB角点检测器(具有旋转不变性和鲁棒性)
Mat ImgAlgorithm::ORBDetect(Mat src)
{
    Mat res;
    src=Preprocess::ins().GrayTransform(src);
    Ptr<ORB> orb = ORB::create();
    vector<KeyPoint> keypoints;
    // orb->detectAndCompute(src,noArray(), keypoints, descriptors);
    try{
        orb->detect(src, keypoints);
    }
    catch (const Exception& e)
    {
        QString eMsg ="ORB检测时发生异常:%s!\n";
        eMsg +=e.what();
        QMessageBox::critical(nullptr,"错误",eMsg,QMessageBox::Ok);
        return Mat();
    }
    drawKeypoints(src, keypoints, res, QVGreen);
    QMessageBox::information(nullptr,QString("提示"),QString("检测到角点数量:%1").arg(keypoints.size()));
    waitKey(0);
    return res;
}


//BRISK角点检测器(结合了快速的特征检测和描述符生成)
Mat ImgAlgorithm::BRISKDetect(Mat src)
{
    Mat res;
    int val = 25;
    int octaves= 4;//金字塔层数(1~4)
    float patternScale = 1.2f;
    Ptr<BRISK> orb=BRISK::create(val,octaves,patternScale);
    vector<KeyPoint> keypoints;
    orb->detect(src, keypoints);
    drawKeypoints(src, keypoints,res,QVGreen,DrawMatchesFlags::DEFAULT);
    QMessageBox::information(nullptr, QString("提示"),QString("检测到角点数量:%1").arg(keypoints.size()));
    waitKey(0);
    return res;
}


//MSER角点检测器(检测稳定的极值区域,也可以用于检测角点。
Mat ImgAlgorithm::MSERDetect(Mat src)
{
    Mat gray = Preprocess::ins().GrayTransform(src);
    vector<Rect> areaBox;
    vector<vector<Point>> regions;
    Ptr<MSER> mser = MSER::create();
    mser->detectRegions(gray, regions,areaBox);
    Mat res = src.clone();
    for(auto& r : regions){
        for (auto& p : r){
            circle(res, p, 1, QVGreen,1,LINE_8);
        }
    }
    QMessageBox::information(nullptr,QString("提示"),QString("检测到角点数量:%1").arg(regions.size()));
    waitKey(0);
    return res;
}


//GFTT角点检测器(通过选择图像中最好跟踪的特征点来进行角点检测。
Mat ImgAlgorithm::GFTTDetect(Mat src)
{
    Mat res;
    int maxCorners = 0;
    double qualityLevel= 0.01;
    double mnDistance=10;
    Ptr<GFTTDetector> gftt = GFTTDetector::create(maxCorners,qualityLevel,mnDistance);
    vector<KeyPoint> keypoints;
    gftt->detect(src, keypoints);
    drawKeypoints(src,keypoints,res,QVGreen,DrawMatchesFlags::DEFAULT);
    QMessageBox::information(nullptr, QString("提示"), QString("检测到角点数量:%1").arg(keypoints.size()));
    waitKey(0);
    return res;
}


Mat ImgAlgorithm::DetectFaceFromImg(Mat src)
{
    Mat equal;
    equal=HistEqual(src);
    CascadeClassifier model;
    if (!model.load("haarcascade_frontalface_default.xml"))
    {
        QMessageBox::information(nullptr,QString("提示"),QString("加载分类器失败!"));
        return src;
    }
    vector<Rect> faces(0);
    model.detectMultiScale(equal, faces,1.1,2,0,Size(30,30));
    if (faces.size() > 0)
    {
        for(int i=0;i < faces.size(); i++)
        {
            rectangle(src, faces[i], QVGreen,2,8,0);
        }
        imwrite("DetectFace"+ to_string(recongizedNum) +".png",src);
        recongizedNum++;
        QMessageBox::information(nullptr,QString("提示"),QString("检测到人脸个数为:%1").arg(faces.size()));
        waitKey(0);
        return src;
    }
    else
    {
        QMessageBox::information(nullptr,QString("提示"),QString("未检测到人脸"));
        return src;
    }
}


//均衡化处理
Mat ImgAlgorithm::HistEqual(Mat src)
{
    Mat res,gray=Preprocess::ins().GrayTransform(src);
    equalizeHist(gray, res);
    return res;
}


//自定义模型
Mat ImgAlgorithm::SelfModel(Mat src,QString modelPath)
{
    Mat equal;
    CascadeClassifier anyObj;
    if (!anyObj.load(modelPath.toStdString())){
        QMessageBox::information(nullptr,QString("提示"),QString("加载模型失败!"));
        return src.clone();
    }
    qDebug()<<modelPath;
    equal=HistEqual(src);
    vector<Rect> objs(0);
    anyObj.detectMultiScale(equal, objs, 1.1, 2,0,Size(30,30));
    if (objs.size()>0)
    {
        for (int i= 0;i < objs.size(); i++)
        {
            rectangle(src,objs[i], QVGreen,2,8,0);
        }
        imwrite("findObj" + to_string(recongizedNum) + ".png",src);
        recongizedNum++;
        QMessageBox::information(nullptr,QString("提示"),QString("检测到目标数量:%1").arg(objs.size()));
        waitKey(0);
        return src;
    }else
    {
        QMessageBox::information(nullptr,QString("提示"),QString("未检测到目标!"));
        return Mat();
    }
}
