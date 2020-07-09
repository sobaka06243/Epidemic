#ifndef INFECTEDBALL_H
#define INFECTEDBALL_H
#include "ballitem.h"
#include "healthyball.h"
#include <QTimer>
#include <QWidget>

class InfectedBall :public QWidget, public BallItem
{
    Q_OBJECT
public:
    InfectedBall(QWidget *parent = 0);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    BallItem* Collision(BallItem *a);
public slots:
    void slot_timerOut();
};

#endif // INFECTEDBALL_H
