#include "enemy.h"
#include "franklin.h"

Enemy::Enemy(int border[10][10], int r, int c) {
  QPixmap enemy("/Users/markemad/Documents/Fall 2022/CS 2/gta/Enemy.png");
  enemy = enemy.scaledToWidth(55);
  enemy = enemy.scaledToHeight(60);
  setPixmap(enemy);
  liveE = 2;
  rowE = r;
  columnE = c;
  setPos(50 + columnE * 50, 50 + rowE * 50);
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      data[i][j] = border[i][j];
  QTimer *timer = new QTimer;
  QObject::connect(timer, SIGNAL(timeout()), this, SLOT(enemyMove()));
  timer->start(2000);
  /*     s=std::make_pair(rowE,columnE);
       d=std::make_pair(drow1,dcol1);
       search(data,s,d)*/
  ;

  //    d_E = new int*[10];
  //    for(int i=0; i<10; i++)
  //        *(d_E+i) = new int[10];
  //    if (liveE == 0){
  //        scene()->removeItem(enemy);
  //    pathIndex = 0;
  //        graph = new Graph(boardData);
  //        switch(index)
  //        {
  //        case 0: path = graph->Shortestpath(getposE(), getposE());break;
  //        case 1: path = graph->Shortestpath(getposE(), getposE());break;
  //        case 2: path = graph->Shortestpath(getposE(), getposE());break;
  //        case 3: path = graph->Shortestpath(getposE(), getposE());break;
  //        }
}

void Enemy::setFraklin(Franklin *frank) { franklin = frank; }

void Enemy::enemyMove() {
  drow1 = franklin->getRow();
  dcol1 = franklin->getCol();
  s = std::make_pair(rowE, columnE);
  d = std::make_pair(drow1, dcol1);
  search(data, s, d);
  if (finalPath.empty() == false) {
    pair1 temp = finalPath.top();
    finalPath.pop();
    int row = temp.first;
    int col = temp.second;
    rowE = row;
    columnE = col;
    setPos(50 + col * 50, 50 + row * 50);
    //        qDebug()<<"hello3";
  }
}
//       int  moveE=arc4random()%4;
//        if ( moveE==0 && data[rowE - 1][columnE] == 2)
//        {
//            rowE--;

//        }
//        else if (moveE==1 && data[rowE + 1][columnE] == 2)
//        {
//            rowE++;
//        }
//        else if (moveE==2 && data[rowE][columnE+1] == 2)
//        {
//            columnE++;
//        }
//        else if (moveE==3 && data[rowE][columnE-1] == 2)
//        {
//            columnE--;
//        }
//        setPos(50 + columnE * 50, 50 + rowE * 50);

