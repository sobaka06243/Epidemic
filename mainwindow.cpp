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
    N=0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timerOut()));
    scene = new QGraphicsScene();
    scene->setSceneRect(ui->graphicsView->rect());
    scene->setSceneRect(-100,-100,300,300);
    ui->graphicsView->setScene(scene);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(buttonClicked()));
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
        int textInf = ui->lineEdit_Infected->text().toInt();
        int textRecovered = ui->lineEdit_Recovered->text().toInt();
        int textDead = ui->lineEdit_Dead->text().toInt();
        //если таймер шара истек
        if(ball[i]->GetIsChange()){
            int rand = qrand() %100;
            ball[i]->GetTimer()->stop();
            //если шар выздоровил
            if(rand>procent){
                BallItem* rec = new RecoveredBall();
                textInf--;
                textRecovered++;
                ui->lineEdit_Recovered->setText(QString::number(textRecovered));
                ui->lineEdit_Infected->setText(QString::number(textInf));
                rec->setPos(ball[i]->pos());
                rec->SetCurAngle(ball[i]->GetCurAngle());
                rec->SetBallStartPos(ball[i]->GetBallStartPos());
                rec->SetLeng(ball[i]->GetLeng());
                scene->removeItem(ball[i]);
                delete ball[i];
                ball[i] = rec;
                scene->addItem(rec);
            }
            //если шар умер
            else{
                textInf--;
                textDead++;
                ui->lineEdit_Dead->setText(QString::number(textDead));
                ui->lineEdit_Infected->setText(QString::number(textInf));
                 BallItem* dead = new DeadBall();
                 dead->setPos(ball[i]->pos());
                 dead->setPos(ball[i]->pos());
                 scene->removeItem(ball[i]);
                 ball[i] = dead;
                 scene->addItem(dead);
            }
        }
    }
}



void MainWindow::init(int count, int inf, int proc)
{
    Clear();
    N=count;
    infected = inf;
    procent = proc;
    int textHealth = ui->lineEdit->text().toInt() - ui->lineEdit_2->text().toInt();
    ui->lineEdit_Healthy->setText(QString::number(textHealth));
    ui->lineEdit_Infected->setText(ui->lineEdit_2->text());
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i=0;i<N;i++){
        int isFree;
        //создание зараженнных шаров
        if(i<infected){
            InfectedBall* infBall = new InfectedBall();
            ball[i] = infBall;
        }
        //создание здоровых шаров
        else{
            HealthyBall* infBall = new HealthyBall();
            ball[i] = infBall;
        }
        connect(ball[i]->GetTimer(),SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
        //задаем расположение шара
        do{
            isFree = 0;
            ball[i]->setPos(qrand() % 440 - 170, qrand() % 440 - 200);
            for(int j=0;j<i;j++){
                //если на этом место занято, рандомим другое место
                if(ball[i]->collidesWithItem(ball[j])){
                    isFree = 1;
                    break;
                }
            }
        }while(isFree);
        scene->addItem(ball[i]);
        ball[i]->SetBallStartPos(ball[i]->pos());
        ball[i]->SetLeng(1);
        //рандомим старотовый угол
        ball[i]->SetCurAngle(qrand()%360);
    }
    QRectF r = scene->sceneRect();
    //задем границы карты
    if(!lineLeft) lineLeft = scene->addLine(r.center().x() - 250, r.center().y() - 250, r.center().x() - 250, r.center().y() + 250);
    if(!lineRight) lineRight = scene->addLine(r.center().x() + 250, r.center().y() - 250, r.center().x() + 250, r.center().y() + 250);
    if(!lineTop) lineTop = scene->addLine(r.center().x() - 250, r.center().y() - 250, r.center().x() + 250, r.center().y() - 250);
    if(!lineBottom) lineBottom = scene->addLine(r.center().x() - 250, r.center().y() + 250, r.center().x() + 250, r.center().y() + 250);
    timer->start(1);
}

