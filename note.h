#ifndef NOTE_H
#define NOTE_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Note : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Note(int Type, int T);

public slots:
    void move();
    void setStartTime(int T);
    int getStartTime();
    void setNotePixmap();
    int getType();

signals:
    void noteDestroyed();

private:
    int startTime;
    int type;

};

#endif // NOTE_H
