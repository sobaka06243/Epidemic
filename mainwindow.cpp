#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lineLeft = 0;
    lineRight = 0;
    lineTop = 0;
    lineBottom = 0;
    ballCount = 0;
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
    for(int i=0; i < ballCount; i++){
        int textInf = ui->lineEdit_Infected->text().toInt();
        int textRecovered = ui->lineEdit_Recovered->text().toInt();
        int textDead = ui->lineEdit_Dead->text().toInt();
        //если таймер шара истек
        if(ballVector[i]->GetIsChange()){
            int random = rand() %100;
            ballVector[i]->GetTimer()->stop();
            //если шар выздоровил
            if(random > procent){
                BallItem* rec = new RecoveredBall();
                textInf--;
                textRecovered++;
                ui->lineEdit_Recovered->setText(QString::number(textRecovered));
                ui->lineEdit_Infected->setText(QString::number(textInf));
                rec->setPos(ballVector[i]->pos());
                rec->SetCurAngle(ballVector[i]->GetCurAngle());
                rec->SetBallStartPos(ballVector[i]->GetBallStartPos());
                rec->SetLeng(ballVector[i]->GetLeng());
                scene->removeItem(ballVector[i]);
                delete ballVector[i];
                ballVector[i] = rec;
                scene->addItem(rec);
            }
            //если шар умер
            else{
                textInf--;
                textDead++;
                ui->lineEdit_Dead->setText(QString::number(textDead));
                ui->lineEdit_Infected->setText(QString::number(textInf));
                 BallItem* dead = new DeadBall();
                 dead->setPos(ballVector[i]->pos());
                 dead->setPos(ballVector[i]->pos());
                 scene->removeItem(ballVector[i]);
                 ballVector[i] = dead;
                 scene->addItem(dead);
            }
        }
    }
}


void MainWindow::CreateBalls()
{
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i = 0;i < ballCount; i++){
        int isFree;
        //создание зараженнных шаров
        if(i < infected){
            InfectedBall* infBall = new InfectedBall();
            ballVector.push_back(infBall);
        }
        //создание здоровых шаров
        else{
            HealthyBall* infBall = new HealthyBall();
            ballVector.push_back(infBall);
        }
        connect(ballVector[i]->GetTimer(),SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
        //задаем расположение шара
        do{
            isFree = 0;
            ballVector[i]->setPos(rand() % 440 - 170, rand() % 440 - 200);
            for(int j=0;j<i;j++){
                //если на этом место занято, рандомим другое место
                if(ballVector[i]->collidesWithItem(ballVector[j])){
                    isFree = 1;
                    break;
                }
            }
        } while(isFree);
        scene->addItem(ballVector[i]);
        ballVector[i]->SetBallStartPos(ballVector[i]->pos());
        ballVector[i]->SetLeng(1);
        //рандомим старотовый угол
        ballVector[i]->SetCurAngle(rand()%360);
    }
    //задем границы карты
    MapBorder();

    timer->start(speedBall);
}

void MainWindow::MapBorder()
{
    QRectF sceneRect = scene->sceneRect();
    if(!lineLeft) lineLeft = scene->addLine(sceneRect.center().x() - mapBorder, sceneRect.center().y() - mapBorder, sceneRect.center().x() - mapBorder, sceneRect.center().y() + mapBorder);
    if(!lineRight) lineRight = scene->addLine(sceneRect.center().x() + mapBorder, sceneRect.center().y() - mapBorder, sceneRect.center().x() + mapBorder, sceneRect.center().y() + mapBorder);
    if(!lineTop) lineTop = scene->addLine(sceneRect.center().x() - mapBorder, sceneRect.center().y() - mapBorder, sceneRect.center().x() + mapBorder, sceneRect.center().y() - mapBorder);
    if(!lineBottom) lineBottom = scene->addLine(sceneRect.center().x() - mapBorder, sceneRect.center().y() + mapBorder, sceneRect.center().x() + mapBorder, sceneRect.center().y() + mapBorder);
}

