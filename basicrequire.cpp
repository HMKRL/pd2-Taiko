#include "basicrequire.h"
#include "ui_basicrequire.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

BasicRequire::BasicRequire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BasicRequire),
    moveTimer(new QTimer),
    time_elapsed(0),
    FPS(1)
{
    ui->setupUi(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(timeElapsed()));
    srand(time(NULL));
}

BasicRequire::~BasicRequire()
{
    delete ui;
    delete moveTimer;
    delete scene;
    delete view;
}

void BasicRequire::timeElapsed()
{
    time_elapsed += FPS;
    if(time_elapsed <= 30000) {
        ui->lcdNumber->display(30 - time_elapsed / 1000);
        if(!map.isEmpty()) {
            if(time_elapsed >= map.front()->getStartTime()) {
                scene->addItem(map.front());
                connect(moveTimer, SIGNAL(timeout()), map.front(), SLOT(move()));
                map.pop_front();
            }
        }
    }
    else {
        moveTimer->stop();
    }
}

void BasicRequire::gameStart()
{
    this->show();
    scene = new QGraphicsScene(0, 0, 1280, 720);
    view = new QGraphicsView(ui->widget);
    view->setScene(scene);
    view->show();
    addNote();
    moveTimer->start(FPS);
}

void BasicRequire::addNote()
{
    /*N = new Note;
    N->setPixmap(QPixmap(":/notes/res/small_blue.png"));
    N->setPos(1280, 218);
    */
    //N->setPos(373, 218);
    for(int i = 0;i < 120;++i) {
        N = new Note(rand() % 4 , 500 * i);
        map.push_back(N);
    }
}

void BasicRequire::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_J) {
    }
}
