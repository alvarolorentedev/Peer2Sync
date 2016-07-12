TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    CrowServer.cpp

LIBS += \
  -lboost_thread \
  -lboost_system \
  -pthread

HEADERS += \
    CrowServer.h \
    IServer.h


