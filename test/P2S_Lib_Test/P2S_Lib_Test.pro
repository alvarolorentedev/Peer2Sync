#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T21:51:29
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = p2s_lib_test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \

LIBS += -lgtest \
  -pthread
