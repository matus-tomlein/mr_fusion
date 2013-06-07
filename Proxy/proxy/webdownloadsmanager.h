#ifndef WEBDOWNLOADSMANAGER_H
#define WEBDOWNLOADSMANAGER_H

#include <QMutex>
#include <QMap>
#include <QNetworkProxy>

class CacheExceptions;
class WebDownload;
class CacheLocations;
class ProxyRequest;
class WebReader;
class ProxyHandlerSession;

class WebDownloadsManager
{
public:
    static WebDownloadsManager *instance() {
        static QMutex mutex;
        if (!m_instance) {
            mutex.lock();
            if (!m_instance)
                m_instance = new WebDownloadsManager;
            mutex.unlock();
        }

        return m_instance;
    }

    QIODevice *getStream(ProxyRequest *request, WebReader *reader, ProxyHandlerSession *handlerSession, bool *finished);
    void deregisterDownloadReader(WebDownload *proxyDownload, int readerId);

    QNetworkProxy applicationProxy() const;
    bool isSetApplicationProxy() const;
    void setApplicationProxy(const QString &ip, int port);

    bool isCacheAvailable(uint cacheId) const;

    bool containsCacheExceptionFor(const QString &url);

private:
    WebDownloadsManager();
    bool shouldRefresh(ProxyRequest *request);

    QMutex m_openDownloadsMutex;
    QMap<uint, WebDownload*> m_downloads;

    CacheExceptions *m_cacheExceptions;

    int m_proxyPort;
    QString m_proxyIp;

    static WebDownloadsManager *m_instance;
};

#endif // WEBDOWNLOADSMANAGER_H
