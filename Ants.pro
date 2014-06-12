TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    mrowisko.cpp \
    world.cpp \
    globaldata.cpp

HEADERS += \
    losowy.h \
    mrowisko.h \
    world.h \
    globalSettings.h \
    globaldata.h

