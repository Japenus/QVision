QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


SOURCES += \
    main.cpp \
    src/qhs.cpp

HEADERS += \
    src/qhs.h

DESTDIR = $$PWD/Qhs
