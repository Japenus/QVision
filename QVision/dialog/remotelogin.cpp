#include "remotelogin.h"
RemoteLogin::RemoteLogin(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("ico.png");
    QMenuBar *menubar = new QMenuBar;
    QMenu *list = menubar->addMenu("Tool");
    QAction *createConn = new QAction("Create");
    list->addSeparator();
    list->addAction(createConn);
    setMenuBar(menubar);
    /*how to get CLSID（Class Identifier）
     *Win + R,regedit;
     *HKEY_CLASSES_ROOT\CLSID
    */
    remoteDesk = new QAxWidget;
    remoteDesk->setControl("{8b918b82-7985-4c24-89df-c33ad2bbfbcd}");
    remoteConn = new QPushButton("远程连接");
    closeRemote = new QPushButton("关闭远程");
    exitLogin = new QPushButton("关闭窗口");
    buildConn = new QPushButton("建立连接");

    remoteConn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: pink;border-radius: 5px;font-weight: bold;");
    closeRemote->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: pink;border-radius: 5px;font-weight: bold;");
    exitLogin->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: pink;border-radius: 5px;font-weight: bold;");
    buildConn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: pink;border-radius: 5px;font-weight: bold;");
    remoteDesk->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: pink;border-radius: 5px;font-weight: bold;");

    QVBoxLayout *MainStruct = new QVBoxLayout;
    QHBoxLayout *Row1 = new QHBoxLayout;
    QHBoxLayout *Row2 = new QHBoxLayout;

    QWidget *central = new QWidget;

    Row1->addWidget(remoteConn);Row1->addWidget(buildConn);
    Row2->addWidget(closeRemote);Row2->addWidget(exitLogin);

    MainStruct->addWidget(remoteDesk);
    MainStruct->addLayout(Row1);MainStruct->addLayout(Row2);
    MainStruct->setStretch(0, 10);

    central->setLayout(MainStruct);
    setCentralWidget(central);

    connect(createConn,&QAction::triggered,this,&RemoteLogin::createRemoteCon);
    connect(remoteConn, &QPushButton::clicked, this, &RemoteLogin::remoteCon);
    connect(closeRemote, &QPushButton::clicked, this, &RemoteLogin::closeCon);
    connect(exitLogin, &QPushButton::clicked, this, &RemoteLogin::exitApp);
    connect(buildConn, &QPushButton::clicked, this, &RemoteLogin::buildCon);

    remoteDesk->show();
    resize(600, 400);
    setWindowIcon(icon);
    setWindowTitle("Remote Login");
}



void RemoteLogin::buildCon()
{
    // QString host = QInputDialog::getText(this, "", "主机名:");
    QString computerName = QInputDialog::getText(this, "", "主机名:");
    // QString password = QInputDialog::getText(this, "", "密码:", QLineEdit::Password);
    QProcess mstscProcess;
    QStringList arguments;
    arguments << "/v:" + computerName;
    mstscProcess.start("mstsc", arguments);
    if (!mstscProcess.waitForStarted()||!mstscProcess.waitForFinished()) {
        QMessageBox::information(nullptr, "", "建立连接失败!");
        return;
    }else{
        QMessageBox::warning(nullptr, "", "远程桌面连接成功!");
        return;
    }
}

void RemoteLogin::remoteCon()
{

}

void RemoteLogin::createRemoteCon()
{
    if(remoteDesk->isNull()){
        qInfo()<<"初始化失败!";
        return;
    }
    QString computerIp = QInputDialog::getText(this, "", "计算机地址:");
    QString userName = QInputDialog::getText(this, "", "用户名:");
    QString passWord = QInputDialog::getText(this, "", "密码:", QLineEdit::Password);
    remoteDesk->setProperty("Server",computerIp);
    remoteDesk->setProperty("UserName", userName);
    remoteDesk->setProperty("ClearTextPassword", passWord);
    remoteDesk->dynamicCall("Connect()");
}

RemoteLogin::~RemoteLogin()
{
    delete remoteDesk;
    delete buildConn;
    delete exitLogin;
    delete remoteConn;
    delete closeRemote;
}


void RemoteLogin::exitApp()
{
    this->close();
}


void RemoteLogin::closeCon()
{
    remoteDesk->close();
}