void MainWindow::ClearMap()
{
    for(int i = 0; i < ballCount; i++){
        BallItem* tmp = ballVector.front();
        ballVector.pop_front();
        delete tmp;
    }
    ui->lineEdit_Recovered->setText("0");
    ui->lineEdit_Dead->setText("0");
}



void MainWindow::buttonClicked()
{
    ClearMap();
    Init();
    CreateBalls();
}

void MainWindow::Init()
{
    ballCount = ui->lineEdit->text().toUInt();
    infected = ui->lineEdit_2->text().toUInt();
    procent = ui->lineEdit_3->text().toUInt();
    int textHealth = ui->lineEdit->text().toInt() - ui->lineEdit_2->text().toInt();
    ui->lineEdit_Healthy->setText(QString::number(textHealth));
    ui->lineEdit_Infected->setText(ui->lineEdit_2->text());
}

void MainWindow::CollidedLine(BallItem* ball,int angle)
{
    ball->SetCurAngle(angle - ball->GetCurAngle());
    ball->SetBallStartPos(ball->pos());
    ball->SetLeng(1);
}

void MainWindow::isCollideLine(BallItem *ball, QGraphicsLineItem* line, int angle)
{
    if(ball->collidesWithItem(line))
    {
        CollidedLine(ball,angle);
    }
}

void MainWindow::slot_timerOut()
{
     for(int i = 0; i < ballCount; i++){
         QColor black;
         black.setRgb(0,0,0);
         if(ballVector[i]->GetColor() != black){
             ballVector[i]->setPos(getNextPoint(ballVector[i]->GetBallStartPos(), ballVector[i]->GetCurAngle(), ballVector[i]->GetLeng()));
             ballVector[i]->SetLeng(ballVector[i]->GetLeng()+1);

             //столкноввние с левой границей
             isCollideLine(ballVector[i],lineLeft,180);

             //столкновыение с правой границей
             isCollideLine(ballVector[i],lineRight,540);

             //столкновение с нижней границей
             isCollideLine(ballVector[i],lineBottom,360);

             //столкновение с верхней границей
             isCollideLine(ballVector[i],lineTop,360);

             for(int j=i+1;j<ballCount;j++){
                 //столкновение шаров
                 if(ballVector[i]->collidesWithItem(ballVector[j])){
                     if(ballVector[j]->GetColor() != black){
                         QColor green;
                         QColor red;
                         green.setGreen(255);
                         red.setRed(255);
                         //выводим информацию пользователю о заражении
                         if((ballVector[i]->GetColor() == green && ballVector[j]->GetColor() == red) ||(ballVector[j]->GetColor() == green && ballVector[i]->GetColor() == red)){
                             int textInf = ui->lineEdit_Infected->text().toInt();
                             int textHealthy = ui->lineEdit_Healthy->text().toInt();
                             textInf++;
                             textHealthy--;
                             ui->lineEdit_Healthy->setText(QString::number(textHealthy));
                             ui->lineEdit_Infected->setText(QString::number(textInf));
                         }
                         qreal angle = ballVector[i]->GetCurAngle();
                         ballVector[i]->SetCurAngle(ballVector[j]->GetCurAngle());
                         ballVector[j]->SetCurAngle(angle);
                         ballVector[i]->SetBallStartPos(ballVector[i]->pos());
                         ballVector[j]->SetBallStartPos(ballVector[j]->pos());
                         ballVector[i]->SetLeng(1);
                         ballVector[j]->SetLeng(1);
                         //удаляем со сцены
                         scene->removeItem(ballVector[i]);
                         scene->removeItem(ballVector[j]);
                         ballVector[j] = ballVector[i]->Collision(ballVector[j]);
                         ballVector[i] = ballVector[j]->Collision(ballVector[i]);
                         ballVector[i]->setPos(ballVector[i]->GetBallStartPos());
                         ballVector[j]->setPos(ballVector[j]->GetBallStartPos());
                         connect(ballVector[j]->GetTimer(),SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
                         connect(ballVector[i]->GetTimer(),SIGNAL(timeout()),this,SLOT(InfectedToRecovered()));
                         //добавляем в сцену
                         scene->addItem(ballVector[i]);
                         scene->addItem(ballVector[j]);
                    }
                 }
             }
         }
     }
}

