#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    background(new QMovie)
{
    ui->setupUi(this);
    setStyleSheet("background:transparent;border:0px");
    scene = new QGraphicsScene(0, 0, 1280, 371);
    ui->graphicsView->setScene(scene);
    background->setFileName(":/animation/res/test.gif");
    ui->label->setMovie(background);
    background->start();
    ui->graphicsView->show();
    moveTimer = new QTimer;
    Music = new QMediaPlayer;
    don = new QMediaPlayer;
    ka = new QMediaPlayer;
    Good = QPixmap(":/judge/res/judgement.png").copy(2, 5, 44, 25).scaled(101, 61, Qt::KeepAspectRatio);
    Ok = QPixmap(":/judge/res/judgement.png").copy(3, 34, 44, 25).scaled(101, 61, Qt::KeepAspectRatio);
    Bad = QPixmap(":/judge/res/judgement.png").copy(2, 65, 45, 25).scaled(101, 61, Qt::KeepAspectRatio);
    judge[0] = Good;
    judge[1] = Ok;
    judge[2] = Bad;
    ui->label_2->setPixmap(judge[2]);
}

GameWindow::~GameWindow()
{
    delete background;
    delete ui;
    delete scene;
    delete moveTimer;
    delete Music;
    delete don;
    delete ka;
}
