#include<QApplication>
#include"ui.h"

int main(int argc,char * argv[])
{
QApplication app(argc,argv);
ui *u=new ui();
u->show();
return app.exec();
}
