#ifndef QCAPTURE_H
#define QCAPTURE_H
#include <global.h>
class QCapture : public QMainWindow
{
    Q_OBJECT

public:
    QCapture(QWidget *parent = nullptr);
    ~QCapture();

public slots:
    void test();

private:
    QPushButton *c;
};
#endif // QCAPTURE_H
