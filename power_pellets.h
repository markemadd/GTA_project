#ifndef POWER_PELLETS_H
#define POWER_PELLETS_H


#include <QGraphicsPixmapItem>
class power_pellets: public QGraphicsPixmapItem
{
private:
    int row;
    int column;
    int data[10][10];
public:
    power_pellets(int border[10][10],int row, int column);
};

#endif // POWER_PELLETS_H
