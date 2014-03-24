#-------------------------------------------------
#
# Project created by QtCreator 2014-03-22T13:11:37
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task1_1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    list.cpp \
    linkedlist.cpp \
    arraylist.cpp

HEADERS += \
    list.h \
    linkedlist.h \
    arraylist.h


QMAKE_CXXFLAGS += -std=c++0x
