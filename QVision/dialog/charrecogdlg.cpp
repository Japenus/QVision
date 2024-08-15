#include "charrecogdlg.h"

CharRecogDlg::CharRecogDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    SherryToJerry="To 我最爱的男孩\n"
        "       这是一封新年就开始写的信，但提笔的瞬间却又不知从何说起，"
        "我们平常的相处感觉也是两个人倾心交流了很多很多次，"
        "从我们的从前、我们的现在到我们的未来，其实我真的真的很庆幸能够遇见你，"
        "我说过很多很多次我觉得你是上天给我的礼物，是一份我期待了很久很久的礼物。"
        "在这个新年伊始，首先感谢我们顺利度过了2023年的时光，"
        "2023这一年的时光对我来说其实是冲击很大、挑战很大的一年，也算是经历了人生中的大起大落，"
        "虽然可能对你来说很多事情并没有那么惊天动地，但对我来说也是一种经历，"
        "但是起起落落、超退潮张这才是人生常态，我也很庆幸，在2023的尾巴遇见了你，"
        "我知道你不相信什么玄学神话，但我依旧很感谢冥冥之中的缘分让我们相遇，"
        "如果说你是上天2023年苦尽甘来的礼物，那我也很希望我可以永远拥有并珍惜这样的感情，"
        "当然我也希望你可以把我当成生命中最重要的人之一，我也希望我对于你而言也是一份珍贵的礼物。"
        "其实，一想到你，我的记忆就好像照片一样，对于你的感觉，"
        "像是南头古城那颗阳光下的大榕树，是红树湾公园桥墩旁的拥吻，"
        "是夜晚牵着两只手漫步在深圳的大街小巷，是在广州塔下你的侧脸，"
        "也是家里的瓶瓶罐罐茶米油盐，是我做的第一顿糖醋排骨，是一个个漫漫长夜你的怀抱，"
        "一想到这些我的泪水就有点无法停止，原谅我始终没办法做一个不掉眼泪的成熟大人，"
        "只是一想到我们所拥有的幸福时刻我就觉得人有时候只活这几个瞬间，"
        "是一个个温馨感动的瞬间组成了我们无法复刻，无人可以代替的人生，也原谅我很贪婪，"
        "贪婪到想要和你共享余生中每一个惊喜与每一份幸福，我想要你身边无可取代的位置，"
        "和你毫无保留的爱，一句句新年快乐的含义是希望今后你的年年岁岁与我一起快快乐乐，幸福平安。"
        "新的一年，我们还会一起看很多很多的风景，一起牵手走过很多很多的路，"
        "也会遇到很多很多困难，但我相信只要你牵紧我的手，我们一起面对，一起思考，"
        "一起学习，没有什么会是困难的，再次祝你——我的宝贝、我最心爱的男孩，新年快乐、万事顺遂，"
        "一切越来越好!\n"
        "                                                                       From \n"
        "                                                                       你最爱的宝贝";
    tip1=new QLabel("图片");
    tip2=new QLabel("结果");

    DisplayPic=new QLabel(this);
    ShowResult=new QTextEdit(this);
    ShowResult->setReadOnly(true);
    ShowResult->setText(SherryToJerry);

    DisplayPic->setMinimumSize(400,300);
    DisplayPic->setMaximumSize(800,600);
    ShowResult->setMinimumSize(400,300);
    ShowResult->setMaximumSize(800,600);

    getPicBtn=new QPushButton("Open");
    makeBigBtn=new QPushButton("Show");
    recogBtn=new QPushButton("Recognize");
    clearBtn=new QPushButton("Clear");
    saveTxtBtn=new QPushButton("Save");
    exitBtn=new QPushButton("Exit");

    tip1->setAlignment(Qt::AlignCenter);
    tip2->setAlignment(Qt::AlignCenter);
    tip1->setStyleSheet("border:1px solid purple;padding: 5px;color: green;border-radius: 5px;font-weight: bold;font-weight: bold;");
    tip2->setStyleSheet("border:1px solid purple;padding: 5px;color: green;border-radius: 5px;font-weight: bold;font-weight: bold;");
    DisplayPic->setStyleSheet("border:1px solid purple; padding: 5px;border-radius: 5px;font-weight: bold;");
    ShowResult->setStyleSheet("border:1px solid purple; padding: 5px;border-radius: 5px;font-weight: bold;");
    getPicBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: "+color1+";border-radius: 10px;font-weight: bold;");
    recogBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: "+color1+";border-radius: 10px;font-weight: bold;");
    exitBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: "+color1+";border-radius: 10px;font-weight: bold;");
    makeBigBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: "+color1+";border-radius: 10px;font-weight: bold;");
    saveTxtBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: "+color1+";border-radius: 10px;font-weight: bold;");
    clearBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: "+color1+";border-radius: 10px;font-weight: bold;");


    QVBoxLayout *MainStruct = new QVBoxLayout();
    QHBoxLayout *subRow1 = new QHBoxLayout();
    QHBoxLayout *subRow2 = new QHBoxLayout();
    QHBoxLayout *btnRow = new QHBoxLayout();

    subRow1->addWidget(tip1);subRow1->addWidget(tip2);
    subRow2->addWidget(DisplayPic);subRow2->addWidget(ShowResult);

    btnRow->addWidget(getPicBtn);
    btnRow->addWidget(makeBigBtn);
    btnRow->addWidget(recogBtn);
    btnRow->addWidget(clearBtn);
    btnRow->addWidget(saveTxtBtn);
    btnRow->addWidget(exitBtn);

    MainStruct->addLayout(subRow1);
    MainStruct->addLayout(subRow2);
    MainStruct->addLayout(btnRow);
    setLayout(MainStruct);

    connect(getPicBtn, &QPushButton::clicked, this,&CharRecogDlg::getPicture);
    connect(makeBigBtn, &QPushButton::clicked, this,&CharRecogDlg::MakeBig);
    connect(recogBtn,&QPushButton::clicked, this,&CharRecogDlg::Recognize);
    connect(clearBtn,&QPushButton::clicked, this,&CharRecogDlg::Clean);
    connect(saveTxtBtn,&QPushButton::clicked, this,&CharRecogDlg::SaveText);
    connect(exitBtn,&QPushButton::clicked, this,&CharRecogDlg::ShutDown);

    resize(800,600);
    setWindowTitle("Character Recognition");
}

