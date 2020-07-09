#include "ballitem.h"

BallItem::BallItem()
{
}

QRectF BallItem::boundingRect() const
{
    return QRectF(-25, -25, 50, 50);
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
