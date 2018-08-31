#ifndef APPLICATIONPONG_H
#define APPLICATIONPONG_H

#include "applicationbase.h"

enum ballDirection {SLEFT,SRIGHT,ULEFT,URIGHT,DLEFT,DRIGHT};
enum stateEnum {PLAYING, WAITREADY, COUNTDOWN};

class applicationPong : public applicationBase
{
public:
    applicationPong(QObject *parent,ws2811_led_t *ledMatrix);
    ~applicationPong();
    void inputReceived(QStringList input);

private:
    int yp1,yp2,xball,yball;
    uchar p1Score, p2Score;
    uchar tickCounter, maxTicks, speedupCounter;
    bool p1Ready, p2Ready;
    stateEnum state;
    ballDirection direction;
    ws2811_led_t colorBall, colorP1, colorP2, colorText;
    void draw();
    void moveBall();
    void checkHit();

private slots:
    void tick();
};

#endif // APPLICATIONPONG_H
