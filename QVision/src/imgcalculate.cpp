#include "imgcalculate.h"

Mat ImgCalculate::OnCalc(Mat src)
{
    Mat gray=Preprocess::ins().GrayTransform(src);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    Mat result;
    morphologyEx(gray,result,MORPH_OPEN,kernel);
    return result;
}

Mat ImgCalculate::OffCalc(Mat src)
{
    Mat gray = Preprocess::ins().GrayTransform(src);
    Mat kernel = getStructuringElement(MORPH_RECT,Size(5,5));
    Mat result;
    morphologyEx(gray,result,MORPH_CLOSE,kernel);
    return result;
}

Mat ImgCalculate::Add(Mat img1,Mat img2)
{
    Mat result;
    add(img1,img2,result);
    return result;
}

Mat ImgCalculate::Subtraction(Mat img1, Mat img2)
{
    Mat res;
    subtract(img1, img2, res);
    return res;
}

Mat ImgCalculate::Multipy(Mat src)
{
    double factor = 1.5;
    Mat res = src * factor;
    return res;
}
Mat ImgCalculate::Divide(Mat src)
{
    double factor = 1.5;
    Mat res = src/factor;
    return res;
}

Mat ImgCalculate::LineStretch(Mat src)
{
    Mat graySrc=Preprocess::ins().GrayTransform(src);
    double minVal, maxVal;
    minMaxLoc(graySrc, &minVal, &maxVal);
    Mat res,stretched = (graySrc - minVal) * (255.0 / (maxVal - minVal));
    threshold(stretched, res, 0, 255, THRESH_TOZERO);
    threshold(res, res, 255, 255, THRESH_TRUNC);
    return res;
}

//拉普拉斯变换(图像锐化)
Mat ImgCalculate::LaplacianTransform(Mat src)
{
    Mat res;
    Laplacian(Preprocess::ins().GrayTransform(src),res,CV_16S);
    res.convertTo(res, CV_8U);
    return res;
}

//傅里叶变换(作用:频率分析、滤波、频域处理、图像恢复、特征提取)
Mat ImgCalculate::FourierTransform(Mat src)
{
    Mat res,complexI,gray=Preprocess::ins().GrayTransform(src);
    Mat planes[] = {Mat_<float>(gray), Mat::zeros(gray.size(), CV_32F)};
    merge(planes,2,complexI);
    dft(complexI,complexI);
    magnitude(planes[0], planes[1], res);
    res += Scalar::all(1);
    log(res, res);
    normalize(res,res,0,1,NORM_MINMAX);
    return res;
}
