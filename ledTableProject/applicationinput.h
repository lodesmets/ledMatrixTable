#ifndef APPLICATIONINPUT_H
#define APPLICATIONINPUT_H

#include "applicationbase.h"


class applicationInput : public applicationBase
{
    Q_OBJECT
public:
    applicationInput(QObject *parent,ws2811_led_t *ledMatrix);
    ~applicationInput();
    void inputReceived(QStringList input);

private:
    void initApp();

private slots:
    void tick();


};

#endif // APPLICATIONINPUT_H
