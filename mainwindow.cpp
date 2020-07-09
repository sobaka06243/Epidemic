#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "qmath.h"
#include <QTime>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = 0;


    lineLeft = 0;
    lineRight = 0;
    lineTop = 0;
    lineBottom = 0;


    //curAngle = qrand()%360;

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timerOut()));
    scene = new QGraphicsScene();
       // scene->setSceneRect(ui->graphicsView->rect());
    scene->setSceneRect(-100,-100,300,300);
        //scene->set
        ui->graphicsView->setScene(scene);
        QLabel* label_all = new QLabel();
        label_all->setText("Количество шаров: ");
        label_all->move(200,200);
        //scene->addItem(label_all);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPointF MainWindow::getNextPoint(QPointF startPoint, qreal angle, qreal leng)
{
    QPointF point;

    qreal angleRad = ((angle + 90) * M_PI)/180;

    point.setX(startPoint.x() + (leng * sin(angleRad)));
    point.setY(startPoint.y() + (leng * cos(angleRad)));

    return point;
}

void MainWindow::InfectedToRecovered()
{
    for(int i=0;i<N;i++){
       // bool n = ball[i]->timer;

        if(ball[i]->isChange){
            int rand = qrand() %100;
            ball[i]->timer->stop();
            if(rand>15){
            BallItem* rec = new RecoveredBall();
            rec->setPos(ball[i]->pos());
            scene->removeItem(ball[i]);
            delete ball[i];
            ball[i] = rec;
            scene->addItem(rec);
            }
            else{
                 BallItem* dead = new DeadBall();
                 dead->setPos(ball[i]->pos());
                 dead->setPos(ball[i]->pos());
                 scene->removeItem(ball[i]);
                 ball[i] = dead;
                 scene->addItem(dead);
            }
        }
    }





   // scene->addItem(infBall);
}



void MainWindow::init()
{

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i=0;i<N;i++){
        //ball[i].setPos(scene->sceneRect().center());
        int isFree;
        if(i<N*0.1){
            InfectedBall* infBall = new InfectedBall();

           // infBall->timer->start(1000);
            ball[i] = infBall;
            connect(infBall->timer,SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
            //connect(infBall->timer,&QTimer::timeout, [i](){InfectedToRecovered(i++);});
        }
        if(i>=N*0.1){
            HealthyBall* infBall = new HealthyBall();
           // connect(infBall->timer,SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
            ball[i] = infBall;
        }
        do{
            isFree = 0;
        ball[i]->setPos(qrand() % 440 - 170, qrand() % 440 - 200);
        for(int j=0;j<i;j++){
            if(ball[i]->collidesWithItem(ball[j])){
                isFree = 1;
                break;
            }
        }
        }while(isFree);
        //ball[i].setPos(-170, -200);
        //ball[i].setPos(270, 240);
        // ball[i].setPos(rand() % 440 - 170, rand() % 440 - 200);
        scene->addItem(ball[i]);
        //QGraphicsEllipseItem* ell = new QGraphicsEllipseItem();

        ballStartPos[i] = ball[i]->pos();
        leng[i] = 1;
        curAngle[i] = qrand()%360;
       // curAngle[i] = 360;
    }
    //ball->setPos(scene->sceneRect().center());

    QRectF r = scene->sceneRect();
    if(!lineLeft) lineLeft = scene->addLine(r.center().x() - 250, r.center().y() - 250, r.center().x() - 250, r.center().y() + 250);
    if(!lineRight) lineRight = scene->addLine(r.center().x() + 250, r.center().y() - 250, r.center().x() + 250, r.center().y() + 250);
    if(!lineTop) lineTop = scene->addLine(r.center().x() - 250, r.center().y() - 250, r.center().x() + 250, r.center().y() - 250);
    if(!lineBottom) lineBottom = scene->addLine(r.center().x() - 250, r.center().y() + 250, r.center().x() + 250, r.center().y() + 250);
    timer->start(1);
}

void MainWindow::slot_timerOut()
{
     for(int i=0;i<N;i++){
         QColor color;
         color.setRgb(0,0,0);
         if(ball[i]->color != color){
         ball[i]->setPos(getNextPoint(ballStartPos[i], curAngle[i], leng[i]));
         leng[i]++;
     if(ball[i]->collidesWithItem(lineLeft))
     {
         curAngle[i] = 90 + (90 - curAngle[i]);
         ballStartPos[i] = this->ball[i]->pos();
         leng[i] = 1;

     }
     else if(ball[i]->collidesWithItem(lineRight))
     {
         curAngle[i] = 270 + (270 - curAngle[i]);
         ballStartPos[i] = this->ball[i]->pos();
         leng[i] = 1;

     }
     else if(ball[i]->collidesWithItem(lineTop))
     {
         curAngle[i] = 360-curAngle[i];
         ballStartPos[i] = this->ball[i]->pos();
         leng[i] = 1;

     }
     else if(ball[i]->collidesWithItem(lineBottom))
     {
         curAngle[i] = 180 + (180 - curAngle[i]);
         ballStartPos[i] = this->ball[i]->pos();
         leng[i] = 1;

     }
     for(int j=i+1;j<N;j++){
     if(ball[i]->collidesWithItem(ball[j])){
         if(ball[j]->color != color){
         qreal angle = curAngle[i];
         curAngle[i] = curAngle[j];
         curAngle[j] = angle;
         ballStartPos[i] = ball[i]->pos();
         ballStartPos[j] = ball[j]->pos();
         leng[i] = 1;
         leng[j] = 1;
         scene->removeItem(ball[i]);
         scene->removeItem(ball[j]);
         ball[j] = ball[i]->Collision(ball[j]);
         ball[i] = ball[j]->Collision(ball[i]);
         ball[i]->setPos(ballStartPos[i]);
         ball[j]->setPos(ballStartPos[j]);
         connect(ball[j]->timer,SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
         connect(ball[i]->timer,SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
         scene->addItem(ball[i]);
         scene->addItem(ball[j]);
}
     }
     }
     }
     }
}
