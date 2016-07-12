TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += warn_off
QMAKE_CXX="g++-5"
QMAKE_CC="gcc-5"

SOURCES += main.cpp \
    CrowServer.cpp

LIBS += \
  -lboost_thread \
  -lboost_system \
  -pthread

HEADERS += \
    CrowServer.h \
    IServer.h


