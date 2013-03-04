#ifndef UI_H
#define UI_H

#include<QWidget>
#include<QTextEdit>
#include<QLineEdit>
#include"client.h"

class ui:public QWidget
{
Q_OBJECT

public:
ui(QWidget *parent=0);
void arrange();
void policy();

signals:
void takethis(QString);

public slots:
void rAtMain(QString);

private:
QTextEdit *te;
QLineEdit *le;
QString ip;
client *sender;
protected:

void keyPressEvent(QKeyEvent *);
};
#endif


