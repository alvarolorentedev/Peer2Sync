TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += warn_off

SOURCES += main.cpp \
    CrowServer.cpp

LIBS += \
  -lboost_thread \
  -lboost_system \
  -pthread

HEADERS += \
    CrowServer.h \
    IServer.h


