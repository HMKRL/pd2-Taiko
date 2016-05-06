#ifndef BASICREQUIRE_H
#define BASICREQUIRE_H

#include "note.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>

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
    void gameStart();
    void addNote();
    void keyPressEvent(QKeyEvent* event);
    void noteDeleted();
    void getPoint(int accurate);

private:
    Ui::BasicRequire *ui;
    QTimer* moveTimer;
    int time_elapsed;
    int FPS;
    QGraphicsScene* scene;
    QGraphicsView* view;
    Note* N;
    QVector<Note*> map;
    int score;
    QVector<Note*>::iterator It;
    QVector<Note*>::iterator Cur;
};

#endif // BASICREQUIRE_H
