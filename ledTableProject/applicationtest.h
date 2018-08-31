#ifndef APPLICATIONTEST_H
#define APPLICATIONTEST_H
#include "applicationbase.h"

class applicationTest : public applicationBase
{
public:
    applicationTest(QObject *parent,ws2811_led_t *ledMatrix);
    ~applicationTest();
    void inputReceived(QStringList input);

private:
    int state=0;
    int x,y;

private slots:
    void tick();



};

#endif // APPLICATIONTEST_H
