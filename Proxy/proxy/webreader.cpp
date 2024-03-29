#include "webreader.h"

#include "webdownload.h"
#include "sockethandler.h"
#include "proxyhandlersession.h"
#include "session.h"
#include "requestreader.h"
#include "webdownloadsmanager.h"
#include "cachefolder.h"
#include "proxyrequest.h"

#include <QUrl>

WebReader::WebReader(SocketHandler *socketHandler, ProxyRequest *request, ProxyHandlerSession *session, QObject *parent) :
    QObject(parent),
    m_socketHandler(socketHandler),
    m_request(request),
    m_stream(NULL),
    m_session(session),
    m_writtenToSocket(false)
{
    m_dependentObjectId = m_session->registerDependentObject();
}

void WebReader::read()
{
    bool done = false;

    m_readMutex.lock();
    m_stream = WebDownloadsManager::instance()->getStream(m_request, this, m_session, &done);
    m_readMutex.unlock();

    if (m_stream) {
        QByteArray firstLine = m_stream->readLine().trimmed();

        if (!firstLine.isEmpty()) {
            m_socketHandler->write(m_stream->readAll());
            m_stream->deleteLater();
            QFile *file = CacheFolder().fileByPath(firstLine);
            if (file->open(QFile::ReadOnly))
                m_stream = file;
            else
                m_stream = NULL;
        }
    }

    if (!m_stream)
        failed();
    else if (done)
        finished();
}

void WebReader::readyRead()
{
    m_readMutex.lock();
    if (m_stream) {
        QByteArray bytes = m_stream->readAll();
        if (!bytes.isEmpty())
            m_socketHandler->write(bytes);
    }
    m_readMutex.unlock();
    m_writtenToSocket = true;

    emit iAmActive();
}

void WebReader::finished()
{
    readyRead();
    if (m_dependentObjectId >= 0)
        m_session->deregisterDependentObject(m_dependentObjectId);
    m_dependentObjectId = -1;
}

void WebReader::failed()
{
    if (!m_writtenToSocket) {
        m_socketHandler->writeStatusCodeAndDescription(418, "I'm a teapot");
        QVariantMap responseHeaders;
        responseHeaders.insert("Content-Length", "0");
        m_socketHandler->writeHeaders(responseHeaders);
        m_socketHandler->write(QByteArray());
    }
    if (m_dependentObjectId >= 0)
        m_session->deregisterDependentObject(m_dependentObjectId);
    m_dependentObjectId = -1;
}
