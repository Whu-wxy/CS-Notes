TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

QT += core
DEFINES += QT_DEPRECATED_WARNINGS
TARGET = stlTest


SOURCES += \
        main.cpp \
    threadinclass.cpp \
    singleton.cpp \
    threadpool.cpp

HEADERS += \
    algorithmmoban.h \
    binary_search.h \
    classtest.h \
    listtest.h \
    lru.h \
    sharedptr.h \
    sortalg.h \
    stlfstream.h \
    threadtest.h \
    threadinclass.h \
    singleton.h \
    threadpool.h \
    treetest.h \
    vectortest.h \
    xipai.h \
    stringtest.h
