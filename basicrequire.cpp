#include "basicrequire.h"
#include "ui_basicrequire.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

BasicRequire::BasicRequire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BasicRequire),
    moveTimer(new QTimer),
    time_elapsed(0),
    FPS(2),
    score(0)
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
        if(It != map.end()) {
            if(time_elapsed >= (*It)->getStartTime()) {
                scene->addItem(*It);
                connect(moveTimer, SIGNAL(timeout()), *It, SLOT(move()));
                connect(*It, SIGNAL(noteDestroyed()), this, SLOT(noteDeleted()));
                ++It;
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
    addNote();
    view->show();
    moveTimer->start(FPS);
}

void BasicRequire::addNote()
{
    //N->setPos(373, 218);
    for(int i = 0;i < 30;++i) {
        N = new Note(rand() % 4 , 500 * i);
        map.push_back(N);
    }
    It = map.begin();
    Cur = map.begin();
}

void BasicRequire::keyPressEvent(QKeyEvent *event)
{
    if(Cur == map.end()) return;
    if((*Cur)->x() < 450) {
        if(event->key() == Qt::Key_J || event->key() == Qt::Key_F) {
            if((*Cur)->getType() == 0 || (*Cur)->getType() == 2) {
                getPoint((*Cur)->x());
                delete *Cur;
                ++Cur;
            }
        }
        else if(event->key() == Qt::Key_D || event->key() == Qt::Key_K) {
            if((*Cur)->getType() == 1 || (*Cur)->getType() == 3) {
                getPoint((*Cur)->x());
                delete *Cur;
                ++Cur;
            }
        }
    }
}

void BasicRequire::noteDeleted()
{
    if(Cur != map.end()) ++Cur;
}

void BasicRequire::getPoint(int accurate)
{
    int dis = abs(accurate - 351);
    if(dis < 20) {
        qDebug() << "T1";
    }
    else if(dis < 40) {
        qDebug() << "T2";
    }
    else {
        qDebug() << "T3";
    }
}
