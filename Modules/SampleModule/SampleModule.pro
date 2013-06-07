QT             -= gui
QT             += sql

TARGET          = $$qtLibraryTarget(ownet_samplemodule)
TEMPLATE        = lib
CONFIG         += plugin

INCLUDEPATH    += ../../Proxy/modules/interfaces

SOURCES        += samplemodule.cpp \
    sampleservice.cpp

HEADERS        += samplemodule.h \
    sampleservice.h

TARGET          = $$qtLibraryTarget(ownet_samplemodule)
macx:DESTDIR    = ../../Proxy/MrFusionProxy.app/Contents/MacOS/modules
!macx:DESTDIR   = ../../Proxy/modules

macx:QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -std=c++0x
