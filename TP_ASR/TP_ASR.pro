#-------------------------------------------------
#
# Project created by QtCreator 2018-02-15T15:41:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TP_ASR
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        vues/mainwindow.cpp \
    vues/dialogconnexion.cpp \
    vues/dialogclient.cpp \
    vues/dialogpersonnel.cpp \
    vues/dialogapropos.cpp \
    vues/tabclient.cpp \
    vues/tabpersonnel.cpp \
    modeles/client.cpp \
    modeles/type.cpp \
    modeles/rdv.cpp \
    modeles/compte.cpp \
    modeles/personnel.cpp \
    bdmanager/c_init_bd.cpp \
    bdmanager/bdmanager.cpp \
    bdmanager/bdmanagerclient.cpp \
    bdmanager/bdmanagerpersonnel.cpp \
    bdmanager/bdmanagerplanification.cpp

HEADERS += \
        vues/mainwindow.h \
    vues/dialogconnexion.h \
    vues/dialogclient.h \
    vues/dialogpersonnel.h \
    vues/dialogapropos.h \
    vues/tabclient.h \
    vues/tabpersonnel.h \
    modeles/client.h \
    modeles/type.h \
    modeles/rdv.h \
    modeles/compte.h \
    modeles/personnel.h \
    bdmanager/c_init_bd.h \
    bdmanager/bdmanager.h \
    bdmanager/bdmanagerclient.h \
    bdmanager/bdmanagerpersonnel.h \
    bdmanager/bdmanagerplanification.h

FORMS += \
        mainwindow.ui \
    dialogconnexion.ui \
    dialogclient.ui \
    dialogpersonnel.ui \
    dialogapropos.ui \
    tabclient.ui \
    tabpersonnel.ui

RESOURCES += \
    logo.qrc
