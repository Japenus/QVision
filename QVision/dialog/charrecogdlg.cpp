#include "charrecogdlg.h"

CharRecogDlg::CharRecogDlg(QWidget *parent):QDialog(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    tip1=new QLabel("图片");
    tip2=new QLabel("结果");

    DisplayPic=new QLabel(this);
    ShowResult=new QTextEdit(this);

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
    getPicBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    recogBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    exitBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    makeBigBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    saveTxtBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");
    clearBtn->setStyleSheet("border:1px solid purple;padding: 5px;color: blue;border-radius: 10px;font-weight: bold;");


    QVBoxLayout *MainStruct = new QVBoxLayout(this);
    QHBoxLayout *subRow1 = new QHBoxLayout(this);
    QHBoxLayout *subRow2 = new QHBoxLayout(this);
    QHBoxLayout *btnRow = new QHBoxLayout(this);

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

    resize(600,400);
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
    ShowResult->setText(Tools::ins().CharRecognize(picPath));
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
