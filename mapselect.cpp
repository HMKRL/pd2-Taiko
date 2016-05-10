#include "mapselect.h"
#include "ui_mapselect.h"
#include <QListWidgetItem>

mapSelect::mapSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mapSelect)
{
    ui->setupUi(this);
    ui->listWidget->addItem(new QListWidgetItem(QIcon("/home/hmkrl/Desktop/only_my_railgun/sliderb0.png"), "test"));
}

mapSelect::~mapSelect()
{
    delete ui;
}
