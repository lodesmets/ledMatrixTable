#include "ledmatrix.h"
#include <iostream>

ledMatrix::ledMatrix()
{
    //initialize the ledstring
    ledstring.freq = TARGET_FREQ;
    ledstring.dmanum = DMA;
    ledstring.channel[0].gpionum = GPIO_PIN;
    ledstring.channel[0].gpionum = GPIO_PIN;

    ledstring.channel[0].count = LED_COUNT;
    ledstring.channel[0].invert = 0;
    ledstring.channel[0].brightness = 255;
    ledstring.channel[0].strip_type = STRIP_TYPE;

    if ((ret = ws2811_init(&ledstring)) != WS2811_SUCCESS)
    {
        std::cout<<"ws2811_init failed: "<< ws2811_get_return_t_str(ret) <<std::endl;
    }

    //create and initialize matrix to temporary stores the led
    matrix = new ws2811_led_t[LED_COUNT];
    int x, y;

    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            matrix[y * WIDTH + x]=0;
        }
    }
    //
}


void ledMatrix::matrix_render()
{

    int x, y;
    std::cout<<"update";
    for (x = 0; x < WIDTH; x++)
    {
        for (y = 0; y < HEIGHT; y++)
        {
            ledstring.channel[0].leds[(y * WIDTH) + x] = matrix[y * WIDTH + x];
        }
    }
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
    {
        std::cout<<"ws2811_render failed: "<< ws2811_get_return_t_str(ret)<<std::endl;
    }
}
