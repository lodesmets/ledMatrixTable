#include "updatethread.h"

updateThread::updateThread(ledMatrix *matrix) :ledmatrix(matrix)
{

}

void updateThread::run()
{
    QTimer timer;

    connect(&timer, SIGNAL(timeout()), ledmatrix, SLOT(matrix_render()));
    timer.start(FRAMETIME);

    exec();
}
