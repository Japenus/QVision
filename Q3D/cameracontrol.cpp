#include "cameracontrol.h"
CameraControl::CameraControl(Qt3DWindow *view,QEntity *scene)
{
    QCamera *camera= view->camera();
    camera->lens()->setPerspectiveProjection(45.0f,16.0f/9.0f,0.1f,1000.0f);
    camera->setPosition(QVector3D(0,0,40.0f));
    camera->setViewCenter(QVector3D(0,0,0));

    QOrbitCameraController *camController= new QOrbitCameraController(scene);
    camController->setLinearSpeed(50.0f);
    camController->setLookSpeed(180.0f);
    camController->setCamera(camera);
    view->setRootEntity(scene);
    view->show();
}
