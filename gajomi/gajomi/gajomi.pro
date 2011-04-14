#-------------------------------------------------
#
# Project created by QtCreator 2011-04-08T12:33:16
#
#-------------------------------------------------

QT       += core gui

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

INCLUDEPATH += ../gameengine
INCLUDEPATH += C:/development/SDL-1.2.14/include
INCLUDEPATH += C:\development\SDL_image-1.2.10\include

SOURCES += main.cpp \
    app.cpp \
    player.cpp \
    enemy.cpp \
    ufo.cpp \
    missil.cpp \
    cannon.cpp

HEADERS  += \
    app.h \
    player.h \
    enemy.h \
    ufo.h \
    missil.h \
    cannon.h

FORMS    +=

OTHER_FILES += \
    maps/2.map \
    maps/1.map \
    maps/1.area \
    images/1.png
