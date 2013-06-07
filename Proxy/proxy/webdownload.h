#ifndef PROXYWEBDOWNLOAD_H
#define PROXYWEBDOWNLOAD_H

#include "iwebdownload.h"

#include <QMutex>
#include <QAbstractSocket>
#include <QMap>

class QIODevice;
class ProxyRequest;
class ProxyHandlerSession;
class WebReader;
class QFile;
class WebSocket;

class WebDownload : public QObject, public IWebDownload
{
    Q_OBJECT
public:
    enum Type {
        CacheFile,
        WebStream,
        NetworkStream,
        Unknown
    };

    WebDownload(uint cacheId, QObject *parent = 0);
    
    QIODevice *getStream(ProxyRequest *request, WebReader *reader, ProxyHandlerSession *session, bool refresh, bool *finished);

    bool exists();

    void downloadFailed();
    void downloadFinished();

signals:
    void readyRead();
    void finished();
    void failed();

private:
    WebSocket *createWebSocket();
    void deregisterDependentObject();

    ProxyRequest *m_request;
    ProxyHandlerSession *m_session;

    int m_sessionDependentObjectId;
    uint m_cacheId;

    QMutex m_startedMutex;
    bool m_inProgress;
};

#endif // PROXYWEBDOWNLOAD_H
