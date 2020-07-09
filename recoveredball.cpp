#include "recoveredball.h"

RecoveredBall::RecoveredBall()
{
timer = new QTimer();
isChange=0;
}

void RecoveredBall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(Qt::transparent);
    color.setBlue(255);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect().center(), 10, 10);
    painter->restore();
}

BallItem* RecoveredBall::Collision(BallItem *a)
{
    return a;
}
