#include "qvision.h"
#include "global.h"
#include <QThread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVision w;
    QSplashScreen *setupIcon=new QSplashScreen(QPixmap("ico.png"));
    setupIcon->show();
    QThread::msleep(3000);
    setupIcon->close();
    w.show();
    return a.exec();
}
