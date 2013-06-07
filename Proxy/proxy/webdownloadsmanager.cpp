#include "webdownloadsmanager.h"

#include "webdownload.h"
#include "proxyrequest.h"
#include "proxyhandlersession.h"
#include "session.h"
#include "cacheexceptions.h"
#include "cachehelper.h"
#include "cachefolder.h"

#include <QDateTime>

WebDownloadsManager *WebDownloadsManager::m_instance = 0;

/**
 * @brief Creates a new ProxyWebDownload, or returns an active one if available.
 * @param request Request to retrieve a download by
 * @param handler ProxyHandler parent class
 * @param downloadReaderId Reference to reader ID varibale to set
 * @return ProxyWebDownload object
 */
QIODevice *WebDownloadsManager::getStream(ProxyRequest *request, WebReader *reader, ProxyHandlerSession *handlerSession, bool *finished)
{
    m_openDownloadsMutex.lock();
    uint cacheId = request->hashCode();

    WebDownload *download = NULL;
    if (m_downloads.contains(cacheId)) {
        download = m_downloads.value(cacheId);
    } else {
        download = new WebDownload(cacheId);
        m_downloads.insert(cacheId, download);
    }
    m_openDownloadsMutex.unlock();
    return download->getStream(request, reader, handlerSession, shouldRefresh(request), finished);
}

QNetworkProxy WebDownloadsManager::applicationProxy() const
{
    if (isSetApplicationProxy())
        return QNetworkProxy(QNetworkProxy::HttpProxy, m_proxyIp, m_proxyPort);
    return QNetworkProxy();
}

bool WebDownloadsManager::isSetApplicationProxy() const
{
    return m_proxyPort != -1;
}

void WebDownloadsManager::setApplicationProxy(const QString &ip, int port)
{
    m_proxyIp = ip;
    m_proxyPort = port;
}

bool WebDownloadsManager::isCacheAvailable(uint cacheId) const
{
    if (m_downloads.contains(cacheId))
        return m_downloads.value(cacheId)->exists();

    return false;
}

bool WebDownloadsManager::containsCacheExceptionFor(const QString &url)
{
    return m_cacheExceptions->containsExceptionFor(url);
}

WebDownloadsManager::WebDownloadsManager()
    : m_proxyPort(-1)
{
    m_cacheExceptions = new CacheExceptions;
}

bool WebDownloadsManager::shouldRefresh(ProxyRequest *request)
{
    if (request->domain() == "local")
        return false;

    return Session().isRefreshSession() || request->isRefreshRequest();
}

