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
    int N;
    int infected;
    int procent;
    QGraphicsScene *scene;
    BallItem* ball[1000];
    QGraphicsLineItem *lineLeft;
    QGraphicsLineItem *lineRight;
    QGraphicsLineItem *lineTop;
    QGraphicsLineItem *lineBottom;
    QTimer *timer;
    QPointF getNextPoint(QPointF startPoint, qreal angle, qreal leng); //следующая позиция щара
    void init(int N, int infected, int procent);
    void Clear();
public:



private slots:
    void slot_timerOut();
    void InfectedToRecovered();
    void buttonClicked();
};

#endif // MAINWINDOW_H
