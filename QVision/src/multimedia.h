#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include"global.h"
class MultiMedia:public QWidget
{
    Q_OBJECT
public:
    MultiMedia(QWidget *parent = nullptr);
    static MultiMedia & ins(){static MultiMedia m;return m;}
private slots:
    void Open();
    void Play();
    void Pause();
    void Close();
    // void setVolume(int volume);
    void setVideoPosition(int position);
    void durationChanged(qint64 duration);
    void positionChanged(qint64 position);
private:
    QLabel *durTime;
    QSlider *pSlider;
    QHBoxLayout *Row1;
    QHBoxLayout *Row2;
    QHBoxLayout *Row3;
    QComboBox *PlaySpeed;
    QVBoxLayout *MainStruct;
    QPushButton *OpenVideo;
    QPushButton *PlayVideo;
    QPushButton *PauseVideo;
    QPushButton *CloseWindow;
    QMediaPlayer *mediaPlayer;
    QVideoWidget *videowidget;
};

#endif // MULTIMEDIA_H
