#ifndef FRANKLIN_H
#define FRANKLIN_H

#include <QDir>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QList>
#include <QStandardItemModel>
#include <QTimer>
#include <QStack>
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include "bullets.h"
#include "door.h"
#include "power_pellets.h"
#include "widgets.h"


class Enemy;
class Franklin : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT;

private:
  int lives;
  int row;
  int column;
  int boarder[10][10];
  Enemy *Enemy1, *Enemy2;
  bool powerful;
  QGraphicsScene *scene;
  int direction;

public:
  int getpos();
  int getpos(int row, int col);
  Franklin(int boardData[10][10],Enemy* enemy1, Enemy* enemy2,Enemy* enemy3, QGraphicsScene * mainscene,door *door1,
           power_pellets* p1, power_pellets* p2,Bullets* b1,Bullets* b2,Bullets* b3, Bullets* b4, Widgets* time);
  int getLivesF();
  void setlives(int life);
  void update_timer();
  int getRow();
  int getCol();
  bool flag = false;
  QTimer timer1;
  QTimer powerTimer;
  QGraphicsTextItem *text1;
  door *door2;
  power_pellets *power1, *power2;
  Bullets *bul1, *bul2, *bul3, *bul4;
  Widgets *timeLeft;
  bool getPowerful();
  void setDirection(int d);

public slots:
  void keyPressEvent(QKeyEvent *event);
  void setFranklin();
  void sethulk();
  void Normal();
  bool win();
  void lose();
  void setGun();
  void collision();
  void pelletTime();
signals:
  void winner();
  void loser();
  void decrease_health();
  void decrease_time();
};

#endif // FRANKLIN_H
