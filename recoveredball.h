#ifndef RECOVEREDBALL_H
#define RECOVEREDBALL_H
#include "ballitem.h"
#include <QTimer>

class RecoveredBall: public BallItem
{
public:
    RecoveredBall();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BallItem* Collision(BallItem *a);
};

#endif // RECOVEREDBALL_H
