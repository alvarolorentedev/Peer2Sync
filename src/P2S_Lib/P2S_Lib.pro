TEMPLATE = lib
LANGUAGE  = C++
CONFIG += c++14 precompile_header
CONFIG -= qt

QMAKE_CXX="g++-5"
QMAKE_CC="gcc-5"
QMAKE_CXXFLAGS += -O3 -std=c++14

TARGET = P2S_Lib

DEFINES += P2S_LIB_LIBRARY

PRECOMPILED_HEADER = precompiled.h

SOURCES += \
    jsonrpcrequest.cpp \
    jsonrpcresponse.cpp \
    jsonrpcvalidator.cpp \
    redisdatastore.cpp \
    optionsresponse.cpp

HEADERS += precompiled.h \
    irequest.h \
    iresponse.h \
    jsonrpcrequest.h \
    jsonrpcresponse.h \
    jsonrpcvalidator.h \
    p2slib.h \
    idatastore.h \
    redisdatastore.h \
    optionsresponse.h

LIBS += -lcpp_redis \
