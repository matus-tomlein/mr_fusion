#include "webdownload.h"

#include "proxyhandlersession.h"
#include "websocket.h"
#include "cachefolder.h"
#include "proxyrequest.h"
#include "webreader.h"
#include "session.h"
#include "cachehelper.h"
#include "webdownloadsmanager.h"
#include "websocketoutput.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QBuffer>

WebDownload::WebDownload(uint cacheId, QObject *parent) :
    QObject(parent),
    m_request(NULL),
    m_inProgress(false),
    m_sessionDependentObjectId(-1),
    m_session(NULL),
    m_cacheId(cacheId)
{
}

QIODevice *WebDownload::getStream(ProxyRequest *request, WebReader *reader, ProxyHandlerSession *session, bool refresh, bool *finished)
{
    m_request = request;
    *finished = false;
    WebSocket *webSocketToStart = NULL;

    m_startedMutex.lock();
    bool downloadFromWeb = true;

    QFile *file = CacheFolder().cacheFile(m_cacheId, 0);
    if (file->exists()) {
        if (m_inProgress) {
            connect(this, SIGNAL(readyRead()), reader, SLOT(readyRead()), Qt::QueuedConnection);
            connect(this, SIGNAL(finished()), reader, SLOT(finished()), Qt::QueuedConnection);
            connect(this, SIGNAL(failed()), reader, SLOT(failed()), Qt::QueuedConnection);
            downloadFromWeb = false;
        } else if (!refresh) {
            *finished = true;
            downloadFromWeb = false;
        }
    }

    if (downloadFromWeb) {
        connect(this, SIGNAL(readyRead()), reader, SLOT(readyRead()), Qt::QueuedConnection);
        connect(this, SIGNAL(finished()), reader, SLOT(finished()), Qt::QueuedConnection);
        connect(this, SIGNAL(failed()), reader, SLOT(failed()), Qt::QueuedConnection);

        m_session = session;
        m_sessionDependentObjectId = m_session->registerDependentObject();
        webSocketToStart = createWebSocket();
        m_inProgress = true;
    }

    m_startedMutex.unlock();

    if (webSocketToStart)
        webSocketToStart->readRequest();

    file->open(QIODevice::ReadOnly);

    return file;
}

bool WebDownload::exists()
{
    QFile *file = CacheFolder().cacheFile(m_cacheId, 0);
    bool exists = file->exists();
    file->deleteLater();
    return exists;
}

WebSocket *WebDownload::createWebSocket()
{
    CacheFolder cacheFolder;
    QFile *writeFile = cacheFolder.cacheFile(m_cacheId, 0);
    if (writeFile->exists())
        writeFile->remove();
    writeFile->open(QIODevice::WriteOnly);

    WebSocket *socket = new WebSocket(m_request, this, new WebSocketOutput(writeFile));

    connect(socket, SIGNAL(readyRead()), this, SIGNAL(readyRead()));
    return socket;
}

void WebDownload::downloadFailed()
{
    m_startedMutex.lock();
    m_inProgress = false;
    emit failed();
    m_startedMutex.unlock();

    deregisterDependentObject();
}

void WebDownload::downloadFinished()
{
    m_startedMutex.lock();
    m_inProgress = false;
    emit finished();
    m_startedMutex.unlock();

    deregisterDependentObject();
}

void WebDownload::deregisterDependentObject()
{
    if (m_sessionDependentObjectId >= 0 && m_session) {
        m_session->deregisterDependentObject(m_sessionDependentObjectId);
        m_session = NULL;
        m_sessionDependentObjectId = -1;
    }
}
