TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    bomb.cpp \
    bomberman.cpp \
    brick.cpp \
    enemy.cpp \
    hiddenstaff.cpp \
    item.cpp \
    animation.cpp \
    animationmanager.cpp \
    main.cpp
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    bomb.h \
    bomberman.h \
    brick.h \
    enemy.h \
    hiddenstaff.h \
    item.h \
    animation.h \
    animationmanager.h

