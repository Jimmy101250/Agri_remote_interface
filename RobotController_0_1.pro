#-------------------------------------------------
#
# Project created by QtCreator 2019-10-22T21:27:09
#
#-------------------------------------------------

QT       += core gui webengine webenginewidgets gamepad

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RobotController_0_1
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        ros_lib/duration.cpp \
        ros_lib/time.cpp \
        ros_lib/WindowsSocket.cpp \
    stdafx.cpp \
    receivemessage.cpp \
    twistfortest.cpp \
    sendhandshankmessage.cpp \
    generatetracepoint.cpp

HEADERS += \
        mainwindow.h \
        ros_lib/ros.h \
        ros_lib/WindowsSocket.h \
    stdafx.h \
    targetver.h \
    receivemessage.h \
    twistfortest.h \
    sendhandshankmessage.h \
    generatetracepoint.h

INCLUDEPATH += C:\MyFiles\QtCodes\RobotController_0_1\ros_lib

LIBS += -lWs2_32

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
