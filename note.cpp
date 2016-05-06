#include "note.h"

Note::Note(int Type, int T)
{
    type = Type;
    setStartTime(T);
    setNotePixmap();
}

void Note::move()
{
    if(x() > 300) {
        setPos(x() - 1, y());
    }
    else {
        emit noteDestroyed();
        delete this;
    }
}

void Note::setStartTime(int T)
{
    startTime = T + 1;
}

int Note::getStartTime()
{
    return startTime;
}

void Note::setNotePixmap()
{
    switch(type) {
    case 0:
        setPixmap(QPixmap(":/notes/res/small_red.png"));
        setPos(1280, 197);
        break;
    case 1:
        setPixmap(QPixmap(":/notes/res/small_blue.png"));
        setPos(1280, 197);
        break;
    case 2:
        setPixmap(QPixmap(":/notes/res/big_red.png"));
        setPos(1280, 197);
        break;
    case 3:
        setPixmap(QPixmap(":/notes/res/big_blue.png"));
        setPos(1280, 197);
        break;
    default:
        break;
    }
}

int Note::getType()
{
    return type;
}
