QT += core network
QT -= gui

CONFIG += c++11

TARGET = ledTableProject
CONFIG += console
CONFIG -= app_bundle

LIBS += -L$$PWD/../lib -lws2811
INCLUDEPATH += $$PWD/../lib/include

TEMPLATE = app


SOURCES += main.cpp \
    controllerclass.cpp \
    applicationbase.cpp \
    applicationinput.cpp \
    ledmatrix.cpp \
    updatethread.cpp \
    fonts.cpp \
    applicationtest.cpp \
    applicationpong.cpp \
    applicationsnake.cpp \
    applicationstart.cpp \
    applicationchristmas.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    controllerclass.h \
    applicationbase.h \
    applicationinput.h \
    ledmatrix.h \
    updatethread.h \
    fonts.h \
    applicationtest.h \
    applicationpong.h \
    applicationsnake.h \
    applicationstart.h \
    applicationchristmas.h

DISTFILES += \
    settings


