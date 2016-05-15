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
#include <QKeyEvent>
#include <QString>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();
    void gameStart();
    void setBeatmap(QString name);

public slots:
    void keyPressEvent(QKeyEvent* event);
    void timeElapsed();

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
    QPixmap judge[3];
    QString Beatmap;
};

#endif // GAMEWINDOW_H
