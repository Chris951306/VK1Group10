QT += core
QT += sql
QT -= gui

TARGET = cs
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    service.cpp \
    display.cpp \
    core.cpp \
    scientists.cpp \
    computers.cpp

HEADERS += \
    service.h \
    display.h \
    core.h \
    scientists.h \
    computers.h

