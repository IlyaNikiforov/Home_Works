#-------------------------------------------------
#
# Project created by QtCreator 2014-05-08T22:03:15
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = 4_4
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    hash.cpp \
    list.cpp \
    strings.cpp

HEADERS += \
    hash.h \
    list.h \
    strings.h \
    stringtest.h \
    hashtest.h
