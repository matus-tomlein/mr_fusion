QT             += sql network

TARGET          = $$qtLibraryTarget(ownet_proxymodule)
TEMPLATE        = lib
CONFIG         += plugin

ProxyPath = ../../Proxy
ModulesPath = ..

SOURCES += proxymodule.cpp
HEADERS += proxymodule.h

include(ProxyModule.pri)

TARGET          = $$qtLibraryTarget(ownet_proxymodule)
macx:DESTDIR    = ../../Proxy/MrFusionProxy.app/Contents/MacOS/modules
!macx:DESTDIR   = ../../Proxy/modules

macx:QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -std=c++0x