void MainWindow::Clear()
{
    for(int i=0;i<N;i++){
        delete ball[i];
    }
}



void MainWindow::buttonClicked()
{
    init(ui->lineEdit->text().toUInt(),ui->lineEdit_2->text().toUInt(),ui->lineEdit_3->text().toUInt());
}

void MainWindow::slot_timerOut()
{
     for(int i=0;i<N;i++){
         QColor black;
         black.setRgb(0,0,0);
         if(ball[i]->GetColor() != black){
             ball[i]->setPos(getNextPoint(ball[i]->GetBallStartPos(), ball[i]->GetCurAngle(), ball[i]->GetLeng()));
             ball[i]->SetLeng(ball[i]->GetLeng()+1);
             //столкноввние с левой границей
             if(ball[i]->collidesWithItem(lineLeft))
             {
                 ball[i]->SetCurAngle(180 - ball[i]->GetCurAngle());
                 ball[i]->SetBallStartPos(ball[i]->pos());
                 ball[i]->SetLeng(1);
             }
             //столкновыение с правой границей
             else if(ball[i]->collidesWithItem(lineRight))
             {
                 ball[i]->SetCurAngle(540 - ball[i]->GetCurAngle());
                 ball[i]->SetBallStartPos(ball[i]->pos());
                 ball[i]->SetLeng(1);
             }
             //столкновение с нижней границей
             else if(ball[i]->collidesWithItem(lineTop))
             {
                 ball[i]->SetCurAngle(360 - ball[i]->GetCurAngle());
                 ball[i]->SetBallStartPos(ball[i]->pos());
                 ball[i]->SetLeng(1);
             }
             //столкновение с верхней границей
             else if(ball[i]->collidesWithItem(lineBottom))
             {
                 ball[i]->SetCurAngle(360 - ball[i]->GetCurAngle());
                 ball[i]->SetBallStartPos(ball[i]->pos());
                 ball[i]->SetLeng(1);
             }
             for(int j=i+1;j<N;j++){
                 //столкновение шаров
                 if(ball[i]->collidesWithItem(ball[j])){
                     if(ball[j]->GetColor() != black){
                         QColor green;
                         QColor red;
                         green.setGreen(255);
                         red.setRed(255);
                         //выводим информацию пользователю о заражении
                         if((ball[i]->GetColor() == green && ball[j]->GetColor() == red) ||(ball[j]->GetColor() == green && ball[i]->GetColor() == red)){
                             int textInf = ui->lineEdit_Infected->text().toInt();
                             int textHealthy = ui->lineEdit_Healthy->text().toInt();
                             textInf++;
                             textHealthy--;
                             ui->lineEdit_Healthy->setText(QString::number(textHealthy));
                             ui->lineEdit_Infected->setText(QString::number(textInf));
                         }
                         qreal angle = ball[i]->GetCurAngle();
                         ball[i]->SetCurAngle(ball[j]->GetCurAngle());
                         ball[j]->SetCurAngle(angle);
                         ball[i]->SetBallStartPos(ball[i]->pos());
                         ball[j]->SetBallStartPos(ball[j]->pos());
                         ball[i]->SetLeng(1);
                         ball[j]->SetLeng(1);
                         //удаляем со сцены
                         scene->removeItem(ball[i]);
                         scene->removeItem(ball[j]);
                         ball[j] = ball[i]->Collision(ball[j]);
                         ball[i] = ball[j]->Collision(ball[i]);
                         ball[i]->setPos(ball[i]->GetBallStartPos());
                         ball[j]->setPos(ball[j]->GetBallStartPos());
                         connect(ball[j]->GetTimer(),SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
                         connect(ball[i]->GetTimer(),SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
                         //добавляем в сцену
                         scene->addItem(ball[i]);
                         scene->addItem(ball[j]);
                    }
                 }
             }
         }
     }
}
