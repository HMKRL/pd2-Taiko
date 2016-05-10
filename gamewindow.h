#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QDialog>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

signals:
    void finished();

private:
    Ui::GameWindow *ui;
    QMovie* background;

};

#endif // GAMEWINDOW_H
