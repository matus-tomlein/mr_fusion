#-------------------------------------------------
#
# Project created by QtCreator 2012-09-29T17:32:25
#
#-------------------------------------------------

QT       += core network sql testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MrFusionProxy
TEMPLATE = app

SOURCES += main.cpp \
    proxyapplication.cpp

INCLUDEPATH += $$_PRO_FILE_PWD_

ProxyPath = .
LibPath = ../lib

include(cache/cache.pri)
include(helpers/helpers.pri)
include(modules/modules.pri)
include(init/init.pri)
include(jobs/jobs.pri)
include(proxy/proxy.pri)

macx:QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7
macx:QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -std=c++0x

HEADERS += \
    proxyapplication.h
