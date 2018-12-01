#include "applicationchristmas.h"

applicationchristmas::applicationchristmas(QObject *parent, ws2811_led_t *ledMatrix) : applicationBase(parent,ledMatrix)
{
    fps = 3;
    //QString vlaams = "Vrolijk Kerstmis";
    addText(26,10,"VROLIJK KERSTMIS",0xFF0000,LEFT,true);
    addText(26,1,"JOYEUX NOEL",0xFF00,LEFT,true);

}

applicationchristmas::~applicationchristmas()
{

}

void applicationchristmas::inputReceived(QStringList input)
{

}



void applicationchristmas::tick()
{
    //std::cout<<"show"<<std::endl;
    clear();
    move();
}
