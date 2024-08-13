#ifndef MACHINELEARNING_H
#define MACHINELEARNING_H

#include <Global.h>
class MachineLearning:public QMainWindow
{
public:
    MachineLearning(QWidget *parent=nullptr);
    ~MachineLearning();
    static MachineLearning & ins(){static MachineLearning m;return m;}

public slots:
    void modifyBackground();
    void closeWin();

    void onStartStreaming();
    void onStopStreaming();
    void onSavingImage();

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawStar(QPainter *painter, int x, int y, int outerRadius, int innerRadius, int points);

private:
    QImage bgImg;
    QString srcBg;
    QVideoWidget *vi;
    QPushButton *lbtn;
    QGroupBox *paras;
    QPushButton *closeCurWin;
    QPushButton *startCapture;
    QPushButton *stopCapture;
    QPushButton *saveScreen;
    QWidget *left;
    QWidget *right;
    QWidget *center;
    QHBoxLayout *main;
    QVBoxLayout *pLeft;
    QVBoxLayout *pRight;

    QCamera *m_camera;
    QMediaCaptureSession *m_mediaCaptureSession;
    QImageCapture *m_imageCapture;
    QString m_imageSavingPath;

};

#endif // MACHINELEARNING_H
