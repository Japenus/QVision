#ifndef MACHINELEARNING_H
#define MACHINELEARNING_H

#include <Global.h>
class MachineLearning:public QMainWindow
{
public:
    MachineLearning(QWidget *parent=nullptr);
    ~MachineLearning();
    static MachineLearning & ins(){static MachineLearning m;return m;}
};

#endif // MACHINELEARNING_H
