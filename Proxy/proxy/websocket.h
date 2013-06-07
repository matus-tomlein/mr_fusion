#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QStringList>

class ProxyRequest;
class QTimer;
class WebSocketOutput;
class IWebDownload;

class WebSocket : public QObject
{
    Q_OBJECT
public:
    enum {
        Timeout = 5000
    };
    enum ResponseLength {
        Chunked,
        Defined,
        Unknown
    };

    explicit WebSocket(ProxyRequest *request, IWebDownload *webDownload, WebSocketOutput *output, QObject *parent = 0);

    void readRequest();

    static void setCanDownloadFromWeb(bool can) { m_canDownloadFromWeb = can; }

signals:
    void readyRead();

private slots:
    void socketConnectedToServer();
    void socketReadyRead();
    void socketDisconnected();
    void socketError(QAbstractSocket::SocketError error);
    void responseTimeout();
    void finished();
    void failed();

private:
    QString extractServer(const QString &fullUrl) const;
    QString serverName(const QString &serverAndPort) const;
    int port(const QString &serverAndPort) const;

    static bool m_canDownloadFromWeb;
    bool m_readHeaders;
    QTcpSocket *m_socket;
    long m_contentLength;
    ResponseLength m_responseLength;
    QTimer *m_timeoutTimer;
    ProxyRequest *m_request;
    WebSocketOutput *m_outputFile;
    IWebDownload *m_webDownload;
};

#endif // WEBSOCKET_H
