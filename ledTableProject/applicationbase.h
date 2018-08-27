#ifndef APPLICATIONBASE_H
#define APPLICATIONBASE_H

#include <QObject>

class applicationBase : public QObject
{
    Q_OBJECT
public:
    explicit applicationBase(QObject *parent = 0);

signals:

public slots:
};

#endif // APPLICATIONBASE_H