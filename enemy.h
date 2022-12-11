#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include <QApplication>
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QDebug>
#include <QStandardItemModel>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <cmath>
#include <stack>
#include <set>
#include <QTimer>
#include <float.h>

 typedef std::pair<int, int> pair1;
 typedef std::pair<int, std::pair<int,int>> pair2;

class Franklin;
struct node{
    int parentRow, parentColumn;
    double f, g, h; //f=g+h
};

class Enemy:public QObject, public QGraphicsPixmapItem
{   Q_OBJECT;
    private:
    int liveE;
    int rowE;
    int columnE;
    int data [10][10];
    std::stack<pair1> finalPath;
    int drow1;
    int dcol1;
    pair1 s;
    pair1 d;
    Franklin* franklin;
    QTimer collisionTimer;
public:
   Enemy(int boardData[10][10], int r, int c);
   void setFraklin(Franklin* frank);
   int getRow();
   int getColumn();
   int getposE();
   int getposE(int row, int col);
   void setLives(int livesE);
   int getLivesE();
   bool isValid(int row, int column);
   bool isDest(int row, int column, pair1 d);
   bool isUnblocked(int graph[][10],int row,int column);
   double calculateH(int row,int column,pair1 d);
   void Path(node nodeArray[][10],pair1 d);
   void search(int graph[][10],pair1 s, pair1 d);
   void setdRow(int drow);
   void setdCol(int dcol);
public slots:
   void enemyMove();
   void checkCollision();
};

#endif // ENEMY_H
