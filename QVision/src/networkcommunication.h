#ifndef NETWORKCOMMUNICATION_H
#define NETWORKCOMMUNICATION_H
#include "global.h"
class NetworkCommunication:public QMainWindow
{
public:
    NetworkCommunication(QWidget *parent = nullptr);
private slots:
    void createServer();
    void senData();
    void connected();
    void stopped();
    void disconnected();
private:
    QLabel *tip1;
    QLabel *tip2;
    QLabel *tip3;
    QLabel *tip4;
    QLabel *tip5;
    QLabel *tip6;
    QComboBox *clientIP;
    QLineEdit *clientPort;
    QComboBox *serverIP;
    QLineEdit *serverPort;

    QPushButton *connectBtn;
    QPushButton *disconnectBtn;
    QPushButton *sendBtn;
    QPushButton *stopBtn;

    QTextEdit *sendData;
    QTextEdit *recvData;
    QTextEdit *curStatus;
};

#endif // NETWORKCOMMUNICATION_H
