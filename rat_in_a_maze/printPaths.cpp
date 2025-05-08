// rat in a maze (R and D direction) printing the path

#include<iostream>
using namespace std;
int countPaths(int sr,int sc,int er,int ec){
    if(sr > er || sc > ec) return 0;
    if(sr == er && sc == ec) return 1;
    int rightWays = countPaths(sr+1,sc,er,ec);
    int downWays = countPaths(sr,sc+1,er,ec);
    return rightWays+downWays;
}

void printPaths(int sr,int sc,int er,int ec,string path){
    if(sr > er || sc > ec) return;
    if(sr == er && sc == ec){
        cout<<path<<endl;
        return;
    }

    //right move
    printPaths(sr+1,sc,er,ec,path+"R");
    //down move
    printPaths(sr,sc+1,er,ec,path+"D");
    return;
    
}

int main(){
    int row = 2, col = 3;
    cout<<"The no. of path is: "<<countPaths(1,1,row,col)<<endl;
    printPaths(1,1,row,col,"");
}