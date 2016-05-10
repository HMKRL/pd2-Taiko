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
