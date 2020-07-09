#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QSignalMapper>
#include <QAction>

#include "ballitem.h"
#include "infectedball.h"
#include "healthyball.h"
#include "recoveredball.h"
#include "deadball.h"
#define N 50
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
    QGraphicsScene *scene;
    BallItem* ball[N];
    //InfectedBall ball[N];
    QGraphicsLineItem *lineLeft;
    QGraphicsLineItem *lineRight;
    QGraphicsLineItem *lineTop;
    QGraphicsLineItem *lineBottom;
    QTimer *timer;
    QPointF ballStartPos[N];
    qreal curAngle[N];
    qreal leng[N];

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

private:
    QPointF getNextPoint(QPointF startPoint, qreal angle, qreal leng);


public:
    void init();


private slots:
    void slot_timerOut();
    void InfectedToRecovered();

};

#endif // MAINWINDOW_H
