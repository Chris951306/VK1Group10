QT += core
QT -= gui

TARGET = cs
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data.cpp \
    service.cpp \
    display.cpp \
    core.cpp

HEADERS += \
    data.h \
    service.h \
    display.h \
    core.h

