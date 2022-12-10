#include "widgets.h"
#include "franklin.h"
Widgets::Widgets(QString l, int w, int index_x, int index_y)
{
QFont font;
//font.setBold(true);
font.setPixelSize(20);
setDefaultTextColor(Qt::white);
setFont(font);
setPos(index_x,index_y);
count = w;
label = l;
setPlainText(label+ QString::number(count));

}
void Widgets:: setTime(int t){
    count=t;
}
void Widgets::timers2(){

//    if(count>=0){
//         QTimer *timer2 = new QTimer();
//    timer2->start(10000);
//    connect(timer2,SIGNAL(timeout()),&franklin,SLOT(decrease_t(t)));
     count--;

    setPlainText(label+ QString::number(count));
}
void Widgets::timers(){
    count--;
    setPlainText(label+ QString::number(count));
}

