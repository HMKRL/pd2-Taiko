#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QMovie>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
        QMovie* background;

signals:
    void finished();

private:
    Ui::GameWindow *ui;

};

#endif // GAMEWINDOW_H
