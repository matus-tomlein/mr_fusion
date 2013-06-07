#include "cacheexceptions.h"

#include <QUrl>
#include <QStringList>

CacheExceptions::CacheExceptions(QObject *parent) :
    QObject(parent)
{
    init();
}

/**
 * @brief Returns true if the url should not be cached
 * @param url Full url of the object
 * @return True is there is an exception
 */
bool CacheExceptions::containsExceptionFor(const QString &url) const
{
    return m_cacheExceptions.contains(getHostName(url));
}

void CacheExceptions::init()
{
}

QString CacheExceptions::getHostName(const QString &url)
{
    QUrl qurl(url);
    QStringList split = qurl.host().split(".");

    while (split.count() > 2)
        split.removeFirst();

    return split.join(".");
}
