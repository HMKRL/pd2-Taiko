#ifndef BASICREQUIRE_H
#define BASICREQUIRE_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class BasicRequire;
}

class BasicRequire : public QMainWindow
{
    Q_OBJECT

public:
    explicit BasicRequire(QWidget *parent = 0);
    ~BasicRequire();

public slots:
    void timeElapsed();

private:
    Ui::BasicRequire *ui;
    QTimer* moveTimer;
    int time_elapsed;
    int FPS;
};

#endif // BASICREQUIRE_H
