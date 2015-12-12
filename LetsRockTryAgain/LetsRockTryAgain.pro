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
    service.cpp \
    database.cpp \
    addcs.cpp \
    addc.cpp

HEADERS  += mainmenu.h \
    service.h \
    database.h \
    addcs.h \
    addc.h

FORMS    += mainmenu.ui \
    addcs.ui \
    addc.ui
