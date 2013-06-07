ModulePath = $${ModulesPath}/ProxyModule

INCLUDEPATH    += $${ProxyPath}/modules/interfaces \
    $${ModulePath}

SOURCES        += $${ModulePath}/refreshservice.cpp \
    $${ModulePath}/refreshsession.cpp \
    $${ModulePath}/appservice.cpp

HEADERS        += $${ModulePath}/refreshservice.h \
    $${ModulePath}/refreshsession.h \
    $${ModulePath}/appservice.h
