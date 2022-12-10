//#include "game.h"

//game::game(Franklin* frank,Enemy* enemy1, Enemy* enemy2, QGraphicsScene * mainscene,door *door1,
//           power_pellets* p1, power_pellets* p2,Bullets* b1,Bullets* b2,Bullets* b3, Bullets* b4, Widgets* time)
//{
//    this->scene=mainscene;
//    row=5;
//    column=5;
//    Enemy1=enemy1;
//    Enemy2=enemy2;
//    powerful=false;
//    door2=door1;
//    bul1=b1;
//    timeLeft=time;
//    franklin=frank;
//    flag1=false;
//    flag2=false;
//    flag3=false;

//}
//void game::collTimer(){
//    QTimer* time1=new QTimer;
//    QObject::connect(time1,SIGNAL(timeout()),this,SLOT(checkCollision()));
//    time1->start(125);
//}
//void game::checkCollision(){

//    QList<QGraphicsItem*> value = collidingItems();
//    int bulletCount=4;
//    for (int i = 0; i < value.size(); i++)
//    {
//        if (typeid(*value[i]) == typeid(Bullets)){
//            scene->removeItem(value[i]);
//            bulletCount--;
//            if (bulletCount==0){
//                Enemy1->~Enemy();
//                Enemy2->~Enemy();
//            }
//            setGun();
//            QTimer gunTimer;
//            gunTimer.singleShot(500,this,SLOT(setFranklin()));
//    //             QPixmap franklin3("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin3.png");
//    //              franklin3 = franklin3.scaledToWidth(50);
//    //              franklin3 = franklin3.scaledToHeight(50);
//    //              setPixmap(franklin3);

//            double d1, d2;
//            int enemyCount=2;
//                        d1=qSqrt((qPow((Enemy1->getRow()-row),2)+qPow((Enemy1->getColumn()-column),2)));
//                        d2=qSqrt((qPow((Enemy2->getRow()-row),2)+qPow((Enemy2->getColumn()-column),2)));
//                        if (d2>=d1){
//                            Enemy1->setLives((Enemy1->getLivesE())-1);
//                            if (Enemy1->getLivesE()==0){
//                                Enemy1->~Enemy();
//                                enemyCount--;
//                            }
//                        }
//                        else {
//                            Enemy2->setLives((Enemy2->getLivesE())-1);
//                            if (Enemy2->getLivesE()==0){
//                                Enemy2->~Enemy();
//                                enemyCount--;
//                            }
//                        }


//        }}
//         if (Enemy1->getLivesE()==0 && Enemy2->getLivesE()==0 && franklin->getLivesF()!=0){
//            //QGraphicsScene scene;
//    //               door door1(boarder,5,3);
//    //              scene()->addItem(&door1);

//    //              QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
//    //              door = door.scaledToWidth(50);
//    //              door = door.scaledToHeight(50);
//    //              setPixmap(door);
//    //             // setPos(50 + 5 * 50, 50 + 5 * 50);
//    //              QPixmap youWin("/Users/markemad/Documents/Fall 2022/CS 2/gta/you_win.jpeg");
//    //              youWin=youWin.scaledToHeight(300);
//    //              youWin=youWin.scaledToWidth(300);
//    //              setPixmap(youWin);
//             flag1=true;
////             emit winner();
//             }

//    QList<QGraphicsItem*> values = collidingItems();
//    for (int i = 0; i < values.size(); i++)
//    {
//       if (typeid(*values[i]) == typeid(power_pellets))
//       {

//    //            int t=10;

//    //            if(t>=0){
//    //                 QTimer *timer2 = new QTimer();
//    //            timer2->start(10000);
//    //            connect(timer2,SIGNAL(timeout()),this,SLOT(decrease_t(t)));
//    //            emit decrease_time();
//    //       }

//                 scene->removeItem(values[i]);
//                 QTimer* countDown;
//                 timer1.start();
//    //                  int x=timer1.remainingTime()/1000;
//    //                  timeLeft->setTime(x);
//    //                  this->scene->addItem(timeLeft);
//                 QObject::connect(&timer1,SIGNAL(timeout()),this,SLOT(pelletTime()));
//                 sethulk();
//                 countDown->singleShot(5000,this,SLOT(Normal()));
//    //                  connect(timer2,SIGNAL(timeout()),this,SLOT(sethulk()));
//    //                    timer2->stop();


//    }

//       if ((typeid(*values[i]) == typeid(Enemy))&& (powerful==false))
//       {
//           franklin->setlives(franklin->getLivesF()-1);
//           emit decrease_health();
//          // setPos(50 + column * 50, 50 + row * 50);
//           if (franklin->getLivesF()==0){
//    //                        QPixmap gameOver("/Users/markemad/Documents/Fall 2022/CS 2/gta/game_over.png");
//    //                        gameOver=gameOver.scaledToHeight(300);
//    //                        gameOver=gameOver.scaledToWidth(300);
//    //                        setPixmap(gameOver);
//               flag2=true;
////               emit loser();


