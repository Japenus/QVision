#ifndef HEXSIGHT_H
#define HEXSIGHT_H
#include "global.h"
class hexSight
{
public:
    hexSight();
    static hexSight &ins(){static hexSight h;return h;}

public:
    void attachImage(const QImage &img);
    void loadModel(const QString &name);
    void displayContours(const QImage src);
    void hsImageToQImage(HSImage src,QImage &dst);
    void createModel(const QImage&img,const QString &name,QPointF &pnt,QRectF &roi);
    void applyModel(const QImage &img, qreal percent, qreal dx, qreal dy, QVector<qreal> &res);

public:
    QPolygon edgelPnts;

private:
    bool inited;
    HSImage *hsImg;
    HSView *hsView;
    HSModel model;
    HSDatabase hsDB;
    HSScene hsScene;
    HSLocator locator;

};

#endif // HEXSIGHT_H
