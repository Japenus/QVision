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
    void closeWin();
    void onSavingImage();
    void onStopStreaming();
    void modifyBackground();
    void onStartStreaming();

protected:
    void paintEvent(QPaintEvent *e) override;
    void drawStar(QPainter *painter, int x, int y, int outerRadius, int innerRadius, int points);

private:
    QImage bgImg;
    QString srcBg;
    QVideoWidget *vi;
    QGroupBox *paras;
    QPushButton *lbtn;
    QPushButton *saveScreen;
    QPushButton *stopCapture;
    QPushButton *closeCurWin;
    QPushButton *startCapture;
    QWidget *left;
    QWidget *right;
    QWidget *center;
    QHBoxLayout *main;
    QVBoxLayout *pLeft;
    QVBoxLayout *pRight;

    QCamera *m_camera;
    QString m_imageSavingPath;
    QImageCapture *m_imageCapture;
    QMediaCaptureSession *m_mediaCaptureSession;

};

#endif // MACHINELEARNING_H
