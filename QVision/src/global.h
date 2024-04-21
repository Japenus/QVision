#ifndef GLOBAL_H
#define GLOBAL_H
#include <QSql>
#include <QList>
#include <QLabel>
#include <QTimer>
#include <QObject>
#include <QScreen>
#include <QMenuBar>
#include <QProcess>
#include <core.hpp>
#include <QSpinBox>
#include <QLineEdit>
#include <baseapi.h>
#include <QTextEdit>
#include <QComboBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QTcpServer>
#include <QTableView>
#include <opencv.hpp>
#include <QEventLoop>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
#include <QHeaderView>
#include <QVBoxLayout>
#include <QAudioDevice>
#include <allheaders.h>
#include <QHostAddress>
#include <QProgressBar>
#include <QSqlDatabase>
#include <QAudioOutput>
#include <QAudioDevice>
#include <QAudioFormat>
#include <QApplication>
#include <QColorDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QStandardItem>
#include <QElapsedTimer>
#include <QSplashScreen>
#include <QNetworkReply>
#include <QPlainTextEdit>
#include <QGuiApplication>
#include <QDesktopServices>
#include <QRegularExpression>
#include <QNetworkAccessManager>
using namespace cv;
using namespace std;
using namespace tesseract;
enum {
    MINDIST,
    LEVEL,
    DP,
    XI,
    ANGLEEPSILON,
    BUFFERSIZE,
    CANNYLOWTHRESHOLD,
    CANNYHIGHTHRESHOLD,
    MINANGLE,
    MAXANGLE,
    ANGLESTEP,
    ANGLETHRESHOLD,
    MINSCALE,
    MAXSCALE,
    SCALESTEP,
    SCALETHRESHOLD,
    POSITIONTHRESHOLD
};
#endif // GLOBAL_H
