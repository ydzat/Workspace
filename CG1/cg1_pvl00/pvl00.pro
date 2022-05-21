TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

OBJECTS_DIR = ./obj
SOURCES += main.cpp  

HEADERS += \
    CGVector.h \
    CGVector.h \
    CGMatrix.h

MAKEFILE = Makefile_qmake.$${TARGET}