//}
int Enemy::getRow() { return rowE; }
int Enemy::getColumn() { return columnE; }
void Enemy::setLives(int livesE) { liveE = livesE; }
int Enemy::getLivesE() { return liveE; }
// return true if the row and column is in range
bool Enemy::isValid(int row, int column) {
  if ((row >= 0) && (row < 10) && (column >= 0) && (column < 10))
    return true;
  return false;
}
// checks if input position is equal to the next destination
bool Enemy::isDest(int row, int column, pair1 d) {
  if (row == d.first && column == d.second)
    return true;
  return false;
}
// return true,if input position is not an obstacle
bool Enemy::isUnblocked(int graph[][10], int row, int column) {
  if (graph[row][column] == 2)
    return true;
  return false;
}
// clculates h value
double Enemy::calculateH(int row, int column, pair1 d) {
  return ((double)(sqrt((row - d.first) * (row - d.first)) +
                   (column - d.second) * (column - d.second)));
}
// backtracks to find full path from source to destination
void Enemy::Path(node nodeArray[10][10], pair1 d) {
  int row = d.first;
  int column = d.second;
  std::stack<pair1> path;
  while (!(nodeArray[row][column].parentRow == rowE &&
           nodeArray[row][column].parentColumn == columnE)) {
    path.push(std::make_pair(row, column));
    int tempRow = nodeArray[row][column].parentRow;
    int tempColumn = nodeArray[row][column].parentColumn;
    row = tempRow;
    column = tempColumn;
  }
  path.push(std::make_pair(row, column));
  // qDebug()<<"path1";
  if (path.empty() == false) {
    path.pop();
  }
  finalPath = path;

  return;
}
// applying a* to the start node and its adjacent nodes
void Enemy::search(int graph[10][10], pair1 s, pair1 d) {

  bool closedList[10][10];
  memset(closedList, false, sizeof(closedList));
  node nodeArray[10][10];
  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      nodeArray[i][j].f = FLT_MAX;
      nodeArray[i][j].g = FLT_MAX;
      nodeArray[i][j].h = FLT_MAX;
      nodeArray[i][j].parentRow = -1;
      nodeArray[i][j].parentColumn = -1;
    }
  }
  i = s.first;
  j = s.second;
  nodeArray[i][j].f = 0.0;
  nodeArray[i][j].g = 0.0;
  nodeArray[i][j].h = 0.0;
  nodeArray[i][j].parentRow = i;
  nodeArray[i][j].parentColumn = j;
  std::set<pair2> openList;
  openList.insert(std::make_pair(0.0, std::make_pair(i, j)));
  // bool found=false;
  while (!openList.empty()) {
    pair2 p = *openList.begin();
    openList.erase(openList.begin());
    i = p.second.first;
    j = p.second.second;
    closedList[i][j] = true;
    double newG, newF, newH;
    if (isValid(i - 1, j) == true) {
      if (isDest(i - 1, j, d)) {
        nodeArray[i - 1][j].parentRow = i;
        nodeArray[i - 1][j].parentColumn = j;
        Path(nodeArray, d);
        // found=true;
        //                 qDebug() << "a*1";
        return;
      } else if (closedList[i - 1][j] == false &&
                 isUnblocked(graph, i - 1, j) == true) {
        newG = nodeArray[i][j].g + 1;
        newH = calculateH(i - 1, j, d);
        newF = newG + newH;
        if (nodeArray[i - 1][j].f == FLT_MAX || nodeArray[i - 1][j].f > newF) {
          openList.insert(std::make_pair(newF, std::make_pair(i - 1, j)));
          nodeArray[i - 1][j].f = newF;
          nodeArray[i - 1][j].g = newG;
          nodeArray[i - 1][j].h = newH;
          nodeArray[i - 1][j].parentRow = i;
          nodeArray[i - 1][j].parentColumn = j;
        }
      }
    }
    if (isValid(i + 1, j) == true) {
      if (isDest(i + 1, j, d)) {
        nodeArray[i + 1][j].parentRow = i;
        nodeArray[i + 1][j].parentColumn = j;
        Path(nodeArray, d);
        // found=true;
        //                 qDebug() << "a*2";
        return;
      } else if (closedList[i + 1][j] == false &&
                 isUnblocked(graph, i + 1, j) == true) {
        newG = nodeArray[i][j].g + 1;
        newH = calculateH(i + 1, j, d);
        newF = newG + newH;
        if (nodeArray[i + 1][j].f == FLT_MAX || nodeArray[i + 1][j].f > newF) {
          openList.insert(std::make_pair(newF, std::make_pair(i + 1, j)));
          nodeArray[i + 1][j].f = newF;
          nodeArray[i + 1][j].g = newG;
          nodeArray[i + 1][j].h = newH;
          nodeArray[i + 1][j].parentRow = i;
          nodeArray[i + 1][j].parentColumn = j;
        }
      }
    }
    if (isValid(i, j + 1) == true) {
      if (isDest(i, j + 1, d)) {
        nodeArray[i][j + 1].parentRow = i;
        nodeArray[i][j + 1].parentColumn = j;
        Path(nodeArray, d);
        // found=true;
        //                 qDebug() << "a*3";
        return;
      } else if (closedList[i][j + 1] == false &&
                 isUnblocked(graph, i, j + 1) == true) {
        newG = nodeArray[i][j].g + 1;
        newH = calculateH(i, j + 1, d);
        newF = newG + newH;
        if (nodeArray[i][j + 1].f == FLT_MAX || nodeArray[i][j + 1].f > newF) {
          openList.insert(std::make_pair(newF, std::make_pair(i, j + 1)));
          nodeArray[i][j + 1].f = newF;
          nodeArray[i][j + 1].g = newG;
          nodeArray[i][j + 1].h = newH;
          nodeArray[i][j + 1].parentRow = i;
          nodeArray[i][j + 1].parentColumn = j;
        }
      }
    }
    if (isValid(i, j - 1) == true) {
      if (isDest(i, j - 1, d)) {
        nodeArray[i][j - 1].parentRow = i;
        nodeArray[i][j - 1].parentColumn = j;
        Path(nodeArray, d);
        // found=true;
        //                 qDebug() << "a*4";
        return;
      } else if (closedList[i][j - 1] == false &&
                 isUnblocked(graph, i, j - 1) == true) {
        newG = nodeArray[i][j].g + 1;
        newH = calculateH(i, j - 1, d);
        newF = newG + newH;
        if (nodeArray[i][j - 1].f == FLT_MAX || nodeArray[i][j - 1].f > newF) {
          openList.insert(std::make_pair(newF, std::make_pair(i, j - 1)));
          nodeArray[i][j - 1].f = newF;
          nodeArray[i][j - 1].g = newG;
          nodeArray[i][j - 1].h = newH;
          nodeArray[i][j - 1].parentRow = i;
          nodeArray[i][j - 1].parentColumn = j;
        }
      }
    }
  }
  return;
}
