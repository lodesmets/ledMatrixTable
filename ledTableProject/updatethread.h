#ifndef UPDATETHREAD_H
#define UPDATETHREAD_H
#include <QThread>
#include "ledmatrix.h"

class updateThread : public QThread
{
    Q_OBJECT
public:
    updateThread(ledMatrix *matrix);
    void run();

private:
    ledMatrix *ledmatrix;
};

#endif // UPDATETHREAD_H
