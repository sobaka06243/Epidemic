#include "deadball.h"

DeadBall::DeadBall()
{
timer = new QTimer();
isChange = 0;
}



void DeadBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(Qt::transparent);
    color.setRgb(0,0,0);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect().center(), 10, 10);
    painter->restore();
}

BallItem* DeadBall::Collision(BallItem *a)
{
    return a;
}
