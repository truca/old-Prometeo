#-------------------------------------------------
#
# Project created by QtCreator 2012-10-22T13:31:34
#
#-------------------------------------------------

QT       += core gui
QT       += webkit

TARGET = Prometeo
TEMPLATE = app

win32: include ( C:/Qwt-6.0.1/features/qwt.prf )
win32: CONFIG += qwt
macx: include ( /usr/local/Cellar/qwt/6.0.1/features/qwt.prf )
unix: !macx: include(/usr/share/qt4/mkspecs/features/qwt.prf)

include(bibliotecas/qextserialport-1.2beta2/src/qextserialport.pri)

INCLUDEPATH += bibliotecas/mavlink/include/mavlink/v1.0/common/

SOURCES += main.cpp\
        mainwindow.cpp \
    plot.cpp \
    PortListener.cpp \
    chromificador.cpp \
    comunicadorjs.cpp \
    mapa.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    plot.h \
    PortListener.h \
    comunicadorjs.h \
    chromificador.h \
    mapa.h \
    client.h

INCLUDEPATH +=.

FORMS    += mainwindow.ui

#Cambiando directorios
release: DESTDIR = build/release
debug:   DESTDIR = build/debug

OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR = $$DESTDIR/moc
RCC_DIR = $$DESTDIR/qrc
UI_DIR = $$DESTDIR/ui

OTHER_FILES += \
    Mapa.html
