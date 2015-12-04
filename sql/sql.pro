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
    display.cpp

HEADERS += \
    database.h \
    control.h \
    service.h \
    display.h

