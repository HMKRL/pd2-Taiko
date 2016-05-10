#ifndef KEYCONF_H
#define KEYCONF_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class keyConf;
}

class keyConf : public QDialog
{
    Q_OBJECT

public:
    explicit keyConf(QWidget *parent = 0);
    ~keyConf();

public slots:
    void keyPressEvent(QKeyEvent* event);

private:
    Ui::keyConf *ui;
};

#endif // KEYCONF_H
