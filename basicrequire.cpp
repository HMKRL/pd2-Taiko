#include "basicrequire.h"
#include "ui_basicrequire.h"

BasicRequire::BasicRequire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BasicRequire),
    moveTimer(new QTimer),
    time_elapsed(0),
    FPS(1)
{
    ui->setupUi(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(timeElapsed()));
    moveTimer->start(FPS);
}

BasicRequire::~BasicRequire()
{
    delete ui;
    delete moveTimer;
}

void BasicRequire::timeElapsed()
{
    time_elapsed += FPS;
    if(time_elapsed <= 30000) {
        ui->lcdNumber->display(30 - time_elapsed / 1000);
    }
    else {
        moveTimer->stop();
    }
}
