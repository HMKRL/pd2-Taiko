#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QSettings>
#include <QAbstractButton>
#include "keyconf.h"

namespace Ui {
class optionsDialog;
}

class optionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit optionsDialog(QWidget *parent = 0);
    ~optionsDialog();
    void loadSettings();

private slots:
    void on_toolButton_clicked();

    void on_DelaySlider_valueChanged(int value);

    void on_Speedslider_valueChanged(int value);

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::optionsDialog *ui;
    QString gameDir;
    QString settingsFilename;
    QSettings* settings;
    keyConf* KeyConf;
    int KEY_CHAR;
};

#endif // OPTIONSDIALOG_H
