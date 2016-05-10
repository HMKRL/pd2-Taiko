#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QtMultimedia/QMediaPlayer>
#include <QSound>
#include "gamewindow.h"
#include "basicrequire.h"
#include "optionsdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void keyPressEvent(QKeyEvent* k);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void moveSelection();
    void selected();
    void onGameFinished();

signals:
    void onIndexChanged(int);
    void playMoveSound();
    void playSelectSound();

private:
    Ui::MainWindow *ui;
    QMovie* currentSelect;
    QSound* indexMove;
    QSound* selectedSound;
    GameWindow* gameWindow;
    BasicRequire* basicWindow;
    int selectIndex;
    optionsDialog* OptionsDialog;
};

#endif // MAINWINDOW_H
