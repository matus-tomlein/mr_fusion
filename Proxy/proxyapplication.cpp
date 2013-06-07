#include "proxyapplication.h"

#include "messagehelper.h"

ProxyApplication::ProxyApplication(int &argc, char **argv) :
    QCoreApplication(argc, argv)
{}

bool ProxyApplication::notify(QObject *receiver, QEvent *event)
{
    bool done = true;
    try {
        done = QCoreApplication::notify(receiver, event);
    } catch (const std::exception &ex) {
        MessageHelper::debug(QString("Caught exception in QApplication: %1").arg(ex.what()));
    }
    return done;
}
