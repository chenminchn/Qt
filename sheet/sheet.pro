######################################################################
# Automatically generated by qmake (3.0) Mon May 14 20:24:33 2018
######################################################################
QT += core
QT +=gui
QT += widgets

TEMPLATE = app
TARGET = sheet
INCLUDEPATH += .

# Input
HEADERS += aboutdialog.h finddialog.h mainwindow.h spreadsheet.h \
    gotocelldialog.h \
    ui_gotocelldialog.h \
    sortdialog.h \
    ui_sortdialog.h
SOURCES += aboutdialog.cpp \
           finddialog.cpp \
           main.cpp \
           mainwindow.cpp \
           spreadsheet.cpp \
    gotocelldialog.cpp \
    sortdialog.cpp

DISTFILES += \
    images/copy.png \
    images/cut.png \
    images/find.png \
    images/gotocell.png \
    images/new.png \
    images/open.png \
    images/paste.png \
    images/save.png

RESOURCES += \
    resource.qrc
