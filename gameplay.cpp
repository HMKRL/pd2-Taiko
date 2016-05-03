#include "gameplay.h"
#include "ui_gameplay.h"

gamePlay::gamePlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gamePlay)
{
    ui->setupUi(this);
    background = new QMovie;
    background->setFileName(":/animation/res/hatsune.gif");
    ui->label->setMovie(background);
    background->start();
}

gamePlay::~gamePlay()
{
    delete ui;
}

void gamePlay::on_pushButton_clicked()
{
    emit closed();
}
