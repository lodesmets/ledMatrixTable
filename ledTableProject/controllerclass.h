#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QThread>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <QTextStream>
#include <iostream>

class controllerClass : public QObject
{
    Q_OBJECT
public:
    explicit controllerClass(QObject *parent = 0);
    void start();

private slots:
    void newConnection();

private:
    QTcpServer *tcpServer;
    QString users[4];

signals:

public slots:
};

#endif // CONTROLLER_H
