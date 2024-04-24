#ifndef CAPTURESCREEN_H
#define CAPTURESCREEN_H
#include "global.h"
class CaptureScreen : public QWidget
{
    Q_OBJECT
public:
    explicit CaptureScreen(QWidget *parent = nullptr);
public slots:
    void pixmapChanged(const QPixmap &pix);
private:
    bool m_isDrawing;
    QPixmap m_originPixmap;
    QPoint m_ptCursor, m_ptStart, m_ptEnd;
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void keyPressEvent(QKeyEvent *event) override final;
    virtual void mouseMoveEvent(QMouseEvent *event) override final;
    virtual void mousePressEvent(QMouseEvent *event) override final;
    virtual void mouseReleaseEvent(QMouseEvent *event) override final;
};

#endif // CAPTURESCREEN_H
