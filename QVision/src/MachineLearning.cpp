#include "MachineLearning.h"

MachineLearning::MachineLearning(QWidget *parent):QMainWindow(parent)
{
    QIcon icon("ico.png");
    setWindowIcon(icon);
    QMenuBar *menubar = new QMenuBar();
    QAction *start = new QAction("Start");
    QMenu *menulist = menubar->addMenu("Option");
    menulist->addSeparator();
    menulist->addAction(start);
    setMenuBar(menubar);
    setWindowTitle("Machine Learning");
}

MachineLearning::~MachineLearning()
{

}
