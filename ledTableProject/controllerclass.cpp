#include "controllerclass.h"

controllerClass::controllerClass(QObject *parent) : QObject(parent)
{
    tcpServer=new QTcpServer(this);
    if(!tcpServer->listen(QHostAddress::Any,3000)){
        std::cout<<"Error, could not start server"<<std::endl;
    }
    connect(tcpServer,&QTcpServer::newConnection,this,&controllerClass::newConnection);


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
        if (messageList.size()==3){
            if (messageList.at(0)=="newUser"){
                users[messageList.at(1).toInt()]=messageList.at(1);
                socket->write(QString("%1OK").arg(messageList.at(1)).toUtf8());
            }
        }

    });
}

