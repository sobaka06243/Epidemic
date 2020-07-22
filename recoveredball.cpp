#include "recoveredball.h"

RecoveredBall::RecoveredBall()
{
timer = new QTimer();
isChange=0;
color.setBlue(255);
}



BallItem* RecoveredBall::Collision(BallItem *a)
{
    return a;
}
