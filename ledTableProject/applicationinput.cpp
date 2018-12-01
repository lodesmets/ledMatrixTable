#include "applicationinput.h"
#include <QTextStream>
#include "settings"
#include<QStringList>

void applicationInput::tick()
{

}

applicationInput::applicationInput(QObject *parent, ws2811_led_t *ledMatrix) : applicationBase(parent,ledMatrix)
{

}

applicationInput::~applicationInput()
{

}

void applicationInput::inputReceived(QStringList input)
{
    uint x,y,value;
    bool ok;
    x=input[0].toInt();
    y=input[1].toInt();
    value=input[2].toInt(&ok,16);
    matrix[y * WIDTH + x]=value;
}

void applicationInput::initApp()
{
    clear();
    stopShowingText();
}
