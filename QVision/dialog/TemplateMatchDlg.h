#ifndef TemplateMatchDlg_H
#define TemplateMatchDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class TemplateMatchDlg:public QDialog
{
    Q_OBJECT
public:
    int getValue();
    void setValue(int val);
    TemplateMatchDlg(QWidget *parent=nullptr);
    static TemplateMatchDlg& ins() {static TemplateMatchDlg s;return s;}
public:
    int thresh;
private slots:
    void onOkClicked();
    void onCancelClicked();
private:
   QLabel *tip;
   QSpinBox *matchThresval;
   QPushButton *okBtn;
   QPushButton *cancelBtn;
};

#endif // TemplateMatchDlg_H
