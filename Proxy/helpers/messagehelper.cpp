#include "messagehelper.h"

#include "applicationdatastorage.h"

#include <QDebug>
#include <QFile>
#include <QQueue>

MessageHelper::MessageHelper()
{
}

void MessageHelper::error(const QString &title, const QVariant &body)
{
    qDebug() << title << body;
}

void MessageHelper::information(const QString &title, const QVariant &body)
{
    qDebug() << title << body.toString();
}

void MessageHelper::warning(const QString &title, const QVariant &body)
{
    qDebug() << title << body.toString();
}

void MessageHelper::debug(const QVariant &message)
{
    qDebug() << message.toString();
}
