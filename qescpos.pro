QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = drive_tester
TEMPLATE = app

OBJECTS_DIR = build
MOC_DIR = build
RCC_DIR = build
UI_DIR = build
DESTDIR = bin

include(qescpos.pri)

FORMS += \
    example/dialogprinttemplate.ui

HEADERS += \
    example/dialogprinttemplate.h

SOURCES += \
    example/main.cpp \
    example/dialogprinttemplate.cpp


greaterThan(QT_MAJOR_VERSION, 4) {
    LIBS += -lQt5SerialPort
} else {
    LIBS += -lqtserialport
}
