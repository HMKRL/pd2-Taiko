#ifndef MAPSELECT_H
#define MAPSELECT_H

#include <QDialog>
#include <QAbstractButton>
#include <QFile>
#include <QSettings>
#include <QString>

namespace Ui {
class mapSelect;
}

class mapSelect : public QDialog
{
    Q_OBJECT

public:
    explicit mapSelect(QWidget *parent = 0);
    ~mapSelect();
    QString getSelectedMap();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::mapSelect *ui;
    QSettings* settings;
};

#endif // MAPSELECT_H
