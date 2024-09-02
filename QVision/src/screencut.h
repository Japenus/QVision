#ifndef SCREENCUT_H
#define SCREENCUT_H
#include "color.h"
#include "global.h"
#include "formattransfer.h"
class ScreenCut : public QWidget
{
    Q_OBJECT
public:
    Mat CurrentArea;
    explicit ScreenCut();
    void CutArea(QPixmap &pix);
    static ScreenCut & ins(){static ScreenCut s;return s;}
private:
    bool drawing;
    QPixmap captured;
    QPoint Cursor, Start, End;
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseReleaseEvent(QMouseEvent *event) override final;
};
#endif // SCREENCUT_H
