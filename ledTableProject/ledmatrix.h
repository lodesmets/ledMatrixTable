#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <QTimer>
#include "ws2811.h"
#include "settings"

class ledMatrix : public QObject
{
    Q_OBJECT
public:
    ledMatrix();
    ws2811_led_t * returnMatrix() {return matrix;}
private:
    ws2811_t ledstring;
    ws2811_led_t *matrix;
    ws2811_return_t ret;

private slots:
    void matrix_render();
};

#endif // LEDMATRIX_H
