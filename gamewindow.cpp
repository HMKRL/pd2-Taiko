#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QDebug>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    background(new QMovie)
{
    ui->setupUi(this);
    background->setFileName(":/animation/res/test.gif");
    ui->label->setMovie(background);
    background->start();
}

GameWindow::~GameWindow()
{
    delete background;
    delete ui;
}
