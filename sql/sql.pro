QT += core sql
QT -= gui

TARGET = sql
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    database.cpp \
    control.cpp \
    service.cpp \
    display.cpp \
    scientist.cpp \
    computer.cpp \
    link.cpp

HEADERS += \
    database.h \
    control.h \
    service.h \
    display.h \
    scientist.h \
    computer.h \
    link.h

