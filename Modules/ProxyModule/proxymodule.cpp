#include "proxymodule.h"

#include "iproxyconnection.h"
#include "refreshservice.h"
#include "appservice.h"

void ProxyModule::init(IProxyConnection *proxyConnection)
{
    m_proxyConnection = proxyConnection;

    m_proxyConnection->registerService(new RefreshService(m_proxyConnection, this));
    m_proxyConnection->registerService(new AppService(m_proxyConnection, this));
}
