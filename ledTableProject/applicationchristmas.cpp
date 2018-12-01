#include "applicationchristmas.h"

applicationchristmas::applicationchristmas(QObject *parent, ws2811_led_t *ledMatrix) : applicationBase(parent,ledMatrix)
{
    fps = 1;
}

applicationchristmas::~applicationchristmas()
{

}

void applicationchristmas::inputReceived(QStringList input)
{

}

void applicationchristmas::initApp()
{
    addText(0,9,"Vrolijk Kerstmis",0xFF0000,LEFT,true);
    addText(0,0,"Joyeux Noël",0xFF00,LEFT,true);
}

void applicationchristmas::closeApp()
{

}

void applicationchristmas::tick()
{
    clear();
    move();
}
