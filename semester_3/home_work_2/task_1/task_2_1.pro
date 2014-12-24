#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T16:32:44
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = task_2_1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp \
    computer.cpp \
    localnetwork.cpp

HEADERS += \
    computer.h \
    localnetwork.h \
    localnetworktest.h \
    random.h
