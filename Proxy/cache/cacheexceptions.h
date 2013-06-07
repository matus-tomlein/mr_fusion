#ifndef CACHEEXCEPTIONS_H
#define CACHEEXCEPTIONS_H

#include <QObject>
#include <QMap>
#include <QMutex>

/**
 * @brief Singleton, contains updated list of all cache exceptions
 */
class CacheExceptions : public QObject
{
    Q_OBJECT
public:
    CacheExceptions(QObject *parent = 0);

    bool containsExceptionFor(const QString &url) const;

private:
    void init();
    static QString getHostName(const QString &url);

    QMap<QString, bool> m_cacheExceptions;
};

#endif // CACHEEXCEPTIONS_H
