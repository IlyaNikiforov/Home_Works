
CONFIG += c++11
QT += testlib

QT       += core

QT       -= gui

TARGET = 7_2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += \
    vector.h \
    testVector.h
