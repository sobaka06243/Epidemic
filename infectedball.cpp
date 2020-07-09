#include "infectedball.h"

InfectedBall::InfectedBall(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timerOut()));
    timer->start(5000);
isChange=0;
}


void InfectedBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    painter->save();
    painter->setPen(Qt::transparent);
    Q_UNUSED(widget);
    color.setRgb(255,0,0);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect().center(), 10, 10);
    painter->restore();
}

BallItem* InfectedBall::Collision(BallItem *a)
{
    QColor green;
    green.setGreen(255);
    if(a->color == green){
        delete a;
        a = new InfectedBall();
         return a;
    }
    return a;
}

void InfectedBall::slot_timerOut()
{
    isChange = 1;
}

/*void InfectedBall::slot_timerOut()
{
    int b = 0;
    int a = 10/b;
    timer->stop();
}*/
