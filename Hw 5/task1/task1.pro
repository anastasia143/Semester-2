#-------------------------------------------------
#
# Project created by QtCreator 2013-03-12T19:30:12
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console qtestlib
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    hashTable.cpp \
    pointerList.cpp \
    hashKeyWithStrlen.cpp \
    hashKeyWithDegrees.cpp \
    hashKeyFunctions.cpp \
    commands.cpp

HEADERS += \
    hashTable.h \
    pointerList.h \
    hashKeyFunctions.h \
    hashKeyWithStrlen.h \
    hashKeyWithDegrees.h \
    commands.h \
    tests.h
