#include "qvision.h"
#include "global.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QVision w;
    // QSplashScreen *setupIcon=new QSplashScreen(QPixmap("start.png"));
    // setupIcon->show();
    // QTimer::singleShot(1000, setupIcon, &QSplashScreen::close);
    w.show();
    return a.exec();
}
