#include "jobinitializer.h"

#include "job.h"

#include <QThread>

JobInitializer::JobInitializer(QObject *parent)
    : QObject(parent)
{
}

void JobInitializer::init()
{
}

QThread *JobInitializer::startJob(Job *job)
{
    if (job->createSeparateThread()) {
        QThread* thread = new QThread;
        job->moveToThread(thread);
        connect(thread, SIGNAL(started()), job, SLOT(start()));
        connect(job, SIGNAL(finish()), thread, SLOT(terminate()));
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        thread->start();
        return thread;
    }
    job->start();
    return NULL;
}
