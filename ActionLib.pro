#-------------------------------------------------
#
# Project created by QtCreator 2016-03-13T11:53:53
#
#-------------------------------------------------

QT       += sql core

QT       -= gui

TARGET = ActionLib
TEMPLATE = lib
CONFIG += shared
#CONFIG += staticlib
CONFIG += c++11

DEFINES += MYSHAREDLIB_LIBRARY

SOURCES += actionlib.cpp \
    actionlibprivate.cpp

HEADERS += actionlib.h \
    actionlibprivate.h

