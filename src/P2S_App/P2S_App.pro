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
    CrowServer.cpp \
    rpcmethods.cpp \
    datastoreput.cpp

HEADERS += \
    precompiled.h \
    CrowServer.h \
    IServer.h \
    precompiled.h \
    rpcmethods.h \
    datastoreput.h \
    irpcmethod.h

LIBS += \
  -lboost_thread \
  -lboost_system \
  -pthread \
  -lcpp_redis \
  -L$$OUT_PWD/../P2S_Lib/ -lP2S_Lib \
  -Wl,-rpath=$$OUT_PWD/../P2S_Lib
  
INCLUDEPATH += $$PWD/../P2S_Lib
DEPENDPATH += $$PWD/../P2S_Lib
