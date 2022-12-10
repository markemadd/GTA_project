QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullets.cpp \
    door.cpp \
    enemy.cpp \
    franklin.cpp \
    game.cpp \
    gameover.cpp \
    graph.cpp \
    home.cpp \
    main.cpp \
    gta.cpp \
    power_pellets.cpp \
    widgets.cpp

HEADERS += \
    bullets.h \
    door.h \
    enemy.h \
    franklin.h \
    game.h \
    gameover.h \
    graph.h \
    gta.h \
    home.h \
    power_pellets.h \
    widgets.h

FORMS += \
    gta.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
