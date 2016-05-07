#include "basicresult.h"
#include "ui_basicresult.h"

basicResult::basicResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basicResult)
{
    ui->setupUi(this);
}

basicResult::~basicResult()
{
    delete ui;
}

void basicResult::showResult(int score)
{
    this->show();
    ui->lcdNumber->display(score);
}