//                   }}
//                       //this->setPos(50 + column * 50, 50 + row * 50);
//                      // Enemy1->setPos()
//                      // Franklin(boarder,lives,Enemy1,Enemy2);
//                     //  Enemy(boarder,2,7);
//                      // Enemy(boarder,7,7);
//                       }

//       /*else*/ /*if (typeid(*values[i]) == typeid(power_pellets)){
//           timer2->start(1);
//           scene()->removeItem(values[i]);
//           connect(timer2,SIGNAL(timeout()),this,SLOT(sethulk()));
//    //            QPixmap hulk("/Users/markemad/Documents/Fall 2022/CS 2/gta/hulk.png");
//    //             hulk = hulk.scaledToWidth(50);
//    //             hulk = hulk.scaledToHeight(50);
//    //             setPixmap(hulk);
//        }}}*/
//}
//void game::flagCheck(){
//    if (flag1==true)
//        emit winner();
//    if (flag2==true)
//        emit loser();
//}

//    void game::sethulk(){
//       powerful=true;
//       QPixmap hulk("/Users/markemad/Documents/Fall 2022/CS 2/gta/hulk.png");
//       hulk = hulk.scaledToWidth(50);
//       hulk = hulk.scaledToHeight(50);
//       this->setPixmap(hulk);
//    }
//    void game::setFranklin(){
//    QPixmap franklin1("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin.png");
//    franklin1 = franklin1.scaledToWidth(50);
//    franklin1 = franklin1.scaledToHeight(50);
//    this->setPixmap(franklin1);
//    }
//    bool game::win(){
//    // will comment this out
//    qDebug()<<"here \n";
//    door door1;

//          flag=true;
//          this->scene->addItem(door2);
//          this->door2->setposition(2,2);
//         // scene()->addItem(&door1);
//    //            door1.setPixmapcheck(
//    //            QPixmap door("/Users/markemad/Documents/Fall 2022/CS 2/gta/SciFi_Door_Pixel.png");
//    //             door = door.scaledToWidth(50);
//    //             door = door.scaledToHeight(50);
//    //             setPixmap(door);
//    //             scene()->addItem(&door);
//    //            // setPos(50 + 5 * 50, 50 + 5 * 50);

//          //door1.setposition(2,2);
//    //             QList<QGraphicsItem*> values = collidingItems();
//    //             for (int i = 0; i < values.size(); i++){
//    //                 if(typeid(*values[i]) == typeid(door)){
//    //                     QPixmap youWin("/Users/markemad/Documents/Fall 2022/CS 2/gta/you_win.jpeg");
//    //                     youWin=youWin.scaledToHeight(300);
//    //                     youWin=youWin.scaledToWidth(300);
//    //                     this->setFlag(QGraphicsPixmapItem::ItemIsFocusable,false);
//    //                     this->setFocus();
//    //                     setPixmap(youWin);
//    //                 }
//    //             }
//           return true;
//    }
//    void game:: lose()
//    {
//    QPixmap gameOver("/Users/markemad/Documents/Fall 2022/CS 2/gta/Game_Over.jpeg");
//    gameOver = gameOver.scaledToWidth(600);
//    gameOver = gameOver.scaledToHeight(500);
//    setPos(50 + 0 * 50, 50 + 0 * 50);
//    this->scene->removeItem(bul1);
//    this->setFlag(QGraphicsPixmapItem::ItemIsFocusable,false);
//    this->setFocus();
//    setPixmap(gameOver);


//    // gameOver gameover;
//    //this->scene->addItem(gameover);

//    }
//    void game::Normal(){
//    powerful=false;
//    setFranklin();
//    }
//    void game::setGun(){
//    QPixmap franklin3("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin3.png");
//    franklin3 = franklin3.scaledToWidth(50);
//    franklin3 = franklin3.scaledToHeight(50);
//    setPixmap(franklin3);
//    }
//    void game::collision(){
//    QList<QGraphicsItem*> values = collidingItems();
//    for (int i = 0; i < values.size(); i++){
//       if(typeid(*values[i]) == typeid(door)){
//           this->scene->removeItem(door2);
//           QPixmap youWin("/Users/markemad/Documents/Fall 2022/CS 2/gta/you_win2.png");
//           youWin=youWin.scaledToHeight(500);
//           youWin=youWin.scaledToWidth(600);
//           setPos(50 + 0 * 50, 50 + 0 * 50);
//           this->setFlag(QGraphicsPixmapItem::ItemIsFocusable,false);
//           this->setFocus();
//           setPixmap(youWin);
//       }
//    }
//}

