#include "networkcommunication.h"
NetworkCommunication::NetworkCommunication(QWidget *parent):QMainWindow(parent)
{
    tcpServer = new QTcpServer(this);
    Socket = new QTcpSocket();
    QIcon icon("Spyder.png");
    curTime = QDateTime::currentDateTime();
    formatted = curTime.toString("yyyy-MM-dd hh:mm:ss");
    QMenuBar *menubar = new QMenuBar();
    QAction *start = new QAction("Start Server");
    QMenu *menulist = menubar->addMenu("Operation");
    menulist->addSeparator();
    menulist->addAction(start);
    setMenuBar(menubar);
    QRect DeviceSize=QGuiApplication::screens().at(0)->geometry();
    int w=DeviceSize.width();
    int h=DeviceSize.height();
    tip1=new QLabel("客户端");
    tip2=new QLabel("服务器");
    tip3=new QLabel("客户端IP:");
    tip4=new QLabel("端口:");
    tip5=new QLabel("服务器IP:");
    tip6=new QLabel("端口:");

    clientIP=new QComboBox;
    serverIP=new QComboBox;
    clientPort=new QLineEdit;
    serverPort=new QLineEdit;

    clientIP->setEditable(true);
    serverIP->setEditable(true);

    clientPort->setText("1234");
    clientIP->setCurrentText("127.0.0.1");

    serverPort->setText("1234");
    serverIP->setCurrentText("127.0.0.1");

    sendData=new QTextEdit();
    recvData=new QTextEdit();
    curStatus=new QTextEdit();
    sendBtn = new QPushButton("发送");
    stopBtn = new QPushButton("关闭");
    connectBtn = new QPushButton("连接");
    disconnectBtn = new QPushButton("断开");
    tip1->setAlignment(Qt::AlignCenter);
    tip2->setAlignment(Qt::AlignCenter);

    tip3->setFixedWidth(80);
    tip4->setFixedWidth(80);
    tip5->setFixedWidth(80);
    tip6->setFixedWidth(80);
    curStatus->setFixedHeight(30);
    tip1->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    tip2->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    tip3->setStyleSheet("border: 2px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    tip4->setStyleSheet("border: 2px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    tip5->setStyleSheet("border: 2px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    tip6->setStyleSheet("border: 2px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    connectBtn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    disconnectBtn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    sendBtn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    stopBtn->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");

    sendData->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    recvData->setStyleSheet("border: 2px solid rgb(25, 25, 112);padding: 5px;color: blue;border-radius: 5px;font-weight: bold;");
    clientIP->setStyleSheet("border: 1px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    serverIP->setStyleSheet("border: 1px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    clientPort->setStyleSheet("border: 1px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    serverPort->setStyleSheet("border: 1px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");

    QVBoxLayout *DisplayGui =new QVBoxLayout;
    QHBoxLayout *MainStruct =new QHBoxLayout;
    QVBoxLayout *MainLeft =new QVBoxLayout;
    QVBoxLayout *MainRight =new QVBoxLayout;
    QVBoxLayout *TopCol1 =new QVBoxLayout;
    QVBoxLayout *TopCol2 =new QVBoxLayout;
    QHBoxLayout *Row1 = new QHBoxLayout;
    QHBoxLayout *Row2 = new QHBoxLayout;
    QHBoxLayout *Row3 = new QHBoxLayout;
    QHBoxLayout *Row4 = new QHBoxLayout;
    QHBoxLayout *btnRow = new QHBoxLayout;
    QWidget *central=new QWidget;

    Row1->addWidget(tip3);Row1->addWidget(clientIP);
    Row2->addWidget(tip4);Row2->addWidget(clientPort);
    Row3->addWidget(tip5);Row3->addWidget(serverIP);
    Row4->addWidget(tip6);Row4->addWidget(serverPort);
    btnRow->addWidget(connectBtn);btnRow->addWidget(disconnectBtn);
    btnRow->addWidget(sendBtn);btnRow->addWidget(stopBtn);

    TopCol1->addWidget(tip1);TopCol1->addLayout(Row1);TopCol1->addLayout(Row2);
    TopCol2->addWidget(tip2);TopCol2->addLayout(Row3);TopCol2->addLayout(Row4);

    MainLeft->addLayout(TopCol1);MainLeft->addWidget(sendData);
    MainRight->addLayout(TopCol2);MainRight->addWidget(recvData);

    MainStruct->addLayout(MainLeft);MainStruct->addLayout(MainRight);

    DisplayGui->addLayout(MainStruct);
    DisplayGui->addWidget(curStatus);
    DisplayGui->addLayout(btnRow);

    central->setLayout(DisplayGui);
    setCentralWidget(central);

    connect(start,&QAction::triggered,this,&NetworkCommunication::createServer);
    connect(sendBtn,&QPushButton::clicked,this,&NetworkCommunication::send);
    connect(connectBtn,&QPushButton::clicked,this,&NetworkCommunication::connected);
    connect(disconnectBtn,&QPushButton::clicked,this,&NetworkCommunication::disconnected);
    connect(stopBtn,&QPushButton::clicked,this,&NetworkCommunication::stopped);

    resize(w/2,h/2);
    setWindowIcon(icon);
    setWindowTitle("Network Communication");
}

void NetworkCommunication::log()
{
    QString logs = "loginfo.txt";
    QFile file(logs);
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << info << "\n";
        file.close();
    }
}


void NetworkCommunication::createServer()
{
    listenPort = serverPort->text().toInt();
    ipAddress = QHostAddress::Any;
    ipAddress.setAddress(serverIP->currentText());
    if(!tcpServer->listen(ipAddress, listenPort)){
        info="<"+formatted+">服务器启动失败";
        curStatus->setText(info);
        log();
        return;
    }
    if(serverIP->currentText()!="" && serverPort->text()!=""){
        info="<"+formatted+">服务器已启动,监听端口号:"+QString::number(listenPort);
        curStatus->setText(info);
        connect(tcpServer, &QTcpServer::newConnection, this, &NetworkCommunication::connected);
        log();
    }else{
        info="<"+formatted+">服务器不明确!";
        curStatus->setText(info);
        log();
    }
}


void NetworkCommunication::send()
{
    QString str = sendData->toPlainText().toLatin1().toLower();
    if (connCount&&Socket->isOpen())
    {
        if(!str.isEmpty()){
            QByteArray sendData = str.toUtf8();
            Socket->write(sendData, sendData.size());
            QString oldData = recvData->toPlainText();
            info = oldData + "\n" + "<" + formatted + ">" + str;
            recvData->setText(info);
        }else{
            info="<"+formatted+">不能发送空消息!";
            curStatus->setText(info);
        }
    }else{
        info="<"+formatted+">连接已断开,发送失败!";
        sendData->setText("");
        curStatus->setText(info);
    }
    log();
}

void NetworkCommunication::connected()
{
    ipAddress.setAddress(serverIP->currentText());
    if (Socket->isOpen()) Socket->close();
    uint16_t port=serverPort->text().toUShort();
    Socket->connectToHost(ipAddress, port);
    if (!Socket->waitForConnected(600))
    {
        info="<"+formatted+">连接失败!";
        curStatus->setText(info);
        log();
        return;
    }else{
        info="<"+formatted+">连接成功!";
        curStatus->setText(info);
        info= "<"+formatted+">客户端已登录";
        recvData->setText(info);
        connCount++;
        log();
    }
}

void NetworkCommunication::disconnected()
{
    if(Socket->isOpen()){
        Socket->disconnectFromHost();
        Socket->close();
        info="<"+formatted+">连接已断开！";
        curStatus->setText(info);
        info="<"+formatted+">客户端退出";
        recvData->setText(info);
    }else{
        info="<"+formatted+">无连接!";
        curStatus->setText(info);
    }
}

//not work
void NetworkCommunication::keyPressEvent(QKeyEvent *event)
{
    if(Socket->isOpen() && !sendData->toPlainText().toLatin1().toLower().isEmpty())
    {
        if (event->key() == Qt::Key_Enter || event->key() ==Qt::Key_Return){
            QByteArray msg = sendData->toPlainText().toUtf8();
            Socket->write(msg);
        }
    }else{
        return;
    }
}

void NetworkCommunication::stopped()
{
    this->close();
}

NetworkCommunication::~NetworkCommunication()
{
    log();
}
