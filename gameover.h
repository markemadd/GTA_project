#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QObject>
#include <QGraphicsPixmapItem>

class gameOver:public QObject, public QGraphicsPixmapItem
{
public:
    gameOver();
};

#endif // GAMEOVER_H
