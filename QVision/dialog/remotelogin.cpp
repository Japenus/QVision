#include "remotelogin.h"
RemoteLogin::RemoteLogin(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("Spyder.png");
    QMenuBar *menubar = new QMenuBar();
    QMenu *list = menubar->addMenu("Tool");
    QAction *createConn = new QAction("Create", this);
    list->addSeparator();
    list->addAction(createConn);
    setMenuBar(menubar);
    QRect DeviceSize = QGuiApplication::screens().at(0)->geometry();
    int w = DeviceSize.width();
    int h = DeviceSize.height();

    /*how to get CLSID（Class Identifier）
     *Win + R,regedit;
     *HKEY_CLASSES_ROOT\CLSID
    */
    connectedWin = new QAxWidget();
    connectedWin->setControl("{8b918b82-7985-4c24-89df-c33ad2bbfbcd}");
    connectedWin->setProperty("DesktopWidth", 800);
    connectedWin->setProperty("DesktopHeight", 600);

    remoteConn = new QPushButton("远程连接");
    closeRemote = new QPushButton("关闭远程");
    exitLogin = new QPushButton("退出登录");
    buildConn = new QPushButton("建立连接");

    remoteConn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    closeRemote->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    exitLogin->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    buildConn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    connectedWin->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");

    QVBoxLayout *MainStruct = new QVBoxLayout;
    QHBoxLayout *Row1 = new QHBoxLayout;
    QHBoxLayout *Row2 = new QHBoxLayout;

    QWidget *central = new QWidget;

    Row1->addWidget(remoteConn);Row1->addWidget(buildConn);
    Row2->addWidget(closeRemote);Row2->addWidget(exitLogin);

    MainStruct->addWidget(connectedWin);
    MainStruct->addLayout(Row1);MainStruct->addLayout(Row2);
    MainStruct->setStretch(0, 10);

    central->setLayout(MainStruct);
    setCentralWidget(central);

    connect(createConn,&QAction::triggered,this,&RemoteLogin::createRemoteCon);
    connect(remoteConn, &QPushButton::clicked, this, &RemoteLogin::remoteCon);
    connect(closeRemote, &QPushButton::clicked, this, &RemoteLogin::closeCon);
    connect(exitLogin, &QPushButton::clicked, this, &RemoteLogin::exitApp);
    connect(buildConn, &QPushButton::clicked, this, &RemoteLogin::buildCon);

    resize(w / 2, h / 2);
    setWindowIcon(icon);
    setWindowTitle("Remote Connection");
}

RemoteLogin::~RemoteLogin()
{

}

void RemoteLogin::closeCon()
{
    connectedWin->clear();
}

void RemoteLogin::exitApp()
{
    this->close();
}

void RemoteLogin::buildCon()
{
    QString host = QInputDialog::getText(this, "远程登录", "主机名:");
    QString computerName = QInputDialog::getText(this, "远程登录", "用户名:");
    QString password = QInputDialog::getText(this, "远程登录", "密码:", QLineEdit::Password);
    QProcess mstscProcess;
    QStringList arguments;
    arguments << "/v:" + computerName;
    mstscProcess.start("mstsc", arguments);

    if (!mstscProcess.waitForStarted()) {
        QMessageBox::information(nullptr, "提示", "创建mstsc进程失败!");
        return;
    }

    if (!mstscProcess.waitForFinished()) {
        QMessageBox::information(nullptr, "提示", "无法完成mstsc进程!");
        return;
    }else{
        QMessageBox::information(nullptr, "提示", "远程桌面连接成功!");
    }
}

void RemoteLogin::remoteCon()
{

}

void RemoteLogin::createRemoteCon()
{
    if(connectedWin->isNull()){
        qInfo()<<"初始化失败!";
        return;
    }
    QString computerIp = QInputDialog::getText(this, "远程登录", "计算机地址:");
    QString userName = QInputDialog::getText(this, "远程登录", "用户名:");
    QString passWord = QInputDialog::getText(this, "远程登录", "密码:", QLineEdit::Password);
    connectedWin->setProperty("Server",computerIp);
    connectedWin->setProperty("UserName", userName);
    connectedWin->setProperty("ClearTextPassword", passWord);
    connectedWin->dynamicCall("Connect()");
}
