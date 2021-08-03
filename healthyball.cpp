#include "healthyball.h"

HealthyBall::HealthyBall()
{
    timer = new QTimer();
    isChange = 0;
    color.setGreen(255);
}

BallItem* HealthyBall::Collision(BallItem *a)
{
    return a;
}
