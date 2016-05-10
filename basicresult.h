#ifndef BASICRESULT_H
#define BASICRESULT_H

#include <QDialog>


namespace Ui {
class basicResult;
}

class basicResult : public QDialog
{
    Q_OBJECT

public:
    explicit basicResult(QWidget *parent = 0);
    ~basicResult();
    void showResult(int score);

private:
    Ui::basicResult *ui;
};

#endif // BASICRESULT_H
