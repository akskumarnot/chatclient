#ifndef CLIENT_H
#define CLIENT_H

#include<QThread>
#include<QTcpSocket>

class client:public QThread
{
Q_OBJECT
public:
client(QString ip);

public slots:
void tookthis(QString);
void dosomething();
private:
QTcpSocket *cli;

signals:
void sendtomain(QString);

protected:
void run();
};

#endif

