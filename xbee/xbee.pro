#-------------------------------------------------
#
# Project created by QtCreator 2015-03-07T18:43:39
#
#-------------------------------------------------

QT       += core gui serialport
QMAKE_CXXFLAGS += -std=c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = xbee
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialthread.cpp

HEADERS  += mainwindow.h \
    serialthread.h

FORMS    += mainwindow.ui
