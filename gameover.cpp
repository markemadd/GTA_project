#include "gameover.h"

gameOver::gameOver()
{
    QPixmap gameOver("/Users/markemad/Documents/Fall 2022/CS 2/gta/Game_Over.jpeg");
    gameOver = gameOver.scaledToWidth(50);
    gameOver = gameOver.scaledToHeight(50);
    setPixmap(gameOver);
    setPos(50 + 2 * 50, 50 + 2 * 50);
}
