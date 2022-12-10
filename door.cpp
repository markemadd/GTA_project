#include "door.h"

door::door()
{
    QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
    door = door.scaledToWidth(50);
    door = door.scaledToHeight(50);
    setPixmap(door);
              // r=6;
               //c=6;

    // Set Position
   // setPos(50 + 2 * 50, 50 + 2 * 50);
     // setPos(50 + c * 50, 50 + r * 50);
}


void door::setposition(int r, int c)
{
    setPos(50 + c * 50, 50 + r * 50);
}

