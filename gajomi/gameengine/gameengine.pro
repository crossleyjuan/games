#-------------------------------------------------
#
# Project created by QtCreator 2011-04-08T12:26:10
#
#-------------------------------------------------

QT       -= core gui

TARGET = gameengine
TEMPLATE = lib

DESTDIR = ../gajomi-bin

LIBS += -LC:/development/SDL-1.2.14/lib
LIBS += -lSDL
LIBS += -lSDLmain
LIBS += -LC:\development\SDL_image-1.2.10\lib
LIBS += -lSDL_image


INCLUDEPATH += C:/development/SDL-1.2.14/include
INCLUDEPATH += C:\development\SDL_image-1.2.10\include

DEFINES += GAMEENGINE_LIBRARY

SOURCES += \
    tile.cpp \
    surface.cpp \
    map.cpp \
    fps.cpp \
    Event.cpp \
    entitycol.cpp \
    entity.cpp \
    camera.cpp \
    area.cpp \
    animation.cpp \
    engine.cpp

HEADERS +=\
        gameengine_global.h \
    tile.h \
    surface.h \
    map.h \
    fps.h \
    Event.h \
    entity.h \
    define.h \
    camera.h \
    area.h \
    animation.h \
    engine.h

OTHER_FILES += \
    maps/2.map \
    maps/1.map \
    maps/1.area \
    images/yoshi2.png \
    images/yoshi.png \
    images/yoshi.bmp \
    images/yoshi - Copy.png \
    images/runmega.png \
    images/MegaManEXE-Z-stylesheet2.png \
    images/1.png \
    images/1 - Copy.png

system(copy-deps.bat)
