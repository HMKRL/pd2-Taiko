#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "note.h"
#include <QMainWindow>
#include <QMovie>
#include <QDialog>
#include <QGraphicsScene>
#include <QTimer>
#include <QtMultimedia/QMediaPlayer>
#include <QPixmap>

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
    QGraphicsScene* scene;
    Note* N;
    QTimer* moveTimer;
    QVector<Note*> map;
    QVector<Note*>::iterator It;
    QVector<Note*>::iterator Cur;
    QMediaPlayer* Music;
    QMediaPlayer* don;
    QMediaPlayer* ka;
    int time_elapsed;
    int score;
    int FPS;
    QPixmap Good;
    QPixmap Ok;
    QPixmap Bad;
    QPixmap judge[3];

};

#endif // GAMEWINDOW_H
