#include"ui.h"
#include<QScrollArea>
#include<QVBoxLayout>
#include<QSizePolicy>
#include<QKeyEvent>
#include<QDebug>

ui::ui(QWidget *parent):QWidget(parent)
{
te=new QTextEdit("this is nice",this);
te->setReadOnly(true);
le=new QLineEdit("default");
sender=NULL;
arrange();
policy();
setFixedSize(500,370);
setWindowTitle("LUGM's chat client");
}

void ui::arrange()
{
QVBoxLayout *lay=new QVBoxLayout(this);
lay->addWidget(te);
lay->addWidget(le);
lay->setAlignment(le,Qt::AlignHCenter);
}

void ui::policy()
{
le->setFixedSize(450,30);
}

void ui::keyPressEvent(QKeyEvent *e)
{
if((le->hasFocus()==true) && (e->key()==Qt::Key_Return))
 { QString str=le->text();
   if(str.left(8)=="$connect") 
    {int i;
    	 for(i=8;(i<str.length()) && (str[i]==' ');i++);
      		ip=str.mid(i,str.length());
    		 if(ip=="")
      			 {te->append("\nthere dosent seem to be anything");
    			 le->setText("");
                         }
     		 else 
    		 {
       			if(sender==NULL)
        			 { sender=new client(ip);
				   connect(sender,SIGNAL(sendtomain(QString)),this,SLOT(rAtMain(QString)));
                                   connect(this,SIGNAL(takethis(QString)),sender,SLOT(tookthis(QString)));
                                  }
      			 else
         			{te->append("\nalready connected to server");}
                 }

       le->setText("");
    }

  else if(str.left(11)=="$disconnect")
         {if(sender!=NULL){sender->terminate();delete sender;}}

  else{
   te->append("\n"+le->text());
  	
    if(sender!=NULL)
     {
      emit takethis(le->text());
     } 
   le->setText(""); 
  }      
 }

}

void ui::rAtMain(QString str)
{
te->append("\n"+str);
}





