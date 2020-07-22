#ifndef RECOVEREDBALL_H
#define RECOVEREDBALL_H
#include "ballitem.h"
#include <QTimer>

class RecoveredBall: public BallItem
{
public:
    RecoveredBall();
    BallItem* Collision(BallItem *a);
};

#endif // RECOVEREDBALL_H
