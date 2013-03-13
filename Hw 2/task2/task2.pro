#-------------------------------------------------
#
# Project created by QtCreator 2013-02-20T19:43:26
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task2
CONFIG   += console qtestlib
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    arrayStack.cpp \
    listStack.cpp \
    commands.cpp \
    calculator.cpp \
    stack.cpp

HEADERS += \
    stack.h \
    arrayStack.h \
    listStack.h \
    commands.h \
    calculator.h \
    stackTests.h
