QT += core gui sql network multimedia multimediawidgets axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# CONFIG += warn_off
# QMAKE_CXXFLAGS += -Wall
# QMAKE_CXXFLAGS += -Wno-comment

INCLUDEPATH +=$$PWD/src \
              $$PWD/dialog \
              include/opencv2 \
              include/tesseract \
              include/leptonica \


LIBS +=-L$$PWD/lib -lopencv_world480 -lleptonica-1.84.0 -ltesseract53


HEADERS += \
    qvision.h \
    dialog/GuilDlg.h \
    dialog/CannyDlg.h \
    dialog/RenameDlg.h \
    dialog/ResizeDlg.h \
    dialog/BallardDlg.h \
    dialog/RotScaleDlg.h \
    dialog/AreaFillDlg.h \
    dialog/Remotelogin.h \
    dialog/ThresholdDlg.h \
    dialog/Charrecogdlg.h \
    dialog/WriteDataDlg.h \
    dialog/NetSpyderDlg.h \
    dialog/CalcuDistDlg.h \
    dialog/FixThresholdDlg.h \
    dialog/TemplateMatchDlg.h \
    dialog/StatisticPixelDlg.h \
    dialog/UpgradeTempMatchDlg.h \
    src/Tools.h \
    src/Color.h \
    src/Dialog.h \
    src/Global.h \
    src/Database.h \
    src/Screencut.h \
    src/Subpixels.h \
    src/Preprocess.h \
    src/Multimedia.h \
    src/ImgAlgorithm.h \
    src/Imgcalculate.h \
    src/Dynamicdetect.h \
    src/Fileoperation.h \
    src/Formattransfer.h \
    src/Networkcommunication.h \
    datastruct/Global.h \
    datastruct/LinkList.h \
    datastruct/BinaryTree.h \

SOURCES += \
    main.cpp \
    qvision.cpp \
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
    dialog/Charrecogdlg.cpp \
    dialog/FixThresholdDlg.cpp \
    dialog/TemplateMatchDlg.cpp \
    dialog/StatisticPixelDlg.cpp \
    dialog/UpgradeTempMatchDlg.cpp \
    src/Tools.cpp \
    src/Database.cpp \
    src/Subpixels.cpp \
    src/Screencut.cpp \
    src/Preprocess.cpp \
    src/Multimedia.cpp \
    src/Imgcalculate.cpp \
    src/ImgAlgorithm.cpp \
    src/Dynamicdetect.cpp \
    src/Fileoperation.cpp \
    src/Formattransfer.cpp \
    src/Networkcommunication.cpp \
    datastruct/LinkList.cpp \
    datastruct/BinaryTree.cpp \

DISTFILES += \
    icon/21.png \
    icon/sample1.jpg \
    icon/sample2.jpg \
    icon/sample3.jpg \
    icon/sample4.jpg \
    icon/sample5.jpg \
    icon/sample6.jpg \
    icon/sample7.jpg \
    icon/sample8.jpg \
    icon/sample9.jpg \
    icon/sample10.jpg \
    icon/sample11.jpg \
    icon/sample12.jpg \
    icon/sample13.jpg \
    icon/sample14.jpg \
    icon/sample15.jpg \
    icon/sample16.jpg \
    icon/sample17.jpg \
    icon/sample18.jpg \
    icon/sample19.jpg \
    icon/sample20.jpg \
