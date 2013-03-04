#include<QApplication>
#include"ui.h"
#include"server.h"

int main(int argc,char * argv[])
{
QApplication app(argc,argv);
server *ser=new server();
ser->start();
ui *u=new ui();
QObject::connect(ser,SIGNAL(sendtomain(QString)),u,SLOT(rAtMain(QString)));
u->show();
return app.exec();
}
