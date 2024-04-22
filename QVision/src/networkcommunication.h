#ifndef NETWORKCOMMUNICATION_H
#define NETWORKCOMMUNICATION_H
#include "global.h"
class NetworkCommunication:public QMainWindow
{
public:
    NetworkCommunication(QWidget *parent = nullptr);
private slots:
    void senData();
    void stopped();
    void connected();
    void createServer();
    void disconnected();
private:
    int connCount=0;
    QLabel *tip1;
    QLabel *tip2;
    QLabel *tip3;
    QLabel *tip4;
    QLabel *tip5;
    QLabel *tip6;
    QComboBox *clientIP;
    QComboBox *serverIP;
    QLineEdit *clientPort;
    QLineEdit *serverPort;

    QPushButton *sendBtn;
    QPushButton *stopBtn;
    QPushButton *connectBtn;
    QPushButton *disconnectBtn;

    QTextEdit *sendData;
    QTextEdit *recvData;
    QTextEdit *curStatus;

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QList<QTcpSocket*> clientLists;
};

#endif // NETWORKCOMMUNICATION_H
