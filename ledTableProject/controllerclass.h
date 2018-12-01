#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <iostream>
#include <QTimer>

#include "updatethread.h"

#include "applicationbase.h"

#include "settings"



class controllerClass : public QObject
{
    Q_OBJECT
public:
    explicit controllerClass(QObject *parent = 0);
    ~controllerClass();
    void start();

private slots:
    void newConnection();
    void matrix_render();

private:
    QTcpServer *tcpServer;
    QString users[4];
    applicationBase * activeApplication;
    QHash<QString,applicationBase*> apps;
    ledMatrix *ledMatrixController;
    updateThread * t;
    ws2811_t ledstring;
    ws2811_led_t *matrix;
    ws2811_return_t ret;
    QTimer *timer;
    applicationBase * activeApp;

signals:


};

#endif // CONTROLLER_H