QString CharRecogDlg::getPath()
{
    return picPath;
}

void CharRecogDlg::setPath(QString pic)
{
    picPath=pic;
}

void CharRecogDlg::getPicture()
{
    QString imgPath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.jpg *.bmp)"));
    setPath(imgPath);
    charImg=imread(imgPath.toStdString());
    if (!imgPath.isEmpty())
    {
        QImage img(imgPath);
        if (!img.isNull())
        {
            DisplayPic->setPixmap(QPixmap::fromImage(img).scaled(DisplayPic->size(),Qt::KeepAspectRatio));
        }
    }
}

void CharRecogDlg::MakeBig()
{
    Tools::ins().MakeBig(charImg);
}

void CharRecogDlg::Recognize()
{
    QMessageBox select;
    select.setText("请选择识别类型");
    QPushButton *qrCode = select.addButton(tr("二维码"), QMessageBox::ActionRole);
    QPushButton *barCode = select.addButton(tr("条形码"), QMessageBox::ActionRole);
    QPushButton *imgChar = select.addButton(tr("字符"), QMessageBox::ActionRole);
    select.exec();
    if (select.clickedButton() == qrCode){
        ShowResult->setText(Tools::ins().recognizeQRCode(charImg));
    }else if (select.clickedButton() == imgChar){
        ShowResult->setText(Tools::ins().CharRecognize(picPath));
    }else if(select.clickedButton() == barCode){
        ShowResult->setText(Tools::ins().recognizeBarCode(charImg));
    }
}

void CharRecogDlg::Clean()
{
    ShowResult->clear();
}
void CharRecogDlg::SaveText()
{
    QString recog=ShowResult->toPlainText();
    QString outputRes = QFileDialog::getSaveFileName(this, tr("Save Result"), "", tr("Texts (*.txt *.res)"));
    if (!outputRes.isEmpty()){
        QFile file(outputRes);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << recog;
            file.close();
        }
    }
}

void CharRecogDlg::ShutDown()
{
    reject();
}
