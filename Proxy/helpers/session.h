#ifndef SESSION_H
#define SESSION_H

#include <QVariantMap>

#include "isession.h"

class QMutex;

class Session : public QObject, public ISession
{
    Q_OBJECT

public:
    Session(QObject *parent = NULL);

    void setValue(const QString &key, const QVariant &value);
    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;
    bool contains(const QString &key) const;

    void clear();

    bool isRefreshSession() const;

private:
    static QVariantMap *m_sessionData;
    static QMutex *m_mutex;
};

#endif // SESSION_H
