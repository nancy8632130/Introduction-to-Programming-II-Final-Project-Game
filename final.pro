#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T20:43:02
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
DESTDIR  =$$PWD
CONFIG += mobility
MOBILITY += multimedia
QT += multimedia
QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    level1.cpp \
    level2.cpp \
    level3.cpp \
    info.cpp \
    level4.cpp \
    role.cpp \
    prize.cpp \
    level5.cpp \
    music.cpp \
    movie.cpp

HEADERS  += mainwindow.h \
    level1.h \
    level2.h \
    level3.h \
    info.h \
    level4.h \
    role.h \
    prize.h \
    level5.h \
    music.h \
    movie.h

FORMS    += mainwindow.ui \
    level1.ui \
    level2.ui \
    info.ui \
    level4.ui \
    level3.ui \
    level5.ui \
    movie.ui

DISTFILES +=

RESOURCES += \
    resorce.qrc
