# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = IphoneLikeCalculator
DESTDIR = ../Win32/Debug
QT += core gui widgets
CONFIG += debug
DEFINES += WIN64 QT_DLL QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
HEADERS += ./iphonelikecalculator.h \
    ./topwidget.h \
    ./bottomwidget.h \
    ./middlewidget.h \
    ./basewidget.h \
    ./basewindow.h
SOURCES += ./basewidget.cpp \
    ./basewindow.cpp \
    ./bottomwidget.cpp \
    ./iphonelikecalculator.cpp \
    ./main.cpp \
    ./middlewidget.cpp \
    ./topwidget.cpp
RESOURCES += iphonelikecalculator.qrc
RC_FILE += calculator.rc