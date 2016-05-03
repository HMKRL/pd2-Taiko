#ifndef BASICREQUIRE_H
#define BASICREQUIRE_H

#include <QMainWindow>

namespace Ui {
class BasicRequire;
}

class BasicRequire : public QMainWindow
{
    Q_OBJECT

public:
    explicit BasicRequire(QWidget *parent = 0);
    ~BasicRequire();

private:
    Ui::BasicRequire *ui;
};

#endif // BASICREQUIRE_H
