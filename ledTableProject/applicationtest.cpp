#include "applicationtest.h"


applicationTest::applicationTest(QObject *parent, ws2811_led_t *ledMatrix) : applicationBase(parent,ledMatrix)
{
    fps=6;

    addText(0,0,QString(8730),0xFFFF00,NONE);
    addText(10,10,"Test2",0xCC0066,LEFT);

}

applicationTest::~applicationTest()
{

}

void applicationTest::inputReceived(QStringList input)
{

}

void applicationTest::tick()
{
    clear();
    move();


}
