#ifndef BALLITEM_H
#define BALLITEM_H

#include <QGraphicsItem>
#include <QPainter>

class BallItem : public QGraphicsEllipseItem
{

   Q_INTERFACES(QGraphicsItem)

public:
   BallItem();

   QRectF boundingRect() const; //возвращение области
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //отрисовка шара
   QPainterPath shape() const; //возвращаем точную форму элемента

   QColor GetColor();
   QTimer* GetTimer();
   int GetIsChange();
   QPointF GetBallStartPos();
   qreal GetCurAngle();
   qreal GetLeng();

   void SetBallStartPos(QPointF ballStartPos);
   void SetCurAngle(qreal curAngle);
   void SetLeng(qreal leng);

   virtual BallItem* Collision(BallItem *a) = 0; //взаимодействие с другим шаром

   protected:
   QColor color;
   QTimer* timer;
   int isChange;
   QPointF ballStartPos;
   qreal curAngle;
   qreal leng;

signals:

public slots:

};

#endif // BALLITEM_H
