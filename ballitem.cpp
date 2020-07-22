#include "ballitem.h"

BallItem::BallItem()
{
}

QRectF BallItem::boundingRect() const
{
    return QRectF(-25, -25, 50, 50);
}

void BallItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->save();
    painter->setPen(Qt::transparent);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect().center(), 10, 10);
    painter->restore();
}

QPainterPath BallItem::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect().center(), 10, 10);
    return path;
}

QColor BallItem::GetColor()
{
    return color;
}

QTimer *BallItem::GetTimer()
{
    return timer;
}

int BallItem::GetIsChange()
{
    return isChange;
}

QPointF BallItem::GetBallStartPos()
{
    return ballStartPos;
}

qreal BallItem::GetCurAngle()
{
    return curAngle;
}

qreal BallItem::GetLeng()
{
    return leng;
}

void BallItem::SetBallStartPos(QPointF ballStartPos)
{
    this->ballStartPos = ballStartPos;
}

void BallItem::SetCurAngle(qreal curAngle)
{
    this->curAngle = curAngle;
}

void BallItem::SetLeng(qreal leng)
{
    this->leng = leng;
}
