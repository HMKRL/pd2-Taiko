#include "keyconf.h"
#include "ui_keyconf.h"

keyConf::keyConf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyConf)
{
    ui->setupUi(this);
}

keyConf::~keyConf()
{
    delete ui;
}

void keyConf::keyPressEvent(QKeyEvent *event)
{
    this->close();
    this->setResult(event->key());
}
