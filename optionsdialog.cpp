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
    //default settings
    if(settings->value("Delay").toInt() == 0) {
        settings->setValue("Delay", 0);
    }
    if(settings->value("Speed").toInt() > 50 || settings->value("Speed").toInt() < 10) {
        settings->setValue("Speed", 10);
    }
    if(settings->value("GameDir").toString() == "") {
        settings->setValue("GameDir", "/home");
    }

    //default key config
    if(settings->value("leftdon").toInt() == 0) {
        settings->setValue("leftdon", 'D');
    }
    if(settings->value("leftka").toInt() == 0) {
        settings->setValue("leftka", 'F');
    }
    if(settings->value("rightdon").toInt() == 0) {
        settings->setValue("rightdon", 'J');
    }
    if(settings->value("rightka").toInt() == 0) {
        settings->setValue("rightka", 'K');
    }

    ui->label_4->setText(settings->value("Delay").toString());
    ui->DelaySlider->setValue(settings->value("Delay").toInt());

    ui->label_5->setText(settings->value("Speed").toString().insert(1, '.'));
    ui->Speedslider->setValue(settings->value("Speed").toInt());

    ui->pushButton->setText(QKeySequence(settings->value("leftka").toInt()).toString());

    ui->pushButton_2->setText(QKeySequence(settings->value("leftdon").toInt()).toString());

    ui->pushButton_3->setText(QKeySequence(settings->value("rightdon").toInt()).toString());

    ui->pushButton_4->setText(QKeySequence(settings->value("rightka").toInt()).toString());

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

        settings->setValue("leftka", 'D');
        ui->pushButton->setText(QString('D'));

        settings->setValue("leftdon", 'F');
        ui->pushButton_2->setText(QString('F'));

        settings->setValue("rightdon", 'J');
        ui->pushButton_3->setText(QString('J'));

        settings->setValue("rightka", 'K');
        ui->pushButton_4->setText(QString('K'));
    }
}

void optionsDialog::on_pushButton_clicked()
{
    KeyConf->show();
    KEY_CHAR = KeyConf->exec();
    settings->setValue("leftka", KEY_CHAR);
    ui->pushButton->setText(QKeySequence(KEY_CHAR).toString());
}

void optionsDialog::on_pushButton_2_clicked()
{
    KeyConf->show();
    KEY_CHAR = KeyConf->exec();
    settings->setValue("leftdon", KEY_CHAR);
    ui->pushButton_2->setText(QKeySequence(KEY_CHAR).toString());
}

void optionsDialog::on_pushButton_3_clicked()
{
    KeyConf->show();
    KEY_CHAR = KeyConf->exec();
    settings->setValue("rightdon", KEY_CHAR);
    ui->pushButton_3->setText(QKeySequence(KEY_CHAR).toString());
}

void optionsDialog::on_pushButton_4_clicked()
{
    KeyConf->show();
    KEY_CHAR = KeyConf->exec();
    settings->setValue("rightka", KEY_CHAR);
    ui->pushButton_4->setText(QKeySequence(KEY_CHAR).toString());
}
