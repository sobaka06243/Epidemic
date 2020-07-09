#ifndef DEADBALL_H
#define DEADBALL_H
#include "ballitem.h"
#include <QTimer>

class DeadBall: public BallItem
{
public:
    DeadBall();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BallItem* Collision(BallItem *a);
};

#endif // DEADBALL_H
