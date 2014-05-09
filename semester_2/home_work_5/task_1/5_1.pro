#-------------------------------------------------
#
# Project created by QtCreator 2014-05-09T13:30:45
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = 5_1
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += main.cpp \
    tree.cpp

HEADERS += \
    tree.h \
    node.h \
    operation.h \
    number.h \
    summ.h \
    subtraction.h \
    multiplication.h \
    division.h \
    treetest.h
