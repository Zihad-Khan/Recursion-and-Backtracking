#include<iostream>
#include<vector>
using namespace std;

void printPath(vector<vector<int>> maze,int sr,int sc,int er,int ec,string path){
    if(sr<0 || sc<0) return;
    if(sr>er || sc>ec) return;
    if(sr==er && sc==ec){
        cout<<path<<endl;
        return;
    }
    if(maze[sr][sc] == 0) return;
    if(maze[sr][sc] == -1) return;

    //setting flag
    maze[sr][sc] = -1;
    //right move
    printPath(maze,sr,sc+1,er,ec,path+"R");
    //down move
    printPath(maze,sr+1,sc,er,ec,path+"D");
    //left move
    printPath(maze,sr,sc-1,er,ec,path+"L");
    //up move
    printPath(maze,sr-1,sc,er,ec,path+"U");

    //backtracking
    maze[sr][sc] = 1;
}


int main(){
    int row = 3,col =4;
    vector<vector<int>> maze = {{1,0,1,1},
                                {1,1,1,1},
                                {1,0,1,1}
                               };
    //printVector(maze,row,col);
    printPath(maze,0,0,row-1,col-1,"");


}   