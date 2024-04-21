#ifndef Q3D_H
#define Q3D_H
#include "global.h"
#include "cameracontrol.h"
class Q3D : public QMainWindow
{
    Q_OBJECT

public:
    Q3D(QWidget *parent = nullptr);
    ~Q3D();
    void ShowEntity(Qt3DWindow* scene,QWidget *parent,QEntity *whatModel);
private slots:
    void importModel();
    void exportModel();
};
#endif // Q3D_H
