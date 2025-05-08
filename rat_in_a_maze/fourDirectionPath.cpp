//this is the best example to understand backtracking

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<string> resultArr){
    for(int i=0;i<resultArr.size();i++){
        cout<<resultArr[i]<<" ";
    }
    cout<<endl;
}

void fourDirMaze(int sr,int sc,int er,int ec,vector<vector<bool>> &trap,string path,vector<string> &resultArr){
    
    if(sr>er || sc>ec) return;
    if(sr<0 || sc<0) return;
    if(trap[sr][sc]) return;
    if(sr==er && sc==ec) {
        resultArr.push_back(path);
        //cout<<path<<endl;
        return;
    }

    //setting the flag
    trap[sr][sc] = true;
    //cout<<"trap["<<sr<<"]["<<sc<<"] = "<< trap[sr][sc]<<endl;
    // right move
    //cout<<"calling Right"<<endl;
    fourDirMaze(sr,sc+1,er,ec,trap,path+"R",resultArr);
    
    // down move
    //cout<<"calling Down"<<endl;
    fourDirMaze(sr+1,sc,er,ec,trap,path+"D",resultArr);
    // left move
    //cout<<"calling Left"<<endl;
    fourDirMaze(sr,sc-1,er,ec,trap,path+"L",resultArr);
    // up move
    //cout<<"calling Up"<<endl;
    fourDirMaze(sr-1,sc,er,ec,trap,path+"U",resultArr);
    trap[sr][sc] = false;
    //cout<<"made trap["<<sr<<"]["<<sc<<"] = "<< trap[sr][sc]<<endl;
    
}

int main(){
    int row = 3,col = 3;
    vector<string> resultArr;
    vector<vector<bool>> trap(row,vector<bool>(col,false));
    fourDirMaze(0,0,row-1,col-1,trap,"",resultArr);
    printVector(resultArr);
    cout<<trap[1][1];
}