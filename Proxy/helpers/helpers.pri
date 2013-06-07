SOURCES += $${ProxyPath}/helpers/messagehelper.cpp \
    $${ProxyPath}/helpers/applicationdatastorage.cpp \
    $${ProxyPath}/helpers/applicationenvironment.cpp \
    $${ProxyPath}/helpers/applicationproxyfactory.cpp \
    $${ProxyPath}/helpers/settings.cpp \
    $${ProxyPath}/helpers/variantmap.cpp \
    $${ProxyPath}/helpers/session.cpp \
    $${ProxyPath}/helpers/proxyconnection.cpp \
    $${ProxyPath}/helpers/artificialrequest.cpp \
    $${ProxyPath}/helpers/jsondocument/jsondocument.cpp \
    $${ProxyPath}/helpers/jsondocument/qjsonwriter.cpp \
    $${ProxyPath}/helpers/jsondocument/qjson.cpp \
    $${ProxyPath}/helpers/uniqueidhelper.cpp \
    $${ProxyPath}/helpers/cachehelper.cpp


HEADERS  += $${ProxyPath}/helpers/messagehelper.h \
    $${ProxyPath}/helpers/applicationdatastorage.h \
    $${ProxyPath}/helpers/applicationenvironment.h \
    $${ProxyPath}/helpers/applicationproxyfactory.h \
    $${ProxyPath}/helpers/settings.h \
    $${ProxyPath}/helpers/variantmap.h \
    $${ProxyPath}/helpers/session.h \
    $${ProxyPath}/helpers/proxyconnection.h \
    $${ProxyPath}/helpers/artificialrequest.h \
    $${ProxyPath}/helpers/jsondocument/jsondocument.h \
    $${ProxyPath}/helpers/jsondocument/qjson_p.h \
    $${ProxyPath}/helpers/uniqueidhelper.h \
    $${ProxyPath}/helpers/cachehelper.h

INCLUDEPATH += $${ProxyPath}/helpers \
    $${ProxyPath}/helpers/jsondocument
