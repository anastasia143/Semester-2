#-------------------------------------------------
#
# Project created by QtCreator 2013-02-27T20:59:32
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task2
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    fileOutputer.cpp \
    consoleOutputer.cpp

HEADERS += \
    fileOutputer.h \
    consoleOutputer.h \
    outputer.h

OTHER_FILES += \
    file.txt
