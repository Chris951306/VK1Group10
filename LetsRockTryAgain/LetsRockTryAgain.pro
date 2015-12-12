#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T16:20:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LetsRockTryAgain
TEMPLATE = app


SOURCES += main.cpp\
        mainmenu.cpp \
    add.cpp \
    service.cpp \
    database.cpp

HEADERS  += mainmenu.h \
    add.h \
    service.h \
    database.h

FORMS    += mainmenu.ui \
    add.ui
