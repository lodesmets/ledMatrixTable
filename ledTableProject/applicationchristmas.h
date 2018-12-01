#ifndef APPLICATIONCHRISTMAS_H
#define APPLICATIONCHRISTMAS_H

#include "applicationbase.h"

class applicationchristmas : public applicationBase
{
public:
    applicationchristmas(QObject *parent,ws2811_led_t *ledMatrix);
    ~applicationchristmas();
    void inputReceived(QStringList input);


private slots:
    void tick();
};

#endif // APPLICATIONCHRISTMAS_H
