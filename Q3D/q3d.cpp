#include "q3d.h"
Q3D::Q3D(QWidget *parent) : QMainWindow(parent)
{
    QMenuBar *menubar=new QMenuBar();
    QMenu *menulist=menubar->addMenu("File");

    QAction *im=new QAction("Import Model",this);
    QAction *ex = new QAction("Export Model",this);
    QAction *exit = new QAction("Exit",this);

    menulist->addAction(im);
    menulist->addAction(ex);
    menulist->addSeparator();

    connect(exit, &QAction::triggered, this, &Q3D::close);
    connect(im,&QAction::triggered,this,&Q3D::importModel);
    connect(ex,&QAction::triggered,this, &Q3D::exportModel);

    menulist->addAction(exit);
    setMenuBar(menubar);

    Qt3DWindow *view= new Qt3DWindow();
    QWidget *displayArea = QWidget::createWindowContainer(view);
    setCentralWidget(displayArea);
    QEntity *root= new QEntity();
    QTorusMesh *torusMesh = new QTorusMesh();
    torusMesh->setRadius(1.0f);
    torusMesh->setMinorRadius(0.3f);
    torusMesh->setSlices(20);
    torusMesh->setRings(20);
    QPhongMaterial *material= new QPhongMaterial();
    material->setDiffuse(QColor(255,0,0));
    Qt3DCore::QTransform *torusTransform=new Qt3DCore::QTransform;
    torusTransform->setScale3D(QVector3D(1.5,1,0.5));
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0),45.0f));
    QEntity *torusEntity=new QEntity(root);
    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusTransform);
    torusEntity->addComponent(material);
    view->setRootEntity(root);
    ShowEntity(view,displayArea,root);
    resize(800,600);
    setWindowTitle("3D Viewer");
}
void Q3D::importModel()
{
    qDebug()<<"Importing model...";
}

void Q3D::exportModel()
{
    qDebug()<<"Exporting model...";
}

void Q3D::ShowEntity(Qt3DWindow* scene,QWidget *parent,QEntity *whatModel)
{
    CameraControl control(scene,whatModel);
    QWidget *container = QWidget::createWindowContainer(scene);
    this->setCentralWidget(container);
    scene->setRootEntity(whatModel);
    scene->resize(800,600);
    scene->show();
}
Q3D::~Q3D()
{

}
