#include "bullets.h"

Bullets::Bullets(int border[10][10], int r, int c)
{
    // Set Image
    QPixmap bullet("/Users/markemad/Documents/Fall 2022/CS 2/gta/bullet4.png");
    bullet = bullet.scaledToWidth(40);
    bullet = bullet.scaledToHeight(40);
    setPixmap(bullet);
row=r;
column=c;
    // Set Position
    setPos(50 + column * 50, 50 + row * 50);
}
