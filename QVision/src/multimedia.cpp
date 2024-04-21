#include "multimedia.h"
MultiMedia::MultiMedia(QWidget *parent):QWidget(parent)
{
    Row1 = new QHBoxLayout;
    Row2 = new QHBoxLayout;
    Row3 = new QHBoxLayout;
    MainStruct = new QVBoxLayout;
    PlaySpeed = new QComboBox(this);
    mediaPlayer = new QMediaPlayer(this);
    videowidget = new QVideoWidget(this);
    OpenVideo = new QPushButton("Open", this);
    PlayVideo = new QPushButton("Play", this);
    PauseVideo = new QPushButton("Pause", this);
    CloseWindow = new QPushButton("Close", this);
    pSlider = new QSlider(Qt::Horizontal, this);
    durTime = new QLabel("00:00 / 00:00", this);
    pSlider->setStyleSheet("border: 2px solid green;border-radius: 5px;");
    durTime->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;;border-radius: 10px;font-weight: bold;");
    OpenVideo->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    PlayVideo->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;;border-radius: 10px;font-weight: bold;");
    PauseVideo->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    CloseWindow->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;;border-radius: 10px;font-weight: bold;");
    PlaySpeed->setStyleSheet("border: 1px solid brown;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");

    // QAudioDevice audioDevice = QAudioDevice::defaultOutputDevice();
    // QAudioOutput *audioOutput = new QAudioOutput(audioDevice, mediaPlayer);
    // mediaPlayer->setAudioOutput(audioOutput);
    // 添加音频输出控件
    // QSlider *volumeSlider = new QSlider(Qt::Horizontal, this);
    // volumeSlider->setRange(0, 100);
    // connect(volumeSlider, &QSlider::valueChanged, mediaPlayer, &QMediaPlayer::setAudioOutput);
    // connect(volumeSlider, &QSlider::valueChanged, this, &MultiMedia::setVolume);

    pSlider->setRange(0, 100);
    PlaySpeed->addItem("0.5x");
    PlaySpeed->addItem("1x");
    PlaySpeed->addItem("1.5x");
    PlaySpeed->addItem("2x");
    mediaPlayer->setVideoOutput(videowidget);


    Row1->addWidget(videowidget);
    Row2->addWidget(OpenVideo);
    Row2->addWidget(PlayVideo);
    Row2->addWidget(PauseVideo);
    Row2->addWidget(CloseWindow);

    Row3->addWidget(pSlider);
    Row3->addWidget(durTime);
    // Row3->addWidget(volumeSlider);
    Row3->addWidget(PlaySpeed);

    MainStruct->addLayout(Row1);
    MainStruct->addLayout(Row2);
    MainStruct->addLayout(Row3);
    setLayout(MainStruct);

    connect(OpenVideo, &QPushButton::clicked, this, &MultiMedia::Open);
    connect(PlayVideo, &QPushButton::clicked, this, &MultiMedia::Play);
    connect(PauseVideo, &QPushButton::clicked, this, &MultiMedia::Pause);
    connect(CloseWindow, &QPushButton::clicked, this, &MultiMedia::Close);
    connect(pSlider, &QSlider::sliderMoved, this, &MultiMedia::setVideoPosition);
    // connect(volumeSlider, &QSlider::valueChanged, this, &MultiMedia::setVolume);
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, &MultiMedia::durationChanged);
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &MultiMedia::positionChanged);
    connect(PlaySpeed, QOverload<int>::of(&QComboBox::activated), [this](int index){
        qreal speed = 1.0;
        switch(index) {
        case 0: speed = 0.5; break;
        case 1: speed = 1.0; break;
        case 2: speed = 1.5; break;
        case 3: speed = 2.0; break;
        }
        mediaPlayer->setPlaybackRate(speed);
    });

    resize(800,600);
    setWindowTitle("Video Player");
}
void MultiMedia::Open()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("open video"),
                QDir::homePath(),tr("video Files (*.mp4 *.avi *.mkv)"));
    if(!fileName.isEmpty()){
        mediaPlayer->setSource(QUrl::fromLocalFile(fileName));
        mediaPlayer->pause();
    }
}

void MultiMedia::Play()
{
    mediaPlayer->play();
}

void MultiMedia::Pause()
{
    mediaPlayer->pause();
}

void MultiMedia::Close()
{
    mediaPlayer->stop();
    this->close();
}
// void MultiMedia::setVolume(int volume)
// {
//     // QAudioDevice info = QAudioDevice::defaultOutputDevice();

//     QAudioOutput *audioOutput = new QAudioOutput(info, this);
//     audioOutput->setVolume(qreal(volume) / 100.0);
//     mediaPlayer->setAudioOutput(audioOutput);
// }

void MultiMedia::setVideoPosition(int position)
{
    mediaPlayer->setPosition(position * 1000);
}

void MultiMedia::durationChanged(qint64 duration)
{
    QTime durationTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    durTime->setText(QString("%1 / %2").arg(mediaPlayer->position() / 1000, 2, 10, QChar('0'))
                         .arg(durationTime.toString("mm:ss")));
}

void MultiMedia::positionChanged(qint64 position)
{
    QTime positionTime(0, (position / 60000) % 60, (position / 1000) % 60);
    durTime->setText(QString("%1 / %2").arg(positionTime.toString("mm:ss")).
                     arg(mediaPlayer->duration() / 1000));
}
