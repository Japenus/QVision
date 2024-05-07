#ifndef REMOTELOGIN_H
#define REMOTELOGIN_H
#include"global.h"
class RemoteLogin:public QMainWindow
{
    Q_OBJECT
public:
    RemoteLogin(QWidget *parent = nullptr);
    ~RemoteLogin();
private slots:
    void closeCon();
    void exitApp();
    void buildCon();
    void remoteCon();
    void createRemoteCon();
private:
    QAxWidget *connectedWin;
    QPushButton *buildConn;
    QPushButton *exitLogin;
    QPushButton *remoteConn;
    QPushButton *closeRemote;
};

#endif // REMOTELOGIN_H
