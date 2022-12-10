#include "power_pellets.h"

power_pellets::power_pellets(int border[10][10], int r, int c)
{
    // Set Image
        QPixmap power("/Users/markemad/Documents/Fall 2022/CS 2/gta/power.png");
        power = power.scaledToWidth(40);
        power = power.scaledToHeight(40);
        setPixmap(power);
    row=r;
    column=c;
        // Set Position
        setPos(50 + row * 50, 50 + column * 50);
        //ne3mel timer 3ashan yezhar b3d wa2t mo3ayan
}
