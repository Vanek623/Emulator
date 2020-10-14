QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Recognizer
TEMPLATE += app

INCLUDEPATH += \
    ./Widgets/ \
    ./Windows/ \
    ./System/

SOURCES += main.cpp \
    System/Neuro.cpp \
    System/Trainer.cpp \
    System/NeuroNet.cpp \
    Widgets/Controls.cpp \
    Widgets/NumInput.cpp \
    Windows/mainwindow.cpp

HEADERS += System/Neuro.h \
    System/Trainer.h \
    System/NeuroNet.h \
    Widgets/Controls.h \
    Widgets/NumInput.h \
    Windows/mainwindow.h \
    System/consts.h

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
