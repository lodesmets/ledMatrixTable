#include <QCoreApplication>
#include "controllerclass.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    controllerClass * controller = new controllerClass(&a);
    controller->start();

    return a.exec();
}
