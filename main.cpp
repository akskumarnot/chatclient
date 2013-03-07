#include<QApplication>
#include"ui.h"
#include"server.h"

int main(int argc,char * argv[])
{
QApplication app(argc,argv);
server *s=new server();
s->start();
ui *u=new ui();
QObject::connect(s,SIGNAL(sendtomain(QString)),u,SLOT(rAtMain(QString)));
u->show();
return app.exec();
}
