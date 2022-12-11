#include "franklin.h"
#include "enemy.h"


Franklin::Franklin(int boardData[10][10], Enemy *enemy1, Enemy *enemy2,Enemy* enemy3,
                   QGraphicsScene *mainscene, door *door1, power_pellets *p1,
                   power_pellets *p2, Bullets *b1, Bullets *b2, Bullets *b3,
                   Bullets *b4, Widgets *time) {
  QPixmap franklin("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin.png");
  franklin = franklin.scaledToWidth(50);
  franklin = franklin.scaledToHeight(50);
  setPixmap(franklin);
  lives = 3;
  row = 5;
  column = 5;
  direction=1;
  this->scene = mainscene;
  setPos(50 + column * 50, 50 + row * 50);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      boarder[i][j] = boardData[i][j];

  Enemy1 = enemy1;
  Enemy2 = enemy2;
  powerful = false;
  door2 = door1;
  bul1 = b1;
  text1 = time;
  power1 = p1;
  power2 = p2;
  timer1.connect(&timer1, SIGNAL(timeout()), this, SLOT(pelletTime()));
  powerTimer.connect(&powerTimer, SIGNAL(timeout()), this, SLOT(Normal()));
}

int Franklin::getRow() { return row; }
int Franklin::getCol() { return column; }
void Franklin::setDirection(int d){
    direction=d;
    QTransform transform;
    if (d==-1){
        transform.scale(-1,1);
        transform.translate(-50,0);
    }
    setTransform(transform);
}
void Franklin::keyPressEvent(QKeyEvent *event) {

  if (event->key() == Qt::Key_Up && boarder[row - 1][column] == 2) {
    row--;

  } else if (event->key() == Qt::Key_Down && boarder[row + 1][column] == 2) {
    row++;

  } else if (event->key() == Qt::Key_Right && boarder[row][column + 1] == 2) {
    column++;
    setDirection(1);

  } else if (event->key() == Qt::Key_Left && boarder[row][column - 1] == 2) {
    column--;
    setDirection(-1);
  }
  setPos(50 + column * 50, 50 + row * 50);

  QList<QGraphicsItem *> value = collidingItems();
  int bulletCount = 4;
  for (int i = 0; i < value.size(); i++) {
    if (typeid(*value[i]) == typeid(Bullets)) {
      scene->removeItem(value[i]);
      bulletCount--;
      if (bulletCount == 0) {
        Enemy1->~Enemy();
        Enemy2->~Enemy();
      }
      setGun();
      QTimer gunTimer;
      gunTimer.singleShot(500, this, SLOT(setFranklin()));

      double d1, d2;
      int enemyCount = 2;
      d1 = qSqrt((qPow((Enemy1->getRow() - row), 2) +
                  qPow((Enemy1->getColumn() - column), 2)));
      d2 = qSqrt((qPow((Enemy2->getRow() - row), 2) +
                  qPow((Enemy2->getColumn() - column), 2)));
      if (d2 >= d1) {
        Enemy1->setLives((Enemy1->getLivesE()) - 1);
        if (Enemy1->getLivesE() == 0) {
          Enemy1->~Enemy();
          enemyCount--;
        }
      } else {
        Enemy2->setLives((Enemy2->getLivesE()) - 1);
        if (Enemy2->getLivesE() == 0) {
          Enemy2->~Enemy();
          enemyCount--;
        }
      }
    }
  }
  if (Enemy1->getLivesE() == 0 && Enemy2->getLivesE() == 0 && lives != 0) {
    emit winner();
  }

  QList<QGraphicsItem *> values = collidingItems();
  for (int i = 0; i < values.size(); i++) {
    if (typeid(*values[i]) == typeid(power_pellets)) {

      scene->removeItem(values[i]);
      timer1.start(1000);
      sethulk();
      powerTimer.start(5000);
    }

    if ((typeid(*values[i]) == typeid(Enemy)) && (powerful == false)) {
      lives--;
      emit decrease_health();

      if (lives == 0) {

        emit loser();
      }
    }
  }
}

int Franklin::getLivesF() { return lives; }
void Franklin::sethulk() {
  powerful = true;
  QPixmap hulk("/Users/markemad/Documents/Fall 2022/CS 2/gta/hulk.png");
  hulk = hulk.scaledToWidth(50);
  hulk = hulk.scaledToHeight(50);
  this->setPixmap(hulk);
}
void Franklin::setFranklin() {
  QPixmap franklin1(
      "/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin.png");
  franklin1 = franklin1.scaledToWidth(50);
  franklin1 = franklin1.scaledToHeight(50);
  this->setPixmap(franklin1);
}
bool Franklin::win() {
  // will comment this out
  qDebug() << "here \n";
  door door1;

  flag = true;
  this->scene->addItem(door2);
  this->door2->setposition(2, 2);
  return true;
}
void Franklin::lose() {
  QPixmap gameOver(
      "/Users/markemad/Documents/Fall 2022/CS 2/gta/Game_Over.jpeg");
  gameOver = gameOver.scaledToWidth(600);
  gameOver = gameOver.scaledToHeight(500);
  setPos(50 + 0 * 50, 50 + 0 * 50);
  this->scene->removeItem(bul1);
  this->setFlag(QGraphicsPixmapItem::ItemIsFocusable, false);
  this->setFocus();
  setDirection(1);
  setPixmap(gameOver);
  if (lives==0){

  }
}
void Franklin::Normal() {
  powerful = false;
  setFranklin();
  timer1.stop();
  powerTimer.stop();
}
void Franklin::setGun() {
  QPixmap franklin3(
      "/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin3.png");
  franklin3 = franklin3.scaledToWidth(50);
  franklin3 = franklin3.scaledToHeight(50);
  setPixmap(franklin3);
}
void Franklin::collision() {
  QList<QGraphicsItem *> values = collidingItems();
  for (int i = 0; i < values.size(); i++) {
    if (typeid(*values[i]) == typeid(door)) {
      this->scene->removeItem(door2);
      QPixmap youWin(
          "/Users/markemad/Documents/Fall 2022/CS 2/gta/you_win2.png");
      youWin = youWin.scaledToHeight(500);
      youWin = youWin.scaledToWidth(600);
      setPos(50 + 0 * 50, 50 + 0 * 50);
      this->setFlag(QGraphicsPixmapItem::ItemIsFocusable, false);
      this->setFocus();
      setDirection(1);
      setPixmap(youWin);
    }
  }
}
void Franklin::pelletTime() {
  text1->setPlainText("Time Left: " + QString::number((powerTimer.remainingTime() / 1000)) + "s");
}
bool Franklin::getPowerful(){
    return powerful;
}
void Franklin::setlives(int life){
    lives=life;
}
