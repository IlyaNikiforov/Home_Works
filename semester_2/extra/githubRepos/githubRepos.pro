QT       += core gui

QT       += core gui webkitwidgets xml

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = githubRepos
TEMPLATE = app
CONFIG   += c++11


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

