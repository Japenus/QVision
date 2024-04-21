#include "networkcommunication.h"
NetworkCommunication::NetworkCommunication(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("Spyder.png");
    QMenuBar *menubar = new QMenuBar();
    QMenu *menulist = menubar->addMenu("Operation");
    QAction *start = new QAction("Start Server");
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

    clientIP->setCurrentText("localhost");
    clientPort->setText("2222");

    sendData=new QTextEdit();
    recvData=new QTextEdit();
    curStatus=new QTextEdit();
    connectBtn = new QPushButton("连接");
    disconnectBtn = new QPushButton("断开");
    sendBtn = new QPushButton("发送");
    stopBtn = new QPushButton("停止");
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
    clientPort->setStyleSheet("border: 1px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
    serverIP->setStyleSheet("border: 1px solid rgb(25, 25, 112);color: blue;border-radius: 5px;font-weight: bold;");
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
    connect(sendBtn,&QPushButton::clicked,this,&NetworkCommunication::senData);
    connect(connectBtn,&QPushButton::clicked,this,&NetworkCommunication::connected);
    connect(disconnectBtn,&QPushButton::clicked,this,&NetworkCommunication::disconnected);
    connect(stopBtn,&QPushButton::clicked,this,&NetworkCommunication::stopped);

    resize(w/2,h/2);
    setWindowIcon(icon);
    setWindowTitle("Network Communication");
}
void NetworkCommunication::createServer()
{
    int listenPort = serverPort->text().toInt();
    QHostAddress serverAddress = QHostAddress::Any;
    serverAddress.setAddress(serverIP->currentText());
    QTcpServer *server = new QTcpServer(this);
    if(!server->listen(serverAddress, listenPort)){
        curStatus->setText("服务器启动失败!");
        return;
    }
    if(serverIP->currentText()!=""||serverPort->text()!=""){
        curStatus->setText("服务器已启动!监听端口号:"+QString::number(listenPort));
        connect(server, &QTcpServer::newConnection, this, &NetworkCommunication::connected);
    }else{
        curStatus->setText("服务器不明确!");
    }
}


void NetworkCommunication::senData()
{

}

void NetworkCommunication::connected()
{
    QTcpServer server = qobject_cast<QTcpServer>(sender());
    if(!server.isListening()) return;
    QTcpSocket *socket = server.nextPendingConnection();
    if(socket->waitForConnected(300)){
        curStatus->setText("连接成功!");
    } else {
        curStatus->setText("连接失败,ip地址:"/*+ip+"端口号:"+QString::number(port)*/);
    }
}

void NetworkCommunication::disconnected()
{
    QTcpSocket socket = qobject_cast<QTcpSocket>(sender());
    if(socket.bind()){
        socket.disconnectFromHost();
        socket.close();
        curStatus->setText("连接已断开！");
    }
}

void NetworkCommunication::stopped()
{
    this->close();
}
