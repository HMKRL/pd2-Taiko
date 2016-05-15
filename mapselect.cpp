#include "mapselect.h"
#include "ui_mapselect.h"
#include <QListWidgetItem>
#include <QDebug>
#include <QDir>
#include <QString>

mapSelect::mapSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mapSelect)
{
    ui->setupUi(this);
    ui->listWidget->setIconSize(QSize(80, 80));
    ui->listWidget->setFont(QFont(ui->listWidget->font()));

    settings = new QSettings(QDir::currentPath() + "/TaikoConfig.ini", QSettings::IniFormat);
    QString mapsdir = settings->value("GameDir").toString();
    QFile maps(mapsdir + "/maps.txt");
    maps.open(QIODevice::ReadOnly);
    QString s;
    while(!maps.atEnd()) {
        s = maps.readLine();
        s.truncate(s.length() - 1);
        QListWidgetItem* t = new QListWidgetItem(QIcon(mapsdir + "/" + s + "/icon.png"), s);
        ui->listWidget->addItem(t);
    }
    ui->listWidget->setCurrentRow(0);
}

mapSelect::~mapSelect()
{
    delete ui;
}

QString mapSelect::getSelectedMap()
{
    return ui->listWidget->currentItem()->text();
}

void mapSelect::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Ok) {

    }
}
