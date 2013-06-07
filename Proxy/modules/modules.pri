SOURCES += $${ProxyPath}/modules/requestrouter.cpp \
    $${ProxyPath}/modules/route.cpp \
    $${ProxyPath}/modules/response.cpp


HEADERS  += $${ProxyPath}/modules/interfaces/imodule.h \
    $${ProxyPath}/modules/interfaces/irequest.h \
    $${ProxyPath}/modules/requestrouter.h \
    $${ProxyPath}/modules/interfaces/isession.h \
    $${ProxyPath}/modules/interfaces/ijobaction.h \
    $${ProxyPath}/modules/interfaces/iproxyconnection.h \
    $${ProxyPath}/modules/interfaces/iservice.h \
    $${ProxyPath}/modules/interfaces/irestservice.h \
    $${ProxyPath}/modules/interfaces/irouter.h \
    $${ProxyPath}/modules/route.h \
    $${ProxyPath}/modules/interfaces/iroute.h \
    $${ProxyPath}/modules/interfaces/iresponse.h \
    $${ProxyPath}/modules/response.h \
    $${ProxyPath}/modules/interfaces/iuidrestservice.h \
    $${ProxyPath}/modules/interfaces/isettings.h \
    $${ProxyPath}/modules/interfaces/icachefolder.h

INCLUDEPATH += $${ProxyPath}/modules \
    $${ProxyPath}/modules/interfaces
