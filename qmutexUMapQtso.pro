QT -= gui

TARGET = qmutexUMapQtso
TEMPLATE = lib

QMAKE_CXXFLAGS += -std=c++17
CONFIG += no_keywords plugin

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    qmutexUMap.cpp

HEADERS += \
    qmutexUMap.hpp

!win32:MYPATH = "/"
win32:MYPATH = "H:/veryuseddata/portable/msys64/"

#mine
INCLUDEPATH += $${MYPATH}home/jouven/mylibs/include

#don't new line the "{"
#release
CONFIG(release, debug|release){
    LIBS += -L$${MYPATH}home/jouven/mylibs/release/ 
    DEPENDPATH += $${MYPATH}home/jouven/mylibs/release
    QMAKE_RPATHDIR += $${MYPATH}home/jouven/mylibs/release
}
#debug
CONFIG(debug, debug|release){
    LIBS += -L$${MYPATH}home/jouven/mylibs/debug/ -lbackwardSTso -ltimeso -lboost_date_time
    DEPENDPATH += $${MYPATH}home/jouven/mylibs/debug
    QMAKE_RPATHDIR += $${MYPATH}home/jouven/mylibs/debug
    DEFINES += DEBUGJOUVEN
}

QMAKE_CXXFLAGS_DEBUG -= -g
QMAKE_CXXFLAGS_DEBUG += -pedantic -Wall -Wextra -g3
#mingw (on msys2) can't handle lto
!win32:QMAKE_CXXFLAGS_RELEASE += -flto
QMAKE_CXXFLAGS_RELEASE += -mtune=sandybridge

#for some reason QMAKE defaults add this to the linker, which is useless
QMAKE_LFLAGS -= -m64
#only for release...
QMAKE_LFLAGS_RELEASE -= -Wl,-O1

!win32:QMAKE_LFLAGS_RELEASE += -flto
QMAKE_LFLAGS_RELEASE += -fvisibility=hidden
