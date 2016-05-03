#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>
#include <QMovie>

namespace Ui {
class gamePlay;
}

class gamePlay : public QWidget
{
    Q_OBJECT

public:
    explicit gamePlay(QWidget *parent = 0);
    ~gamePlay();

signals:
    void closed();

private slots:
    void on_pushButton_clicked();

private:
    Ui::gamePlay *ui;
    QMovie* background;
};

#endif // GAMEPLAY_H
