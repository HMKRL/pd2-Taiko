#ifndef MAPSELECT_H
#define MAPSELECT_H

#include <QDialog>

namespace Ui {
class mapSelect;
}

class mapSelect : public QDialog
{
    Q_OBJECT

public:
    explicit mapSelect(QWidget *parent = 0);
    ~mapSelect();

private:
    Ui::mapSelect *ui;
};

#endif // MAPSELECT_H
