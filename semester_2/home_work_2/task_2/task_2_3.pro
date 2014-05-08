#-------------------------------------------------
#
# Project created by QtCreator 2014-03-26T13:48:47
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT       += testlib

TARGET = task_2_3
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += C++11

TEMPLATE = app


SOURCES += main.cpp \
    printer.cpp \
    consoleprinter.cpp \
    fileprinter.cpp

HEADERS += \
    printer.h \
    consoleprinter.h \
    fileprinter.h \
    matrixtest.h
