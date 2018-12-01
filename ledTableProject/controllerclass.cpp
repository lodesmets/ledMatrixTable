#include "controllerclass.h"
#include <unistd.h>

#include "applicationinput.h"
#include "applicationtest.h"
#include "applicationpong.h"
#include "applicationsnake.h"
#include "applicationstart.h"
#include "applicationchristmas.h"
#include <QHostInfo>
controllerClass::controllerClass(QObject *parent) : QObject(parent)
{
    //create tcp server
    tcpServer=new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::Any,0)){
        std::cout<<"Error, could not start server"<<std::endl;
    }
    std::cout<<tcpServer->serverPort()<<std::endl;
    connect(tcpServer,&QTcpServer::newConnection,this,&controllerClass::newConnection);
    //

    /*ledMatrixController = new ledMatrix;
    t = new updateThread(ledMatrixController);
    t->start();*/


    //initialize the ledstring
    ledstring.freq = TARGET_FREQ;
    ledstring.dmanum = DMA;
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


    for (int x = 0; x < LED_COUNT; x++)
    {   
        matrix[x]=0;
    }
    //
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(matrix_render()));
    timer->start(FRAMETIME);

    apps.insert("input",new applicationInput(this,matrix));
    apps.insert("test",new applicationTest(this,matrix));
    apps.insert("pong",new applicationPong(this,matrix));
    apps.insert("snake",new applicationSnake(this,matrix));
    apps.insert("start",new applicationStart(this,matrix,"192.168.0.138",tcpServer->serverPort()));
    apps.insert("christmas",new applicationchristmas(this,matrix));
    activeApp = apps.value("christmas");
    activeApp->start();
}

controllerClass::~controllerClass()
{
    delete tcpServer;
    ws2811_fini(&ledstring);

}

void controllerClass::start()
{

}


void controllerClass::newConnection()
{
    QTcpSocket *socket= tcpServer->nextPendingConnection();

    connect(socket,&QTcpSocket::readyRead,[=](){
        QString message=socket->readLine();
        std::cout<<message.toStdString()<<std::endl;
        QStringList messageList=message.split('>');
        if (messageList.at(0)=="newUser"){
            users[messageList.at(1).toInt()]=messageList.at(1);
            socket->write(QString("%1OK").arg(messageList.at(1)).toUtf8());
        }
        else if (messageList.at(0)=="active")
        {
            activeApp->stop();
            activeApp = apps.value(messageList.at(1));
            activeApp->start();
        }
        else
            activeApp->inputReceived(messageList);

    });
}

void controllerClass::matrix_render()
{

    for (uchar x = 0; x < WIDTH; x++)
    {
        for (uchar y = 0; y < HEIGHT; y++)
        {
            if (y%2==0)
                ledstring.channel[0].leds[(y * WIDTH) + x] = matrix[y * WIDTH + x];
            else
                ledstring.channel[0].leds[(y * WIDTH) + (WIDTH-1-x)] = matrix[y * WIDTH + x];

        }
    }
    if ((ret = ws2811_render(&ledstring)) != WS2811_SUCCESS)
    {
        std::cout<<"ws2811_render failed: "<< ws2811_get_return_t_str(ret)<<std::endl;
    }
}

