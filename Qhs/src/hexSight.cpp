#include "hexSight.h"

hexSight::hexSight()
{
    hsImg=hsDB.AddView("Acquisition")->AddImage("GreyImage");
    hsImg->SetImageCoordinateSystemType(HSImage::hsLeftHanded);
    locator.SetDatabase(hsDB.GetHandle());
    locator.SetInputGreyScaleImageView("Acquisition");
    locator.SetInputGreyScaleImage("GreyImage");
    locator.SetUnitsOrientation(HSLocator::hsDegree);
    locator.SetMaximumInstanceCountEnabled(true);
    locator.SetMaximumInstanceCount(1);

    //search attributes
    locator.SetNominalRotationEnabled(false);
    locator.SetMinimumRotation(-10.0);
    locator.SetMaximumRotation(10.0);
    locator.SetNominalRotation(0.0);

    locator.SetNominalScaleFactorEnabled(false);
    locator.SetMinimumScaleFactor(static_cast<float>(0.8));
    locator.SetMaximumScaleFactor(static_cast<float>(1.2));
    locator.SetNominalScaleFactor(static_cast<float>(1.0));

    locator.SetTimeoutEnabled(true);
    locator.SetTimeout(500);


    // Transform Attributes
    locator.SetModelBasedMinimumScaleFactor(static_cast<float>(0.8));
    locator.SetModelBasedMaximumScaleFactor(static_cast<float>(1.2));
    locator.SetModelBasedMinimumRotation(-10);
    locator.SetModelBasedMaximumRotation(10);
    locator.SetModelDisambiguationEnabled(true);
    locator.SetToolUseEntireImage(false);
    locator.SetToolRotation(0);
}

void hexSight::createModel(const QImage&img,const QString &name,QPointF &pnt,QRectF &roi)
{
    attachImage(img);
    locator.NewModelDatabase();
    locator.AddModel("model");
    int idx=locator.GetModelIndex("model");
    model=locator.GetModel(idx);
    model.SetBoundingAreaTop(roi.top());
    model.SetBoundingAreaRight(roi.right());
    model.SetBoundingAreaBottom(roi.bottom());
    model.SetBoundingAreaLeft(roi.left());

    model.SetOriginPositionX(pnt.x());
    model.SetOriginPositionY(pnt.y());
    model.SetOriginRotation(0);
    model.SetAutomaticLevels(true);
    model.SetFeatureSelection(HSModel::hsFeatureSelectionLess);
    model.SetContrastThresholdMode(HSModel::hsContrastThresholdAdaptiveNormalSensitivity);
    model.Build();
    model.Crop();
    const char *modelName = name.toLocal8Bit().constData();
    locator.SaveModelDatabase(modelName,false);
    inited=true;
}

void hexSight::loadModel(const QString &name)
{
    const char *modelName = name.toLocal8Bit().constData();
    if (!QFile(modelName).exists()) {
        locator.NewModelDatabase();
        return;
    }
    if(strcmp(modelName,locator.GetModelDatabaseFileName())){
        locator.LoadModelDatabase(modelName);
    }
}


void hexSight::applyModel(const QImage &img, qreal percent, qreal dx, qreal dy,QVector<qreal> &res)
{
    attachImage(img);
    locator.SetMinimumModelPercentage(percent);
    locator.SetToolPositionX(img.width()/2);
    locator.SetToolPositionY(img.height()/2);
    locator.SetToolWidth(img.width()*dx);
    locator.SetToolHeight(img.height()*dy);

    locator.ClearResults();
    locator.Execute();
    int count=locator.GetInstanceCount();
    if(count>0){
        res.append(locator.GetInstanceTranslationX(0));
        res.append(locator.GetInstanceTranslationY(0));
        res.append(locator.GetInstanceRotation(0));
        res.append(locator.GetInstanceScaleFactor(0));
    }else{
        qInfo("locate failed！");
    }
}

void hexSight::attachImage(const QImage &img)
{
    if(hsImg->GetWidth()!=img.width()||hsImg->GetHeight()!=img.height()) hsImg->SetSize(img.width(),img.height());
    hsImg->SetRawImagePointer((void *)img.bits());
}


void hexSight::hsImageToQImage(HSImage src, QImage &dst)
{
    if(src.GetType()==HSImage::hsImage8bppGreyScale){
        dst=QImage(src.GetWidth(),src.GetHeight(),QImage::Format_Grayscale8);
    }else if(src.GetType()==HSImage::hsImage16bppGreyScale){
        dst=QImage(src.GetWidth(),src.GetHeight(),QImage::Format_Grayscale16);
    }else if(src.GetType()==HSImage::hsImage32bppRgb){
        dst=QImage(src.GetWidth(),src.GetHeight(), QImage::Format_RGB32);
    }else{
        qInfo()<<"Wrong Image Format";
    }
}

void hexSight::displayContours(const QImage src)
{
    int edgel;
    attachImage(src);
    hsScene=model.GetSceneOutline();
    hsScene.SetName("Contours");
    hsScene.SetSize(src.width(),src.height());
    hsScene.SetUnitsLength(HSScene::hsMillimeter);
    hsScene.SetImageCoordinateSystemType(HSScene::hsLeftHanded);
    edgel=hsScene.GetEdgelCount();

    if(inited&&edgel>0){
        for(int i=0;i<edgel;i++){
            QPoint edgelP;
            edgelP.setX(hsScene.GetEdgelWorldX(i));
            edgelP.setY(hsScene.GetEdgelWorldY(i));
            edgelPnts.append(edgelP);
        }
    }
}
