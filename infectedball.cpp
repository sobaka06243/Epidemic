#include "infectedball.h"

InfectedBall::InfectedBall(QWidget *parent)
    : QWidget(parent)
{
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timerOut()));
    timer->start(5000);
isChange=0;
color.setRgb(255,0,0);
}


BallItem* InfectedBall::Collision(BallItem *a)
{
    QColor green;
    green.setGreen(255);

    if(a->GetColor() == green){
        BallItem* b = new InfectedBall();
        b->SetCurAngle(a->GetCurAngle());
        b->SetLeng(a->GetLeng());
        b->SetBallStartPos(a->GetBallStartPos());

        delete a;
        return b;
    }
    return a;
}

void InfectedBall::slot_timerOut()
{
    isChange = 1;
}


