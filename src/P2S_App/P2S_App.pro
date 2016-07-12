TEMPLATE = app
LANGUAGE  = C++
CONFIG += console c++14 precompile_header
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXX="g++-5"
QMAKE_CC="gcc-5"
QMAKE_CXXFLAGS += -O3 -std=c++14

PRECOMPILED_HEADER = precompiled.h

SOURCES += main.cpp \
    CrowServer.cpp

HEADERS += \
    precompiled.h \
    CrowServer.h \
    IServer.h \
    precompiled.h

LIBS += \
  -lboost_thread \
  -lboost_system \
  -pthread
