#ifndef DEADBALL_H
#define DEADBALL_H
#include "ballitem.h"
#include <QTimer>

class DeadBall: public BallItem
{
public:
    DeadBall();
    BallItem* Collision(BallItem *a);
};

#endif // DEADBALL_H
