#-------------------------------------------------
#
# Project created by QtCreator 2013-07-01T10:52:32
#
#-------------------------------------------------

QT       += core gui
QT       += core gui opengl

TARGET = Firebird
TEMPLATE = app


SOURCES += main.cpp\
    shape.cpp \
    greenhouse.cpp \
    robot.cpp \
    createenvironmentopenglwindow.cpp \
    createenvironment.cpp \
    robotwindow.cpp \
    robotopenglwindow.cpp \
    texture.cpp \
    mainwindow2.cpp \
    mainopenglwindow2.cpp \
    image.cpp \
    loadpng.cpp \
    initialise.cpp \
    communicate.cpp

HEADERS  += \
    shape.h \
    greenhouse.h \
    robot.h \
    mydatatype.h \
    createenvironment.h \
    createenvironmentopenglwindow.h \
    createenvironmentopenglwindow.cpp.autosave \
    robotwindow.h \
    texture.h \
    robotopenglwindow.h \
    mainwindow2.h \
    mainopenglwindow2.h \
    image.h \
    loadpng.h \
    initialise.h \
    communicate.h

FORMS    += \
    createenvironment.ui \
    mainwindow2.ui \
    robotwindow.ui

#INCLUDEPATH += /home/atul/src/OpenCV-2.4.2/include/opencv/ #this is where the header files are on my machine
#LIBS += /usr/lib/libopencv_core.so.2.3.1
#LIBS += /usr/lib/libopencv_highgui.so.2.3.1

OTHER_FILES += \
    top.ppm \
    soil-t2.jpg \
    images (1).jpg \
    images.jpg \
    Firebird.pro.user.b848433 \
    Firebird.pro.user.2.5pre1 \
    Firebird.pro.user
