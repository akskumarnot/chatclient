#include"client.h"
#include<QDebug>
#include<QByteArray>
#include<QDataStream>


client::client(QString ip)
{
cli=new QTcpSocket(this);
cli->connectToHost(ip,9985);

if(cli->waitForConnected(3000))
  {this->start();}
else
 {qDebug()<<"not connecting";}
}



void client::run()
{
qDebug()<<"hurrah got connection!!!";
exec();
}


void client::tookthis(QString str)
{  cli->flush();
   QByteArray arr;
   QDataStream stream(&arr,QIODevice::WriteOnly);
   stream<<str;
  cli->write(arr);
  cli->flush();
}





