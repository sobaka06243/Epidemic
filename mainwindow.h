#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QSignalMapper>
#include <QAction>
#include "qmath.h"
#include <QTime>
#include <QLabel>
#include <QVector>
#include <QRandomGenerator>
#include <random>

#include "ballitem.h"
#include "infectedball.h"
#include "healthyball.h"
#include "recoveredball.h"
#include "deadball.h"
#include "line.h"
#include "lineleft.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    int ballCount; //всего шаров
    int infected; //начальное кол-во зараженных шаров
    int procent; //процент смерти
    int const mapBorder = 250; //границы карты
    int const speedBall = 15;
    QGraphicsScene *scene;
   // BallItem* ball[1000];
    QVector <BallItem*> ballVector;
    QGraphicsLineItem *lineLeft;
    QGraphicsLineItem *lineRight;
    QGraphicsLineItem *lineTop;
    QGraphicsLineItem *lineBottom;
    int check = 0;
    QTimer *timer;
    QPointF getNextPoint(QPointF startPoint, qreal angle, qreal leng); //следующая позиция щара
    void CreateBalls();
    void AddBallToMap(BallItem*ball);
    void Init();
    void ClearMap();
    void CollidedLine(BallItem* ball,int angle); //обработка столкновения
    void isCollideLine(BallItem *ball, QGraphicsLineItem* line, int angle); //проверка на столковение
    void MapBorder(); //границы карты

public:



private slots:
    void slot_timerOut();
    void InfectedToRecovered();
    void buttonClicked();
};

#endif // MAINWINDOW_H
