#ifndef SERVER_H
#define SERVER_H
#include<QThread>
#include<QTcpServer>
class server:public QThread
{
Q_OBJECT
public:
server();

public slots:

void newConnection();
void something(); 

signals:
void sendtomain(QString);

private:
QTcpServer *ser;
QTcpSocket *soc;

protected:

void run();
};

#endif

