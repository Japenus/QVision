#include "formattransfer.h"
Mat FormatTransfer::Pix2Mat(Pix *datatype)
{
    l_int32 w = pixGetWidth(datatype);
    l_int32 h = pixGetHeight(datatype);
    uint32_t *data = pixGetData(datatype);
    Mat res(Size(w,h),CV_8UC1);
    for(uint32_t y=0;y<h;++y)
    {
        for(uint32_t x=0;x<w;++x)
        {
            res.at<uchar>(y,x)=GET_DATA_BYTE(data,x);
        }
        data += pixGetWpl(datatype);
    }
    return res;
}

Pix* FormatTransfer::Mat2Pix(Mat datatype)
{
    int cols = datatype.cols;
    int rows = datatype.rows;
    Pix *pixS = pixCreate(cols,rows,8);
    for(int i=0;i< rows;i++)
    {
        for(int j=0;j< cols;j++)
        {
            pixSetPixel(pixS,j,i,(l_int32)datatype.at<uchar>(i,j));
        }
    }
    return pixS;
}

QImage FormatTransfer::Pix2QImage(Pix *datatype)
{
    QImage::Format f;
    QVector<QRgb> colorTable;
    l_int32 numcolors;
    l_int32 factor =1;// 设置因子
    l_int32 wpld = pixGetWpl(datatype);
    l_int32 depth =pixGetDepth(datatype);
    l_int32 width = pixGetWidth(datatype);
    l_int32 height = pixGetHeight(datatype);
    QImage res(width,height,f);
    l_uint32 *start = pixGetData(datatype);
    PIXCMAP *pixcmap =pixGetColormap(datatype);
    QImage none(0,0,QImage::Format_Invalid);
    l_int32 bytesPerLine = pixGetWpl(datatype)*4;
    l_uint32 *s_data = pixGetData(pixEndianByteSwapNew(datatype));
    switch (depth)
    {
        case 1:
            f=QImage::Format_Mono;
            break;
        case 8:
            f=QImage::Format_Indexed8;
            break;
        case 24:
            f=QImage::Format_RGB888;
            break;
        default:
            f=QImage::Format_RGB32;
            break;
    }
    if(res.format() == QImage::Format_RGB32)
    {
        for(int i=0;i< height; i++)
        {
            QRgb *lined =(QRgb *)res.scanLine(i);
            l_uint32 *lines =start +wpld *i;
            for(int j=0;j<width;j++)
            {
                l_int32 r,g,b;
                extractRGBValues(lines[j],&r,&g,&b);
                lined[j] = qRgb(r,g,b);
            }
        }
    }else{
        for(int i=0;i< height; i++)
        {
            uchar * lined = res.scanLine(i);
            uchar *lines=(uchar*)(start+wpld *i);
            memcpy(lined ,lines,static_cast<int>(bytesPerLine));
        }
    }
    return res;
}

Pix* FormatTransfer::QImage2Pix(QImage &datatype)
{
    PIX *pix;
    int width = datatype.width();
    int height = datatype.height();
    int depth = datatype.depth();
    pix = pixCreate(width,height,depth);
    if(datatype.colorCount())
    {
        QVector<QRgb> table = datatype.colorTable();
        PIXCMAP *map = pixcmapCreate(8);
        int n = table.size();
        for(int i=0;i< n; i++)
        {
            pixcmapAddColor(map, qRed(table[i]), qGreen(table[i]), qBlue(table[i]));
        }
        pixSetColormap(pix,map);
    }
    int bytePerLine = datatype.bytesPerLine();
    l_uint32* start = pixGetData(pix);
    l_int32 wpld = pixGetWpl(pix);

    if(datatype.format()== QImage::Format_Mono||datatype.format()== QImage::Format_Indexed8||datatype.format()== 0)
    {
        for(int i =0;i< height; i++)
        {
            const uchar *lines = datatype.scanLine(i);
            uchar *lined=(uchar *)(start+wpld *i);
            memcpy(lined ,lines,static_cast<int>(bytePerLine));
        }
    }
    else if (datatype.format()== QImage::Format_RGB32||datatype.format()== QImage::Format_ARGB32)
    {
        for(int i=0;i<datatype.height();i++)
        {
            const QRgb *lines =(const QRgb *)datatype.scanLine(i);
            l_uint32 *lined =start+wpld *i;
            for(int j=0;j< width;j++)
            {
                uchar r=qRed(lines[j]);
                uchar g=qGreen(lines[j]);
                uchar b=qBlue(lines[j]);
                l_uint32 pixel;
                composeRGBPixel(r,g,b,&pixel);
                lined[j] = pixel;
            }
        }
    }
    return pix;
}

Mat FormatTransfer::QPixmap2Mat(QPixmap &datatype)
{
    QImage image = datatype.toImage();
    if(image.isNull())
    {
        qDebug() << "Failed to convert";
        return Mat();
    }
    Mat res(image.height(), image.width(), CV_8UC4, image.bits(), image.bytesPerLine());
    cvtColor(res, res, COLOR_BGRA2BGR);
    return res;
}

QString FormatTransfer::Int2QString(int data)
{
    return QString::number(data);
}
