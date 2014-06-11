TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    mrowisko.cpp \
    world.cpp \
    resultsheet.cpp

HEADERS += \
    losowy.h \
    mrowisko.h \
    world.h \
    globalSettings.h \
    resultsheet.h

