#-------------------------------------------------
#
# Project created by QtCreator 2019-04-11T17:43:59
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = ProjectFeelTheChunder
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

INCLUDEPATH += ./containers \
                ./database \


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        shape.cpp \
        RenderArea.cpp \
        ./database/dbconnection.cpp \
        create_user.cpp \

HEADERS += \
        mainwindow.h \
        shape.h \
        containers/AwesomeVector.h \
        RenderArea.h \
        shape.h \
        ./database/dbconnection.h \
        create_user.h \


FORMS += \
        mainwindow.ui \
    create_user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    siccpixandstuff.qrc

DISTFILES += \
    FileParser/shapes.txt
