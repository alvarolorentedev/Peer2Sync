TEMPLATE = app
LANGUAGE  = C++
TARGET = p2s_lib_test
CONFIG   += console c++14
CONFIG   -= app_bundle -qt

QMAKE_CXX="g++-5"
QMAKE_CC="gcc-5"
QMAKE_CXXFLAGS += -O3 -std=c++14

SOURCES += main.cpp \

LIBS += -lgtest \
    -pthread \
    -L$$OUT_PWD/../../src/P2S_Lib/ -lP2S_Lib

INCLUDEPATH += $$PWD/../../src/P2S_Lib
DEPENDPATH += $$PWD/../../src/P2S_Lib
