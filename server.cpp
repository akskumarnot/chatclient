#include"server.h"
#include<QHostAddress>
#include<QTcpSocket>

server::server()
{
ser=new QTcpServer(this);
connect(ser,SIGNAL(newConnection()),this,SLOT(newConnection()));
ser->listen(QHostAddress::Any,9982);
}


void server::run()
{
exec();
}


void server::newConnection()
{
qDebug()<<"lol got connected";
soc=ser->nextPendingConnection();
connect(soc,SIGNAL(readyRead()),this,SLOT(something()));
}

void server::something()
{
QDataStream stream(soc);
QString str;
stream>>str;
emit sendtomain(str);
soc->flush();
}

