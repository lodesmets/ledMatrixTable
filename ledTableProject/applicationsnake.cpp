#include "applicationsnake.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

applicationSnake::applicationSnake(QObject *parent,ws2811_led_t *ledMatrix) : applicationBase(parent,ledMatrix)
{
    fps = 2;
}

applicationSnake::~applicationSnake()
{

}

void applicationSnake::inputReceived(QStringList input)
{
    if (input[0] == "players")
    {
        if (!playing)
        {
            for (uchar i = 0; i < 4; i++)
            {
                snakes[i]->state = NOTPLAYING;
            }
            for (uchar i = 0; i < input[1].toInt(); i++)
            {
                snakes[i]->state = WAITING;
            }
        }
    }
    else if (input[1] == "ready")
    {
        if (!playing)
        {
            snakes[input[0].toInt()-1]->state = READY;
        }
    }
    else if (snakes[input[0].toInt()-1]->oppositeDirection != directionEnum(input[1].toInt()))
    {
        snakes[input[0].toInt()-1]->direction = directionEnum(input[1].toInt());
    }

}

void applicationSnake::initApp()
{
    /* initialize random seed: */
    srand (time(0));

    snake *temp;
    coordinate * coord1;
    coordinate * coord2;
    temp = new snake;
    temp->state = WAITING;
    temp->color = 0xFF0000;
    temp->direction = RIGHT;
    temp->oppositeDirection = LEFT;
    temp->grow =false;
    coord1 = new coordinate;
    coord2 = new coordinate;
    coord1->x = 2;
    coord1->y = 4;
    coord2->x = 1;
    coord2->y = 4;
    temp->body.append(coord1);
    temp->body.append(coord2);
    snakes.append(temp);

    temp = new snake;
    temp->state = NOTPLAYING;
    temp->color = 0xFF00;
    temp->direction = LEFT;
    temp->oppositeDirection = RIGHT;
    temp->grow =false;
    coord1 = new coordinate;
    coord2 = new coordinate;
    coord1->x = 23;
    coord1->y = 4;
    coord2->x = 24;
    coord2->y = 4;
    temp->body.append(coord1);
    temp->body.append(coord2);
    snakes.append(temp);

    temp = new snake;
    temp->state = NOTPLAYING;
    temp->color = 0xFF;
    temp->direction = RIGHT;
    temp->oppositeDirection = LEFT;
    temp->grow =false;
    coord1 = new coordinate;
    coord2 = new coordinate;
    coord1->x = 2;
    coord1->y = 13;
    coord2->x = 1;
    coord2->y = 13;
    temp->body.append(coord1);
    temp->body.append(coord2);
    snakes.append(temp);

    temp = new snake;
    temp->state = NOTPLAYING;
    temp->color = 0xFFFF00;
    temp->direction = LEFT;
    temp->oppositeDirection = RIGHT;
    temp->grow =false;
    coord1 = new coordinate;
    coord2 = new coordinate;
    coord1->x = 23;
    coord1->y = 13;
    coord2->x = 24;
    coord2->y = 13;
    temp->body.append(coord1);
    temp->body.append(coord2);
    snakes.append(temp);

    createFood();
    playing = false;
}

void applicationSnake::closeApp()
{
    while (!snakes.isEmpty())
    {
        snake * temp = snakes.takeFirst();
        while (!temp->body.isEmpty())
        {
            delete temp->body.takeFirst();
        }
        delete temp;
    }
}

void applicationSnake::createFood()
{
    food.x = rand() % 26;
    food.y = rand() % 18;
}

