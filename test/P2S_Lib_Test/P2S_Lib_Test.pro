TEMPLATE = app
LANGUAGE  = C++
TARGET = p2s_lib_test
CONFIG   += console c++14 precompile_header
CONFIG   -= app_bundle
CONFIG -= qt
QMAKE_CXX="g++-5"
QMAKE_CC="gcc-5"
QMAKE_CXXFLAGS += -O3 -std=c++14

PRECOMPILED_HEADER = precompiled.h

HEADERS += \
    precompiled.h \
    precompiled.h

SOURCES += main.cpp \
    rpcRequestTest.cpp

LIBS += -lgtest \
    -pthread \
    -L$$OUT_PWD/../../src/P2S_Lib/ -lP2S_Lib

INCLUDEPATH += $$PWD/../../src/P2S_Lib
DEPENDPATH += $$PWD/../../src/P2S_Lib
