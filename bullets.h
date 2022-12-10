#ifndef BULLETS_H
#define BULLETS_H


#include <QGraphicsPixmapItem>

class Bullets : public QGraphicsPixmapItem
{
private:
    int row;
    int column;
    int data[10][10];
public:
    Bullets(int border[10][10],int row, int column);

};

#endif // BULLETS_H
