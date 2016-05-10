#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentSelect(new QMovie),
    indexMove(new QSound(":/sounds/res/ka.wav")),
    selectedSound(new QSound(":/sounds/res/don.wav")),
    selectIndex(0)
{
    ui->setupUi(this);
    currentSelect->setFileName(":/animation/res/taikoSelect.gif");
    ui->label->setMovie(currentSelect);
    currentSelect->start();
    connect(this, SIGNAL(playMoveSound()), indexMove, SLOT(play()));
    connect(this, SIGNAL(playSelectSound()), selectedSound, SLOT(play()));
    setMouseTracking(true);
    centralWidget()->setMouseTracking(true);
    //connect(gameWindow, SIGNAL(finished()), this, SLOT(onGameFinished()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete currentSelect;
    delete indexMove;
    delete selectedSound;
}

void MainWindow::moveSelection()
{
    emit playMoveSound();
    ui->label->setGeometry(ui->label->x(), 295 + 75 * selectIndex, 50, 50);
}

void MainWindow::selected()
{
    emit playSelectSound();
    switch(selectIndex) {
    case 0:
        basicWindow = new BasicRequire;
        basicWindow->setGeometry(this->x(), this->y(), 1280, 720);
        basicWindow->show();
        basicWindow->gameStart();
        this->close();
        break;
    case 1:
        MapSelect = new mapSelect;
        MapSelect->show();
        //gameWindow = new GameWindow;
        //gameWindow->setGeometry(this->x(), this->y(), 1280, 720);
        //gameWindow->show();
        this->hide();

        break;
    case 2:
        OptionsDialog = new optionsDialog;
        OptionsDialog->show();
        this->setDisabled(true);
        OptionsDialog->exec();
        this->setDisabled(false);
        break;
    case 3:
        this->close();
        break;
    default:
        break;
    }
}

void MainWindow::onGameFinished()
{
    this->show();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    if(k->key() == Qt::Key_Up) {
        --selectIndex;
        if(selectIndex == -1) selectIndex = 3;
        moveSelection();
    }
    else if(k->key() == Qt::Key_Down) {
        ++selectIndex;
        if(selectIndex == 4) selectIndex = 0;
        moveSelection();
    }
    else if(k->key() == Qt::Key_Enter || k->key() == Qt::Key_Return) {
        selected();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug() << event->x() << event->y();
    int temp = selectIndex;
    if(event->x() <= 1050 && event->x() >= 720) {
        if(event->y() <= 290) selectIndex = 0;
        else if(event->y() <= 365) selectIndex = 0;
        else if(event->y() <= 435) selectIndex = 1;
        else if(event->y() <= 510) selectIndex = 2;
        else if(event->y() <= 585) selectIndex = 3;
    }
    if(temp != selectIndex) moveSelection();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->x() <= 1050 && event->x() >= 720 && event->y() >= 290 && event->y() <= 585) {
        if(event->button() == Qt::LeftButton) selected();
    }
}
