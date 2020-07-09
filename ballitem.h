#ifndef BALLITEM_H
#define BALLITEM_H

#include <QGraphicsItem>
#include <QPainter>



 class BallItem : public QGraphicsEllipseItem
{
//    Q_OBJECT

    Q_INTERFACES(QGraphicsItem)

public:
    BallItem();

    QRectF boundingRect() const; //возвращение области
  //  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //отрисовка шара
    QPainterPath shape() const; //возвращаем точную форму элемента

    QColor GetColor();
    virtual BallItem* Collision(BallItem *a) = 0;
    QColor color;
    QTimer* timer;
    int isChange;
 protected:


signals:
    
public slots:
   // void slot
};

#endif // BALLITEM_H