void applicationSnake::moveSnake()
{
    for (uchar i = 0; i<4 ;i++)
    {
        if (snakes[i]->state == ALIVE)
        {
            coordinate temp1, temp2;
            temp1.x = snakes[i]->body[0]->x;
            temp1.y = snakes[i]->body[0]->y;
            for (uchar j=1; j<snakes[i]->body.size(); j++)
            {
                temp2.x = snakes[i]->body[j]->x;
                temp2.y = snakes[i]->body[j]->y;

                snakes[i]->body[j]->x=temp1.x;
                snakes[i]->body[j]->y=temp1.y;

                temp1 = temp2;
            }
            if (snakes[i]->grow)
            {
                coordinate * temp = new coordinate;
                temp->x = temp1.x;
                temp->y = temp1.y;
                snakes[i]->body.append(temp);
                snakes[i]->grow=false;
            }
            if(snakes[i]->direction == LEFT)
            {
                snakes[i]->body[0]->x--;
                snakes[i]->oppositeDirection = RIGHT;
            }
            else if(snakes[i]->direction == RIGHT)
            {
                snakes[i]->body[0]->x++;
                snakes[i]->oppositeDirection = LEFT;
            }
            else if(snakes[i]->direction == UP)
            {
                snakes[i]->body[0]->y++;
                snakes[i]->oppositeDirection = DOWN;
            }
            else if(snakes[i]->direction == DOWN)
            {
                snakes[i]->body[0]->y--;
                snakes[i]->oppositeDirection = UP;
            }
        }
    }
    checkHit();
}

void applicationSnake::showSnake()
{
    for (uchar i = 0; i<4 ;i++)
    {
        if (snakes[i]->state == ALIVE || snakes[i]->state == READY)
        {
            for (uchar j=0; j<snakes[i]->body.size(); j++)
            {
                matrix[snakes[i]->body[j]->y * WIDTH + snakes[i]->body[j]->x] = snakes[i]->color;
            }
        }
        else if (snakes[i]->state == WAITING)
        {
            for (uchar j=0; j<snakes[i]->body.size(); j++)
            {
                matrix[snakes[i]->body[j]->y * WIDTH + snakes[i]->body[j]->x] = 0xFFFFFF;
            }
        }
    }
    if (playing)
    {
        matrix[food.y * WIDTH + food.x] = 0xFFFFFF;
    }
}

void applicationSnake::checkHit()
{
    for (uchar i = 0; i<4 ;i++)
    {
        if (snakes[i]->state == ALIVE)
        {
            if (snakes[i]->body[0]->x == food.x && snakes[i]->body[0]->y == food.y)
            {
                snakes[i]->grow = true;
                createFood();
            }
            if (snakes[i]->body[0]->x < 0 || snakes[i]->body[0]->x >= WIDTH)
            {
                snakes[i]->state= DEAD;
            }
            else if (snakes[i]->body[0]->y < 0 || snakes[i]->body[0]->y >= HEIGHT)
            {
                snakes[i]->state= DEAD;
            }
            else
            {
                for (uchar j = 0; j<4 ;j++)
                {
                    if (i!=j && snakes[j]->state == ALIVE)
                    {
                        for (uchar k = 0; k<snakes[j]->body.size(); k++)
                        {
                            if (snakes[i]->body[0]->x == snakes[j]->body[k]->x && snakes[i]->body[0]->y == snakes[j]->body[k]->y)
                            {
                                snakes[i]->state = DEAD;
                            }
                        }
                    }
                }
            }

        }
    }
}

void applicationSnake::checkState()
{
    if (playing)
    {
        char i = 0;
        bool looping = true;
        while (looping && (i<4))
        {
            if (snakes[i++]->state == ALIVE)
            {
                looping = false;
            }
        }
        if (looping)
        {
            closeApp();
            initApp();
        }

    }
    else
    {
        char i = 0;
        bool looping = true;
        while (looping && (i<4))
        {
            if (snakes[i++]->state  == WAITING)
            {
                looping = false;
            }
        }
        if (looping)
        {
            playing = true;
            for (uchar i = 0; i < 4; i++)
            {
                if (snakes[i]->state  == READY)
                {
                    snakes[i]->state = ALIVE;
                }
            }
        }
    }
}

void applicationSnake::tick()
{
    clear();
    moveSnake();
    showSnake();
    checkState();
}
