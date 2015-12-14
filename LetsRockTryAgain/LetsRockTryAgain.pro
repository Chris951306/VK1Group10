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
    addc.cpp \
    scientist.cpp \
    computer.cpp \
    link.cpp \
    addl.cpp \
    deletecs.cpp \
    deletec.cpp \
    deletel.cpp

HEADERS  += mainmenu.h \
    service.h \
    database.h \
    addcs.h \
    addc.h \
    scientist.h \
    computer.h \
    link.h \
    addl.h \
    deletecs.h \
    deletec.h \
    deletel.h

FORMS    += mainmenu.ui \
    addcs.ui \
    addc.ui \
    addl.ui \
    deletecs.ui \
    deletec.ui \
    deletel.ui
