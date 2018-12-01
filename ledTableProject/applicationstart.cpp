#include "applicationstart.h"

applicationStart::applicationStart(QObject *parent,ws2811_led_t *ledMatrix, QString ipAddress, int port) : applicationBase(parent,ledMatrix)
{
    fps = 6;
    QString ipAndPort = ipAddress+":"+QString("%1").arg(port);

    addText(26,8,ipAndPort,0xFF0000, LEFT, true);
}

applicationStart::~applicationStart()
{

}

void applicationStart::inputReceived(QStringList input)
{

}



void applicationStart::tick()
{
    clear();
    move();
}
