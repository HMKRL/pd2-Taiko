#include "optionsdialog.h"
#include "ui_optionsdialog.h"
#include <QDebug>
#include <string>
using namespace std;

optionsDialog::optionsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optionsDialog)
{
    ui->setupUi(this);
    settingsFilename = QDir::currentPath() + "/TaikoConfig.ini";
    settings = new QSettings(settingsFilename, QSettings::IniFormat);
    KeyConf = new keyConf;
    loadSettings();
}

optionsDialog::~optionsDialog()
{
    delete ui;
    delete settings;
    delete KeyConf;
}

void optionsDialog::loadSettings()
{
    if(settings->value("Delay").toInt() == 0) {
        settings->setValue("Delay", 0);
    }
    if(settings->value("Speed").toInt() > 50 || settings->value("Speed").toInt() < 10) {
        settings->setValue("Speed", 10);
    }
    if(settings->value("GameDir").toString() == "") {
        settings->setValue("GameDir", "/home");
    }
    ui->label_4->setText(settings->value("Delay").toString());
    ui->DelaySlider->setValue(settings->value("Delay").toInt());

    ui->label_5->setText(settings->value("Speed").toString().insert(1, '.'));
    ui->Speedslider->setValue(settings->value("Speed").toInt());

    ui->lineEdit->setText(settings->value("GameDir").toString());
}

void optionsDialog::on_toolButton_clicked()
{
    gameDir = QFileDialog::getExistingDirectory(this,
                                                "Choose Game Dir...",
                                                "/home",
                                                QFileDialog::ShowDirsOnly);
    ui->lineEdit->setText(gameDir);
}

void optionsDialog::on_DelaySlider_valueChanged(int value)
{
    ui->label_4->setText(to_string(value).c_str());
}

void optionsDialog::on_Speedslider_valueChanged(int value)
{
    string temp = to_string(value);
    temp.insert(temp.begin() + 1, '.');
    ui->label_5->setText(temp.c_str());
}

void optionsDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(ui->buttonBox->standardButton(button) == QDialogButtonBox::Save) {
        settings->setValue("Delay", ui->DelaySlider->value());
        settings->setValue("Speed", ui->Speedslider->value());
        settings->setValue("GameDir", ui->lineEdit->text());
    }
    else if(ui->buttonBox->standardButton(button) == QDialogButtonBox::RestoreDefaults) {
        settings->setValue("Delay", 0);
        ui->label_4->setText("0");
        ui->DelaySlider->setValue(0);

        settings->setValue("Speed", 10);
        ui->label_5->setText("1.0");
        ui->Speedslider->setValue(10);

        settings->setValue("GameDir", "/home");
        ui->lineEdit->setText("/home");

        settings->setValue("leftka", Qt::Key_D);
        settings->setValue("leftdon", Qt::Key_F);
        settings->setValue("rightdon", Qt::Key_J);
        settings->setValue("rightka", Qt::Key_K);
    }
}

void optionsDialog::on_pushButton_clicked()
{
    KeyConf->show();
    settings->setValue("leftka", KeyConf->exec());
}

void optionsDialog::on_pushButton_2_clicked()
{
    KeyConf->show();
    settings->setValue("leftdon", KeyConf->exec());
}

void optionsDialog::on_pushButton_3_clicked()
{
    KeyConf->show();
    settings->setValue("rightdon", KeyConf->exec());
}

void optionsDialog::on_pushButton_4_clicked()
{
    KeyConf->show();
    settings->setValue("rightka", KeyConf->exec());
}
