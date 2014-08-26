QMAKE_MAC_SDK = macosx10.7
TARGET = DataStructures
TEMPLATE = app
CONFIG += c++11

macx {
    LIBS += -stdlib=libc++
    QMAKE_CXXFLAGS += -stdlib=libc++
    QMAKE_CXXFLAGS += -mmacosx-version-min=10.7
    QMAKE_LFLAGS += -mmacosx-version-min=10.7
}

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -Wall
QMAKE_CXXFLAGS += -pedantic
INCLUDEPATH += ..

SOURCES += ScoreTile.cpp \
    Match.cpp \
    Project1Main.cpp \
    Team.cpp \
    Player.cpp

HEADERS += ScoreTile.h \
    Match.h \
    Player.h \
    Team.h

