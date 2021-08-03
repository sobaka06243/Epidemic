#include "deadball.h"

DeadBall::DeadBall()
{
    timer = new QTimer();
    isChange = 0;
    color.setRgb(0,0,0);
}

BallItem* DeadBall::Collision(BallItem *a)
{
    return a;
}
