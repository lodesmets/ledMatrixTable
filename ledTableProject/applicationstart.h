#ifndef APPLICATIONSTART_H
#define APPLICATIONSTART_H

#include "applicationbase.h"

class applicationStart : public applicationBase
{
public:
    applicationStart(QObject *parent,ws2811_led_t *ledMatrix, QString ipAddress, int port);
    ~applicationStart();
    void inputReceived(QStringList input);

private:
    QString ip;
    int port;

private slots:
    void tick();
};

#endif // APPLICATIONSTART_H
