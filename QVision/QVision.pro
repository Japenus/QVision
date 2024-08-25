QT += core gui sql network multimedia multimediawidgets axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17
RC_ICONS = qvision.ico

INCLUDEPATH +=$$PWD/src \
              $$PWD/dialog\
              include \
              include/zbar \
              include/opencv2 \
              include/tesseract\
              include/leptonica \


LIBS +=-L$$PWD/lib -lOpenCV -lLeptonica -lOCR -lZBar -lSort -lDlib


HEADERS += \
    qvision.h \
    barcode/scanner.h \
    algorithm/Sort.h \
    dialog/GuilDlg.h \
    dialog/CannyDlg.h \
    algorithm/Global.h \
    dialog/RenameDlg.h \
    dialog/ResizeDlg.h \
    dialog/BallardDlg.h \
    dialog/RotScaleDlg.h \
    dialog/AreaFillDlg.h \
    dialog/Remotelogin.h \
    dialog/ThresholdDlg.h \
    dialog/CharRecogdlg.h \
    dialog/WriteDataDlg.h \
    dialog/NetSpyderDlg.h \
    dialog/CalcuDistDlg.h \
    dialog/FixThresholdDlg.h \
    dialog/TemplateMatchDlg.h \
    dialog/StatisticPixelDlg.h \
    dialog/UpgradeTempMatchDlg.h \
    src/Api.h \
    src/Sort.h \
    src/Tools.h \
    src/Color.h \
    src/Dialog.h \
    src/Global.h \
    src/Database.h \
    src/Screencut.h \
    # src/Subpixels.h \
    src/DllManager.h \
    src/Preprocess.h \
    src/Multimedia.h \
    src/ImgAlgorithm.h \
    src/Imgcalculate.h \
    src/Dynamicdetect.h \
    src/Fileoperation.h \
    src/Formattransfer.h \
    src/MachineLearning.h \
    src/CoordinateSystem.h \
    src/Networkcommunication.h \
    datastruct/Global.h \
    datastruct/LinkList.h \
    datastruct/BinaryTree.h \

SOURCES += \
    main.cpp \
    qvision.cpp \
    algorithm/Sort.cpp \
    barcode/scanner.cpp \
    dialog/GuilDlg.cpp \
    dialog/CannyDlg.cpp \
    dialog/RenameDlg.cpp \
    dialog/ResizeDlg.cpp \
    dialog/BallardDlg.cpp \
    dialog/Remotelogin.cpp \
    dialog/RotScaleDlg.cpp \
    dialog/AreaFillDlg.cpp \
    dialog/NetSpyderDlg.cpp \
    dialog/WriteDataDlg.cpp \
    dialog/ThresholdDlg.cpp \
    dialog/CalcuDistDlg.cpp \
    dialog/CharRecogdlg.cpp \
    dialog/FixThresholdDlg.cpp \
    dialog/TemplateMatchDlg.cpp \
    dialog/StatisticPixelDlg.cpp \
    dialog/UpgradeTempMatchDlg.cpp \
    src/Tools.cpp \
    src/Database.cpp \
    # src/Subpixels.cpp \
    src/Screencut.cpp \
    src/DllManager.cpp \
    src/Preprocess.cpp \
    src/Multimedia.cpp \
    src/Imgcalculate.cpp \
    src/ImgAlgorithm.cpp \
    src/Dynamicdetect.cpp \
    src/Fileoperation.cpp \
    src/Formattransfer.cpp \
    src/MachineLearning.cpp \
    src/CoordinateSystem.cpp \
    src/Networkcommunication.cpp \
    datastruct/LinkList.cpp \
    datastruct/BinaryTree.cpp \
