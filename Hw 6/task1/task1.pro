#-------------------------------------------------
#
# Project created by QtCreator 2013-03-19T20:06:35
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console qtestlib
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tree.cpp \
    digitNode.cpp \
    signNode.cpp

HEADERS += \
    tree.h \
    test.h \
    treeNode.h \
    digitNode.h \
    signNode.h

OTHER_FILES += \
    file.txt \
    file2.txt
