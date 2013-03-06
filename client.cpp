#include"client.h"
#include<QDebug>
#include<QByteArray>
#include<QDataStream>


client::client(QString ip)
{
cli=new QTcpSocket(this);
cli->connectToHost(ip,9982);

if(cli->waitForConnected(10000))
  {
connect(cli,SIGNAL(readyRead()),this,SLOT(dosomething()));
this->start();}
else
 {qDebug()<<"not connecting";}
}



void client::run()
{
qDebug()<<"hurrah got connection!!!";
exec();
}


void client::tookthis(QString str)
{  
   cli->flush();
   QByteArray arr;
   QDataStream stream(&arr,QIODevice::WriteOnly);
   stream<<str;
  cli->write(arr);
  cli->flush();
}


void client::dosomething()
{
cli->flush();
qDebug()<<"used";
QDataStream stream(cli);
QString str;
stream>>str;
emit sendtomain(str);
cli->flush();
}



