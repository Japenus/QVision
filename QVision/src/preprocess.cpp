#include "Preprocess.h"
Mat Preprocess::GrayTransform(Mat src)
{
    cvtColor(src, src,COLOR_BGR2GRAY);
    return src;
}

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
    return res;
}

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
    return res;
}

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
    return res;
}

Mat Preprocess::BoxFilter(Mat src)
{
    Mat res;
    boxFilter(src,res,-1,Size(3,3),Point(-1,-1),false,BORDER_DEFAULT);
    return res;
}

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
    return res;
}

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
            sort(pixels,pixels + 9,[](const Vec3b& a, const Vec3b& b) {return (a[0] + a[1] + a[2]) < (b[0] + b[1] + b[2]);});
            res.at<Vec3b>(y,x) = pixels[4];
        }
    }
    return res;
}

Mat Preprocess::BilateralFilter(Mat src)
{
    Mat res;
    bilateralFilter(src, res, 33, 100, 100);
    return res;
}

Mat Preprocess::GaussFilter(Mat src)
{
    GaussianBlur(src, src, Size(15,15), 0) ;
    return src;
}

Mat Preprocess::Erosion(Mat src)
{
    Mat kernel = getStructuringElement(MORPH_RECT,Size(3,3));
    erode(src,src, kernel);
    return src;
}

Mat Preprocess::Dilation(Mat src)
{
    Mat kernel =getStructuringElement(MORPH_RECT,Size(3,3));
    dilate(src,src,kernel);
    return src;
}
