#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QDialog>
#include <QString>
#include <QFileDialog>
#include <QDir>
#include <QSettings>
#include <QAbstractButton>

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

private:
    Ui::optionsDialog *ui;
    QString gameDir;
    QString settingsFilename;
    QSettings* settings;
};

#endif // OPTIONSDIALOG_H
