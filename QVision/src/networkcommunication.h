#ifndef NETWORKCOMMUNICATION_H
#define NETWORKCOMMUNICATION_H
#include "global.h"
class NetworkCommunication:public QMainWindow
{
public:
    NetworkCommunication(QWidget *parent = nullptr);
    ~NetworkCommunication();
    void log();
    static NetworkCommunication & ins(){static NetworkCommunication n;return n;}
protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void send();
    void stopped();
    void sysInfo();
    void connected();
    void clearHistory();
    void createServer();
    void disconnected();
    void exeInstruction();
private:
    int listenPort=80;
    QString info;
    QString formatted;
    QDateTime curTime;
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
    QPushButton *exeBtn;
    QPushButton *cleanBtn;
    QPushButton *connectBtn;
    QPushButton *disconnectBtn;

    QTextEdit *sendData;
    QTextEdit *recvData;
    QTextEdit *curStatus;

    QTcpSocket *Socket;
    QTcpServer *tcpServer;
    QHostAddress ipAddress;
    QList<QTcpSocket*> clientLists;
};

#endif // NETWORKCOMMUNICATION_H
