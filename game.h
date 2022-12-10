//#ifndef GAME_H
//#define GAME_H
//#include <QMainWindow>
//#include <QGraphicsPixmapItem>
//#include <QDir>
//#include <QDebug>
//#include <QStandardItemModel>
//#include <QGraphicsPixmapItem>
//#include <QGraphicsScene>
//#include<QGraphicsTextItem>
//#include <QKeyEvent>
//#include <QList>
//#include <QTimer>
//#include "enemy.h"
//#include "door.h"
//#include "power_pellets.h"
//#include "bullets.h"
//#include "widgets.h"
//#include <stack>
//#include "bullets.h"
//#include "power_pellets.h"
//#include <QTimer>
//#include <QGraphicsTextItem>
//#include "franklin.h"

//class game:public QObject, public QGraphicsPixmapItem
//{
//    QGraphicsScene * scene;
//    Enemy* Enemy1,*Enemy2;
//    bool powerful;
//    int row, column;
//    bool flag=false;
//    door* door2;
//    power_pellets* power1,*power2;
//    Bullets*bul1,*bul2,*bul3,*bul4;
//    Widgets* timeLeft;
//    QTimer timer1;
//    QGraphicsTextItem* text1;
//    Franklin* franklin;
//    bool flag1,flag2,flag3;

//public:
//    game(Franklin* frank,Enemy* enemy1, Enemy* enemy2, QGraphicsScene * mainscene,door *door1,
//         power_pellets* p1, power_pellets* p2,Bullets* b1,Bullets* b2,Bullets* b3, Bullets* b4, Widgets* time);
//    void collTimer();
//    void flagCheck();

//public slots:
//     void setFranklin();
//     void sethulk();
//     void Normal();
//     bool win();
//     void lose();
//     void setGun();
//     void collision();
//     void checkCollision();
//signals:
//     void winner();
//     void loser();
//     void decrease_health();
//};

//#endif // GAME_H
