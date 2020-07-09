#ifndef HEALTHYBALL_H
#define HEALTHYBALL_H
#include "ballitem.h"
#include <QTimer>

class HealthyBall : public BallItem
{
public:
    HealthyBall();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BallItem* Collision(BallItem *a);
};

#endif // HEALTHYBALL_H
