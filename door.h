#ifndef DOOR_H
#define DOOR_H
#include <QObject>

#include <QGraphicsPixmapItem>
class door: public QObject, public QGraphicsPixmapItem
{
private:
    int row2;
    int column2;
    int data[10][10];

public:
    door();
    void setposition(int r, int c);
};

#endif // DOOR_H
