QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    main.cpp \
    src/qhs.cpp

HEADERS += \
    src/qhs.h \
    src/global.h \

DESTDIR = $$PWD/Qhs

INCLUDEPATH += $$PWD/source/inc
DEPENDPATH += $$PWD/source/inc

win32: LIBS += -L$$PWD/source/lib/ -lHSLocator

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/source/lib/HSLocator.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/source/lib/libHSLocator.a

win32: LIBS += -L$$PWD/source/lib/ -lHSClassLibrary



win32:!win32-g++: PRE_TARGETDEPS += $$PWD/source/lib/HSClassLibrary.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/source/lib/libHSClassLibrary.a
