#include "applicationpong.h"
#include <iostream>

applicationPong::applicationPong(QObject *parent, ws2811_led_t *ledMatrix) : applicationBase(parent,ledMatrix)
{
    fps = 30;
}

applicationPong::~applicationPong()
{

}

void applicationPong::inputReceived(QStringList input)
{
    if(input[1]=="up")
    {
        if (input[0].toInt()==1)
        {
            yp1++;
            if(yp1>=(HEIGHT-5))
                yp1=HEIGHT-5;
        }
        if (input[0].toInt()==2)
        {
            yp2++;
            if(yp2>=(HEIGHT-5))
                yp2=HEIGHT-5;
        }
    }
    else if(input[1]=="down")
    {
        if (input[0].toInt()==1)
        {
            yp1--;
            if(yp1<=0)
                yp1=0;
        }
        if (input[0].toInt()==2)
        {
            yp2--;
            if(yp2<=0)
                yp2=0;
        }
    }
    else if(input[1]=="ready")
    {
        if (input[0].toInt()==1)
        {
            p1Ready=true;
        }
        if (input[0].toInt()==2)
        {
            p2Ready=true;
        }
    }
}

void applicationPong::draw()
{
    drawRectangle(0,yp1,0,yp1+4,colorP1);
    drawRectangle(WIDTH-1,yp2,WIDTH-1,yp2+4,colorP2);
    drawChar(5,13,QString("%1").arg(p1Score)[0],0x111111,true);
    drawChar(17,13,QString("%1").arg(p2Score)[0],0x111111,true);
    if (state == PLAYING)
    {
        drawRectangle(xball,yball,xball,yball,colorBall);
    }
    if (state == WAITREADY)
    {
        if (p1Ready)
        {
            drawChar(5,5,8730,0xFF00);
        }
        else
        {
            drawChar(5,5,'X',0xFF0000);
        }
        if (p2Ready)
        {
            drawChar(16,5,8730,0xFF00);
        }
        else
        {
            drawChar(16,5,'X',0xFF0000);
        }
    }
    else if (state == COUNTDOWN)
    {
        drawChar(10,5,QString("%1").arg(speedupCounter)[0],0xFFFF00);
    }
}

void applicationPong::moveBall()
{
    if (direction==SLEFT)
    {
        xball--;
    }
    else if (direction==SRIGHT)
    {
        xball++;
    }
    else if (direction==ULEFT)
    {
        xball--;
        yball++;
    }
    else if (direction==URIGHT)
    {
        xball++;
        yball++;
    }
    else if (direction==DLEFT)
    {
        xball--;
        yball--;
    }
    else if (direction==DRIGHT)
    {
        xball++;
        yball--;
    }
    if(yball<0)
    {
        yball =0;
    }
    else if (yball >= HEIGHT)
    {
        yball = HEIGHT-1;
    }

    checkHit();
}



void applicationPong::checkHit()
{
    if (xball == 1)
    {
        if ((yball >= yp1)&&(yball <= yp1+4))
        {
            if (yball == 0)
            {
                direction = URIGHT;
            }
            else if (yball == HEIGHT-1)
            {
                direction = DRIGHT;
            }
            else if (yball == yp1)
            {
                if (direction == ULEFT)
                {
                    direction = SRIGHT;
                }
                else if (direction == DLEFT)
                {
                    direction = DRIGHT;
                }
                else if (direction == SLEFT)
                {
                    direction = DRIGHT;
                }
            }
            else if (yball == yp1+4)
            {
                if (direction == DLEFT)
                {
                    direction = SRIGHT;
                }
                else if (direction == ULEFT)
                {
                    direction = URIGHT;
                }
                else if (direction == SLEFT)
                {
                    direction = URIGHT;
                }
            }
            else
            {
                if (direction == DLEFT)
                {
                    direction = DRIGHT;
                }
                else if (direction == ULEFT)
                {
                    direction = URIGHT;
                }
                else if (direction == SLEFT)
                {
                    direction = SRIGHT;
                }
            }
        }
    }
    else if (xball == WIDTH - 2)
    {
        if ((yball >= yp2)&&(yball <= yp2+4))
        {
            if (yball == 0)
            {
                direction = ULEFT;
            }
            else if (yball == HEIGHT-1)
            {
                direction = DLEFT;
            }
            else if (yball == yp2)
            {
                if (direction == URIGHT)
                {
                    direction = SLEFT;
                }
                else if (direction == DRIGHT)
                {
                    direction = DLEFT;
                }
                else if (direction == SRIGHT)
                {
                    direction = ULEFT;
                }
            }
            else if (yball == yp2+4)
            {
                if (direction == DRIGHT)
                {
                    direction = SLEFT;
                }
                else if (direction == URIGHT)
                {
                    direction = ULEFT;
                }
                else if (direction == SRIGHT)
                {
                    direction = ULEFT;
                }
            }
            else
            {
                if (direction == DRIGHT)
                {
                    direction = DLEFT;
                }
                else if (direction == URIGHT)
                {
                    direction = ULEFT;
                }
                else if (direction == SRIGHT)
                {
                    direction = SLEFT;
                }
            }
        }
    }
    else if (xball == 0)
    {
        state = WAITREADY;
        p1Ready = false;
        p2Ready = false;
        p2Score++;
        speedupCounter = 0;
        xball = 12;
        yball = 8;
        direction = SLEFT;
    }
    else if (xball == WIDTH -1)
    {
        state = WAITREADY;
        p1Ready = false;
        p2Ready = false;
        p1Score++;
        speedupCounter = 0;
        xball = 12;
        yball = 8;
        direction = SRIGHT;
    }
    else if (yball >= HEIGHT-1)
    {
        if (direction == ULEFT)
        {
            direction = DLEFT;
        }
        else if (direction == URIGHT)
        {
            direction = DRIGHT;
        }
    }
    else if (yball <= 0)
    {
        if (direction == DLEFT)
        {
            direction = ULEFT;
        }
        else if (direction == DRIGHT)
        {
            direction = URIGHT;
        }
    }
}

void applicationPong::initApp()
{
    maxTicks = 10;
    state = WAITREADY;
    speedupCounter = 0;
    tickCounter = 0;
    yp1 = 7;
    p1Ready = false;
    colorP1 = 0xFF0000;
    yp2 = 7;
    p2Ready = false;
    colorP2 = 0xFF;
    p1Score = 0;
    p2Score = 0;
    colorBall = 0xFFFFFF;
    xball = 12;
    yball = 8;
}

void applicationPong::tick()
{

    clear();


    if (state == PLAYING)
    {
        if (tickCounter++>maxTicks)
        {
            tickCounter = 0;
            moveBall();
            //speedupCounter++;
        }
    }
    else if (state == WAITREADY)
    {
        tickCounter = 0;
        if (p1Ready && p2Ready)
        {
            state = COUNTDOWN;
            speedupCounter = 3;
        }
    }
    else if (state == COUNTDOWN)
    {
        if (tickCounter++>fps)
        {
            tickCounter = 0;
            speedupCounter--;
            std::cout<<speedupCounter<<std::endl;
            if (speedupCounter == 0)
            {
                state = PLAYING;
            }
        }
    }
    draw();

}
