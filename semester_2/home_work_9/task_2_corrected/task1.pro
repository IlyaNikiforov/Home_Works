TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

QT += testlib

SOURCES += main.cpp \
    hashTable.cpp \
    wordList.cpp \
    hashFunctions.cpp

HEADERS += \
    hashTable.h \
    wordList.h \
    hashFunctions.h \
    hashTableTest.h

QMAKE_CXXFLAGS += -std=c++11
