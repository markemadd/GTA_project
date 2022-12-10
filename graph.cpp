//#include "graph.h"
//#include <QString>
//#include <QDebug>
//#include <iostream>
//#include <QFile>
//#include <QTextStream>
//#include <float.h>
//#include  <set>
//#include <cmath>

//bool Graph::isValid(int row, int column){
//    if ( (row>=0)&&(row<10)&&(column>=0)&&(column<10))
//       return true;
//    return false;
//}
//// checks if row colum and columns are equal to  the next destination
//bool Graph::isDest(int row, int column, pair1 d){
//    if(row==d.first&&column==d.second){
//        return true;
//    }
//    else
//        return false;
//}
////return true,if on the road
//bool Graph::isUnblocked(int graph[][10],int row,int column){
//    if (graph[row][column]==2){
//        return true;
//    }
//    else{
//        return false;
//    }
//}
//double Graph::calculateH(int row,int column,pair1 d){
//    return ((double)(sqrt((row-d.first)*(row-d.first))+(column-d.second)*(column-d.second)));
//}
//void Graph::Path(node nodeArray[][10],pair1 d){
//    int row=d.first;
//    int column=d.second;
//    std::stack<pair1> path;
//    while (!(nodeArray[row][column].parentRow==row && nodeArray[row][column].parentColumn==column)){
//        path.push(std::make_pair(row,column));
//        int tempRow=nodeArray[row][column].parentRow;
//        int tempColumn=nodeArray[row][column].parentColumn;
//        row=tempRow;
//        column=tempColumn;
//    }
//        path.push(std::make_pair(row,column));
//        finalPath=path ;
////         while (!path.empty()){
////             pair1 p=path.top();
////             path.pop();
////         }
//        return;
//}
//void Graph::search(int graph[][10],pair1 s, pair1 d){
////     if (isValid(s.first, s.second)==false)
////     {
////         return;
////     }
////     if (isValid(d.first, d.second)==false)
////     {
////         return;
////     }
////     if (isUnblocked(graph, s.first, s.second)==false || isUnblocked(graph, d.first, d.second)==false)
////     {
////         return;
////     }
////     if (isDest(s.first, s.second, d)==true)
////     {
////         return;
////     }
//    bool closedList[10][10];
//    memset(closedList, false,sizeof(closedList));
//    node nodeArray[10][10];
//    int i,j;
//    for (i=0;i<10;i++){
//        for (j=0;j<10;j++){
//            nodeArray[i][j].f=FLT_MAX;
//            nodeArray[i][j].g=FLT_MAX;
//            nodeArray[i][j].h=FLT_MAX;
//            nodeArray[i][j].parentRow=-1;
//            nodeArray[i][j].parentColumn=-1;
//        }
//    }
//    i=s.first;
//    j=s.second;
//    nodeArray[i][j].f =0.0;
//    nodeArray[i][j].g =0.0;
//    nodeArray[i][j].h =0.0;
//    nodeArray[i][j].parentRow =i;
//    nodeArray[i][j].parentColumn =j;
//    std::set<pair2> openList;
//    openList.insert(std::make_pair(0.0,std::make_pair(i,j)));
//    //bool found=false;
//    while (!openList.empty()){
//        pair2 p=*openList.begin();
//        openList.erase(openList.begin());
//        i=p.second.first;
//        j=p.second.second;
//        closedList[i][j]=true;
//        double newG, newF, newH;
//        if (isValid(i-1,j)==true){
//            if (isDest(i-1,j,d)){
//                nodeArray[i-1][j].parentRow=i;
//                nodeArray[i-1][j].parentColumn=j;
//                Path(nodeArray,d);
//                //found=true;
//                return;
//            }
//            else if (closedList[i-1][j]==false && isUnblocked(graph,i-1,j)==true)
//            {
//                newG=nodeArray[i][j].g+1;
//                newH=calculateH(i-1,j,d);
//                newF=newG+newH;
//                if (nodeArray[i-1][j].f==FLT_MAX || nodeArray[i-1][j].f>newF){
//                    openList.insert(std::make_pair(newF,std::make_pair(i-1,j)));
//                    nodeArray[i-1][j].f =newF;
//                    nodeArray[i-1][j].g =newG;
//                    nodeArray[i-1][j].h =newH;
//                    nodeArray[i-1][j].parentRow =i;
//                    nodeArray[i-1][j].parentColumn =j;
//                }
//            }
//        }
//        if (isValid(i+1,j)==true){
//            if (isDest(i+1,j,d)){
//                nodeArray[i+1][j].parentRow=i;
//                nodeArray[i+1][j].parentColumn=j;
//                Path(nodeArray,d);
//               // found=true;
//                return;
//            }
//            else if (closedList[i+1][j]==false && isUnblocked(graph,i+1,j)==true)
//            {
//                newG=nodeArray[i][j].g+1;
//                newH=calculateH(i+1,j,d);
//                newF=newG+newH;
//                if (nodeArray[i+1][j].f==INFINITY || nodeArray[i+1][j].f>newF){
//                    openList.insert(std::make_pair(newF,std::make_pair(i+1,j)));
//                    nodeArray[i+1][j].f =newF;
//                    nodeArray[i+1][j].g =newG;
//                    nodeArray[i+1][j].h =newH;
//                    nodeArray[i+1][j].parentRow =i;
//                    nodeArray[i+1][j].parentColumn =j;
//                }
//            }
//        }
//        if (isValid(i,j+1)==true){
//            if (isDest(i,j+1,d)){
//                nodeArray[i][j+1].parentRow=i;
//                nodeArray[i][j+1].parentColumn=j;
//                Path(nodeArray,d);
//                //found=true;
//                return;
//            }
//            else if (closedList[i][j+1]==false && isUnblocked(graph,i,j+1)==true)
//            {
//                newG=nodeArray[i][j].g+1;
//                newH=calculateH(i,j+1,d);
//                newF=newG+newH;
//                if (nodeArray[i][j+1].f==INFINITY || nodeArray[i][j+1].f>newF){
//                    openList.insert(std::make_pair(newF,std::make_pair(i,j+1)));
//                    nodeArray[i][j+1].f =newF;
//                    nodeArray[i][j+1].g =newG;
//                    nodeArray[i][j+1].h =newH;
//                    nodeArray[i][j+1].parentRow =i;
//                    nodeArray[i][j+1].parentColumn =j;
//                }
//            }
//        }
//        if (isValid(i,j-1)==true){
//            if (isDest(i,j-1,d)){
//                nodeArray[i][j-1].parentRow=i;
//                nodeArray[i][j-1].parentColumn=j;
//                Path(nodeArray,d);
//                //found=true;
//                return;
//            }
//            else if (closedList[i][j-1]==false && isUnblocked(graph,i,j-1)==true)
//            {
//                newG=nodeArray[i][j].g+1;
//                newH=calculateH(i,j-1,d);
//                newF=newG+newH;
//                if (nodeArray[i][j-1].f==INFINITY || nodeArray[i][j-1].f>newF){
//                    openList.insert(std::make_pair(newF,std::make_pair(i,j-1)));
//                    nodeArray[i][j-1].f =newF;
//                    nodeArray[i][j-1].g =newG;
//                    nodeArray[i][j-1].h =newH;
//                    nodeArray[i][j-1].parentRow =i;
//                    nodeArray[i][j-1].parentColumn =j;
//                }
//            }
//        }
//    }
//    return;
//}
//void Graph::enemyMove()
//{
//    pair1 temp=finalPath.top();
//    if (finalPath.empty()==false){
//        finalPath.pop();
//        int row=temp.first;
//        int col=temp.second;
//        setPos(50+col*50,50+row*50);

//    }
//}
