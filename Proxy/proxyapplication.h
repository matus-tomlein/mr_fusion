#ifndef PROXYAPPLICATION_H
#define PROXYAPPLICATION_H

#include <QCoreApplication>

class ProxyApplication : public QCoreApplication
{
public:
    ProxyApplication(int &argc, char **argv);

    bool notify(QObject *receiver, QEvent *event);
};

#endif // PROXYAPPLICATION_H
