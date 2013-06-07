INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

SOURCES += $${ProxyPath}/proxy/proxyrequest.cpp \
    $${ProxyPath}/proxy/proxyhandler.cpp \
    $${ProxyPath}/proxy/proxyhandlersession.cpp \
    $${ProxyPath}/proxy/httpserver/httpserver.cpp \
    $${ProxyPath}/proxy/httpserver/sockethandler.cpp \
    $${ProxyPath}/proxy/httpserver/requestreader.cpp \
    $${ProxyPath}/proxy/staticreader.cpp \
    $${ProxyPath}/proxy/servicereader.cpp \
    $${ProxyPath}/proxy/websocket.cpp \
    $${ProxyPath}/proxy/webdownloadsmanager.cpp \
    $${ProxyPath}/proxy/webreader.cpp \
    $${ProxyPath}/proxy/webdownload.cpp \
    $${ProxyPath}/proxy/directwebreader.cpp \
    $${ProxyPath}/proxy/websocketoutput.cpp

HEADERS  += $${ProxyPath}/proxy/proxyrequest.h \
    $${ProxyPath}/proxy/proxyhandler.h \
    $${ProxyPath}/proxy/proxyhandlersession.h \
    $${ProxyPath}/proxy/httpserver/httpserver.h \
    $${ProxyPath}/proxy/httpserver/sockethandler.h \
    $${ProxyPath}/proxy/httpserver/requestreader.h \
    $${ProxyPath}/proxy/staticreader.h \
    $${ProxyPath}/proxy/servicereader.h \
    $${ProxyPath}/proxy/websocket.h \
    $${ProxyPath}/proxy/webdownloadsmanager.h \
    $${ProxyPath}/proxy/webreader.h \
    $${ProxyPath}/proxy/webdownload.h \
    $${ProxyPath}/proxy/directwebreader.h \
    $${ProxyPath}/proxy/iwebdownload.h \
    $${ProxyPath}/proxy/websocketoutput.h

INCLUDEPATH += $${ProxyPath}/proxy \
    $${ProxyPath}/proxy/httpserver
