#include "basicrequire.h"
#include "ui_basicrequire.h"

BasicRequire::BasicRequire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BasicRequire)
{
    ui->setupUi(this);
}

BasicRequire::~BasicRequire()
{
    delete ui;
}
