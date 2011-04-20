#-------------------------------------------------
#
# Project created by QtCreator 2011-04-08T12:33:16
#
#-------------------------------------------------

QT       += core

QT       -= gui

CONFIG   += console
CONFIG   -= app_bundle

TARGET = gajomi
TEMPLATE = app

DESTDIR = ../gajomi-bin

LIBS += -L../gajomi-bin
LIBS += -lgameengine
LIBS += -LC:/development/SDL-1.2.14/lib
LIBS += -lSDL
LIBS += -lSDLmain
LIBS += -LC:\development\SDL_image-1.2.10\lib
LIBS += -lSDL_image
LIBS += -LC:\development\SDL_ttf-2.0.10\lib
LIBS += -lSDL_ttf

INCLUDEPATH += ../gameengine
INCLUDEPATH += C:/development/SDL-1.2.14/include/SDL
INCLUDEPATH += C:/development\SDL_image-1.2.10\include
INCLUDEPATH += C:\development\SDL_ttf-2.0.10\include

SOURCES += main.cpp \
    app.cpp \
    player.cpp \
    enemy.cpp \
    ufo.cpp \
    missil.cpp \
    cannon.cpp \
    level.cpp

HEADERS  += \
    app.h \
    player.h \
    enemy.h \
    ufo.h \
    missil.h \
    cannon.h \
    level.h

FORMS    +=

OTHER_FILES += \
    maps/2.map \
    maps/1.map \
    maps/1.area \
    images/1.png \
    Levels.txt
