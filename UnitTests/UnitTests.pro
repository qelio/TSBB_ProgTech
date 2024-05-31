QT += testlib sql network
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../server/aes.cpp \
    ../server/database.cpp \
    ../server/dichotomymethod.cpp \
    ../server/dijkstra.cpp \
    ../server/functionserver.cpp \
    ../server/mytcpserver.cpp \
    ../server/sha512.cpp \
    tst_funcforserver_test.cpp

HEADERS += \
    ../server/aes.h \
    ../server/database.h \
    ../server/dichotomymethod.h \
    ../server/dijkstra.h \
    ../server/functionserver.h \
    ../server/mytcpserver.h \
    ../server/sha512.h
