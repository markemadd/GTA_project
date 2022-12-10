#include "franklin.h"
#include "bullets.h"
#include "enemy.h"
#include "power_pellets.h"
#include "widgets.h"
#include <QApplication>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QTimer>
#include <QDebug>
#include <QStandardItemModel>
#include <QKeyEvent>
#include <QBrush>
#include <QElapsedTimer>
#include "door.h"
#include "game.h"


slots void setDoor(bool flag1, QGraphicsScene* scene1){
    if (flag1==true){
        door door1;
        scene1->addItem(&door1);
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // QApplication board(argc,argv);
    QGraphicsView view;
    QGraphicsScene scene;
    view.setFixedSize(700, 800);
    view.setWindowTitle("GTA Game");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);
//	QString parentPath = "D:/Personal/qt/";
    QFile file("/Users/markemad/Documents/Fall 2022/CS 2/gta/Board1.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int border[10][10];
    QString temp;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            {
                stream >> temp;
                border[i][j] = temp.toInt();
            }
    QPixmap grassImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Grass_image.png");
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);
    QPixmap buildingimage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Building_image.png");
    buildingimage = buildingimage.scaledToWidth(500);
    buildingimage = buildingimage.scaledToHeight(50);
    QPixmap treeImage( "/Users/markemad/Documents/Fall 2022/CS 2/gta/Tree_image.png");
    treeImage = treeImage.scaledToWidth(100);
    treeImage = treeImage.scaledToHeight(53);
    QPixmap lampImage( "/Users/markemad/Documents/Fall 2022/CS 2/gta/Lamp_image.png");
    lampImage = lampImage.scaledToWidth(50);
    lampImage = lampImage.scaledToHeight(50);
    QPixmap roadImage("/Users/markemad/Documents/Fall 2022/CS 2/gta/Road.png");
    roadImage = roadImage.scaledToWidth(50);
    roadImage = roadImage.scaledToHeight(50);
    QPixmap  car( "/Users/markemad/Documents/Fall 2022/CS 2/gta/car2.png");
    car = car.scaledToWidth(50);
    car = car.scaledToHeight(50);
    QPixmap F_home("/Users/markemad/Documents/Fall 2022/CS 2/gta/Franklin_home.png");
    F_home = F_home.scaledToWidth(50);
    F_home = F_home.scaledToHeight(50);

    QGraphicsPixmapItem boardItems[10][10];
    QGraphicsPixmapItem newBoard[10][10];
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        // Set Image
        if (border[i][j]==4)
          newBoard[i][j].setPixmap(roadImage);
        else
          newBoard[i][j].setPixmap(grassImage);
        // Set Position
        newBoard[i][j].setPos(50 + j * 50, 50 + i * 50);

        // Add to the Scene
        scene.addItem(&newBoard[i][j]);
      }
    }
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
            {
                // Set Image
                if (border[i][j] == 4)
                    boardItems[i][j].setPixmap(car);
                else if(border[i][j]==5)
                    boardItems[i][j].setPixmap(grassImage);
                else if(border[i][j]== 1)
                    boardItems[i][j].setPixmap(buildingimage);
                else if(border[i][j]== 8)
                   boardItems[i][j].setPixmap(treeImage);
                else if(border[i][j]==3)
                    boardItems[i][j].setPixmap(lampImage);
                else if(border[i][j]== 2)
                    boardItems[i][j].setPixmap(roadImage);
                else if(border[i][j]==7)
                    boardItems[i][j].setPixmap(F_home);

                // Set Position
                boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

                // Add to the Scene
                scene.addItem(&boardItems[i][j]);

            }
//                Widgets *lives,*bullets;
//                lives = new Widgets("Lives: ", 3, 500, 0);
//                bullets = new Widgets("bullets left ", 4, 300, 0);
//                connect(Franklin, SIGNAL(timer()),lives,SLOT(timer));




                door door1;
                power_pellets power1(border,4,6);
                scene.addItem(&power1);
                power_pellets power2(border,7,2);
                scene.addItem(&power2);
                Bullets bullet1(border,1,1);
                scene.addItem(&bullet1);
                Bullets bullet2(border,1,8);
                scene.addItem(&bullet2);
                Bullets bullet3(border,8,1);
                scene.addItem(&bullet3);
                Bullets bullet4(border,8,8);
                scene.addItem(&bullet4);
                Widgets *lives,*time_left/*,*state*/;
                time_left=new Widgets("Time Left: ",5, 50, 20);
                scene.addItem(time_left);
                Enemy enemy1(border,7,2);
                scene.addItem(&enemy1);
                Enemy enemy2(border,7,7);
                scene.addItem(&enemy2);
                Franklin franklin(border, &enemy1, &enemy2,&scene,&door1,&power1,&power2,&bullet1,&bullet2,&bullet3,&bullet4,time_left);
                scene.addItem(&franklin);
                enemy1.setFraklin(&franklin);
                enemy2.setFraklin(&franklin);


               // game game1(&franklin,&enemy1,&enemy2,&scene,&door1,&power1,&power2,&bullet1,&bullet2,&bullet3,&bullet4,time_left);

//                enemy1.setdRow(franklin.getRow());
//                enemy1.setdCol(franklin.getCol());
//                enemy2.setdRow(franklin.getRow());
//                enemy2.setdCol(franklin.getCol());

                qDebug() << "here1";

               franklin.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
               franklin.setFocus();
               lives = new Widgets("Lives: ", 3, 400, 20);
//               state = new Widgets("state: ",1, 50,0);
//               time_left = new Widgets("Time Left: ",5, 50, 20);
               QObject::connect(&franklin, SIGNAL(decrease_health()),lives,SLOT(timers()));
               scene.addItem(lives);
               //QObject::connect(&franklin, SIGNAL(decrease_time()),time_left,SLOT(timers()));

//               scene.addItem(state);
               QObject::connect(&franklin,SIGNAL(winner()),&franklin,SLOT(win()));
               qDebug() << "here4";
               //timer to keep checking if flag changed from false to true
               QTimer* flagTimer=new QTimer;
               QObject::connect(flagTimer,SIGNAL(timeout()),&franklin,SLOT(collision()));
               flagTimer->start(10);

               QObject::connect(&franklin,SIGNAL(loser()),&franklin,SLOT(lose()));

               view.setScene(&scene);
               view.show();
               return a.exec();

}
