#ifndef CHARRECOGDLG_H
#define CHARRECOGDLG_H
#include <QObject>
#include "tools.h"
#include "global.h"
class CharRecogDlg:public QDialog
{
    Q_OBJECT
public:
    QString picPath;
    QString getPath();
    void setPath(QString pic);
    CharRecogDlg(QWidget *parent=nullptr);
    static CharRecogDlg& ins(){static CharRecogDlg g;return g;}
private slots:
    void Clean();
    void MakeBig();
    void SaveText();
    void ShutDown();
    void Recognize();
    void getPicture();
private:
    Mat charImg;
    QLabel *tip1;
    QLabel *tip2;
    QLabel *DisplayPic;
    QTextEdit *ShowResult;
    QPushButton *getPicBtn;
    QPushButton *makeBigBtn;
    QPushButton *saveTxtBtn;
    QPushButton *clearBtn;
    QPushButton *recogBtn;
    QPushButton *exitBtn;
    QString color1="green";
    QString SherryToJerry;
};
#endif // CHARRECOGDLG_H
