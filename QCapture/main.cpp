#include "qcapture.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCapture w;
    w.show();
    return a.exec();
}
