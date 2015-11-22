#-------------------------------------------------
#
# Project created by QtCreator 2015-11-21T13:40:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseDeDatos
TEMPLATE = app


SOURCES += main.cpp\
        interface.cpp \
    manejador_mensajes.cpp \
    pugixml.cpp \
    button.cpp \
    socketcliente.cpp

    socketcliente.cpp

HEADERS  += interface.h \
    Constants.h \
    manejador_mensajes.h \
    Node.h \
    pugiconfig.hpp \
    pugixml.hpp \
    button.h \
    linked_list1.h \
    linked_list.h \
    socketcliente.h

FORMS    += interface.ui
