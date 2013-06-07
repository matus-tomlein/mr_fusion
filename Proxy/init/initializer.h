#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <QObject>

class Initializer : public QObject
{
    Q_OBJECT

public:
    Initializer(QObject *parent = NULL);

    void init();
};

#endif // INITIALIZER_H
