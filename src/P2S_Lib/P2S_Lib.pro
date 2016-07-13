#-------------------------------------------------
#
# Project created by QtCreator 2016-07-12T21:34:26
#
#-------------------------------------------------

QT       -= core gui

TARGET = P2S_Lib
TEMPLATE = lib

DEFINES += P2S_LIB_LIBRARY

PRECOMPILED_HEADER = precompiled.h

SOURCES += \
    request.cpp \
    response.cpp

HEADERS += precompiled.h \
        p2s_lib_global.h \
    request.h \
    response.h

#unix {
#    target.path = /usr/lib
#    INSTALLS += target
#}
