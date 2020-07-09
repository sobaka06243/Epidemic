#include "healthyball.h"

HealthyBall::HealthyBall()
{
timer = new QTimer();
isChange = 0;
}



void HealthyBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(Qt::transparent);
    color.setGreen(255);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect().center(), 10, 10);
    painter->restore();
}

BallItem* HealthyBall::Collision(BallItem *a)
{
    return a;
}
