QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH +=$$PWD/Source/opencv2

SOURCES += \
    main.cpp \
    src/qcapture.cpp

HEADERS += \
    src/global.h \
    src/qcapture.h

DESTDIR =$$PWD/Capture

win32: LIBS += -L$$PWD/Source/lib/ -lOpenCV

INCLUDEPATH += $$PWD/Source/opencv2
DEPENDPATH += $$PWD/Source/opencv2

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/Source/lib/OpenCV.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/Source/lib/libOpenCV.a

win32: LIBS += -L$$PWD/Source/lib/ -ldlib

INCLUDEPATH += $$PWD/''
DEPENDPATH += $$PWD/''

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/Source/lib/dlib.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/Source/lib/libdlib.a
