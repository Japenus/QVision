#include "Preprocess.h"
//灰度变换
Mat Preprocess::GrayTransform(Mat src)
{
    Mat res;
    cvtColor(src, res,COLOR_BGR2GRAY);
    imwrite("Gray.png", res);
    imwrite("output.png", res);
    return res;
}
//对数变换
Mat Preprocess::LogTransform(Mat src,double para)
{
    assert(src.channels() == 3);
    Mat res(src.size(), CV_8UC1);
    for(int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            Vec3b pixel = src.at<Vec3b>(i,j);
            int grayValue = para * log(1 + pixel[2]);
            res.at<uchar>(i, j) = grayValue;
        }
    }
    imwrite("LogTransform.png", res);
    imwrite("output.png", res);
    return res;
}
//线性变换
Mat Preprocess::LinearTransform(Mat src)
{
    assert(src.channels() == 3);
    Mat res(src.size(), CV_8UC1);
    for(int i = 0; i< src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            Vec3b pixel = src.at<Vec3b>(i, j);
            int grayValue = 0.299 * pixel[2]+0.587 * pixel[1] + 0.114 * pixel[0];
            res.at<uchar>(i, j) = grayValue;
        }
    }
    imwrite("LinearTransform.png", res);
    imwrite("output.png", res ) ;
    return res;
}
//伽马变换
Mat Preprocess::GammaTransform(Mat src, float gamma)
{
    assert(src.channels() == 3);
    Mat res(src.size(), CV_8UC1);
    for(int i = 0; i < src.rows; i++)
    {
        for(int j=0;j<src.cols;j++)
        {
            Vec3b pixel=src.at<Vec3b>(i,j);
            int grayValue = 255 * pow(pixel[2]/255,gamma);
            res.at<uchar>(i, j) = grayValue;
        }
    }
    imwrite("GammaTransform.png", res);
    imwrite("output.png", res);
    return res;
}
//方框滤波
Mat Preprocess::BoxFilter(Mat src)
{
    Mat res;
    boxFilter(src,res,-1,Size(3,3),Point(-1,-1),false,BORDER_DEFAULT);
    imwrite("BoxFilter.png", res);
    imwrite("output.png" , res) ;
    return res;
}
//均值滤波
Mat Preprocess::MeanFilter(Mat src)
{
    Mat res=Mat::zeros(src.size(),src.type());
    for(int y= 1; y < src.rows - 1; y++)
    {
        for(int x = 1; x < src.cols - 1; x++)
        {
            int R = 0, G = 0, B = 0;
            for(int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    Vec3b pixel = src.at<Vec3b>(y + i,x + j);
                    R += pixel[2];
                    G += pixel[1];
                    B += pixel[0];
                }
            }
            res.at<Vec3b>(y,x)[2]=R/9;
            res.at<Vec3b>(y,x)[1]=G/9;
            res.at<Vec3b>(y,x)[0]=B/9;
        }
    }
    imwrite("MeanFilter.png",res);
    imwrite("output.png",res);
    return res;
}
//中值滤波
Mat Preprocess::MediumFilter(Mat src)
{
    Mat res = src.clone();
    for(int y= 1;y < src.rows-1; y++)
    {
        for(int x = 1; x < src.cols - 1; x++)
        {
            Vec3b pixels[9];
            int index = 0;
            for(int i = -1; i <= 1; i++)
            {
                for (int j= -1; j <= 1; j++)
                {
                    pixels[index++] = src.at<Vec3b>(y + i,x + j);
                }
            }
            //对9个像素进行排序,取中值作为当前像素的值
            sort(pixels,pixels + 9,[](const Vec3b& a, const Vec3b& b) {return (a[0] + a[1] + a[2]) < (b[0] + b[1] + b[2]);});
            res.at<Vec3b>(y,x) = pixels[4];
        }
    }
    imwrite("MediumFilter.png", res);
    imwrite("output.png" ,res);
    return res;
}
//双边滤波
Mat Preprocess::BilateralFilter(Mat src)
{
    Mat res;
    bilateralFilter(src, res, 33,100,100);
    imwrite("BilateralFilter.png",res);
    imwrite("output.png", res );
    return res;
}
//高斯滤波
Mat Preprocess::GaussFilter(Mat src)
{
    Mat res;
    GaussianBlur(src, res, Size(15,15), 0) ;
    imwrite("MediumFiter.png",res);
    imwrite("output.png", res);
    return res;
}
//腐蚀
Mat Preprocess::Erosion(Mat src)
{
    Mat res;
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    erode(src,res, kernel);
    imwrite("Erosion.png",res);
    imwrite("output.png", res) ;
    return res;
}
//膨胀
Mat Preprocess::Dilation(Mat src)
{
    Mat res(src.size(), src.type()) ;
    Mat kernel =getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(src,res , kernel);
    imwrite("Dilate.png", res);
    imwrite("output.png", res);
    return res;
}
