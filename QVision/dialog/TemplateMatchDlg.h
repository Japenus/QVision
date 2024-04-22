#ifndef TemplateMatchDlg_H
#define TemplateMatchDlg_H
#include <QObject>
#include"tools.h"
#include"global.h"
class TemplateMatchDlg:public QDialog
{
    Q_OBJECT
public:
    TemplateMatchDlg(QWidget *parent=nullptr);
    int getValue();
    void setValue(int val);
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
