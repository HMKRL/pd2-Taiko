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
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(timeElapsed()));

    Music = new QMediaPlayer;
    don = new QMediaPlayer;
    ka = new QMediaPlayer;
    don->setMedia(QUrl("qrc:/sounds/res/don.wav"));
    ka->setMedia(QUrl("qrc:/sounds/res/ka.wav"));

    judge[0] = QPixmap(":/judge/res/judgement.png").copy(2, 5, 44, 25).scaled(101, 61, Qt::KeepAspectRatio);
    judge[1] = QPixmap(":/judge/res/judgement.png").copy(3, 34, 44, 25).scaled(101, 61, Qt::KeepAspectRatio);
    judge[2] = QPixmap(":/judge/res/judgement.png").copy(2, 65, 45, 25).scaled(101, 61, Qt::KeepAspectRatio);
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

void GameWindow::gameStart()
{
    this->show();
    Music->setMedia(QUrl::fromLocalFile(Beatmap + "/music.wav"));
    Music->play();
    moveTimer->start(1000);
}

void GameWindow::setBeatmap(QString name)
{
    Beatmap = name;
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_K) {
        ui->label_2->setPixmap(judge[0]);
        moveTimer->singleShot(200, ui->label_2, SLOT(clear()));
    }
    else if(event->key() == Qt::Key_J){
        ui->label_2->setPixmap(judge[1]);
        moveTimer->singleShot(200, ui->label_2, SLOT(clear()));
    }
    else {
        ui->label_2->setPixmap(judge[2]);
        moveTimer->singleShot(200, ui->label_2, SLOT(clear()));
    }
}

void GameWindow::timeElapsed()
{

}
