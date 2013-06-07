#include "proxyapplication.h"

#include "initializer.h"
#ifndef Q_OS_WIN
#include <sys/signal.h>
#endif

int main(int argc, char *argv[])
{
    ProxyApplication a(argc, argv);
#ifndef Q_OS_WIN
    signal(SIGPIPE, SIG_IGN);
#endif

    Initializer initializer;
    initializer.init();

    return a.exec();
}
