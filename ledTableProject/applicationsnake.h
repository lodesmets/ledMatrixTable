#ifndef APPLICATIONSNAKE_H
#define APPLICATIONSNAKE_H

#include "applicationbase.h"

enum playerState {NOTPLAYING, ALIVE, DEAD, READY, WAITING};

struct coordinate
{
    int x;
    int y;
};

struct snake
{
    QVector <coordinate *> body;
    directionEnum direction;
    directionEnum oppositeDirection;
    playerState state;
    ws2811_led_t color;
    bool grow;
};

class applicationSnake : public applicationBase
{
public:
    applicationSnake(QObject *parent,ws2811_led_t *ledMatrix);
    ~applicationSnake();
    void inputReceived(QStringList input);


private:
    coordinate food;
    QVector <snake *> snakes;
    bool playing;
    void initApp();
    void closeApp();
    void createFood();
    void moveSnake();
    void showSnake();
    void checkHit();
    void checkState();

private slots:
    void tick();
};

#endif // APPLICATIONSNAKE_H
