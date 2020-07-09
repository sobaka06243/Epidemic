#-------------------------------------------------
#
# Project created by QtCreator 2015-03-24T12:09:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ball
TEMPLATE = app


SOURCES += main.cpp\
    deadball.cpp \
    healthyball.cpp \
    infectedball.cpp \
        mainwindow.cpp \
    ballitem.cpp \
    recoveredball.cpp

HEADERS  += mainwindow.h \
    ballitem.h \
    deadball.h \
    healthyball.h \
    infectedball.h \
    recoveredball.h

FORMS    += mainwindow.ui
