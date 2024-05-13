#ifndef ResizeDlg_H
#define ResizeDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class ResizeDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue(int which);
    void setValue(int a,int b);
    ResizeDlg(QWidget *parent=nullptr);
    static ResizeDlg& ins(){static ResizeDlg g;return g;}
public:
    int w;
    int h;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
    QSpinBox *widthBox;
    QSpinBox *heightBox;
    QLabel *tip1;
    QLabel *tip2;
    QPushButton *okBtn;
    QPushButton*cancelBtn;
};

#endif // ResizeDlg_H
