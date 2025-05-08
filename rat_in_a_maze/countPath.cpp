// rat in a maze (R and D direction)

#include<iostream>
using namespace std;

int countPaths(int sr,int sc,int er,int ec){
    if(sr > er || sc > ec) return 0;
    if(sr == er && sc == ec) return 1;
    int rightWays = countPaths(sr+1,sc,er,ec);
    int downWays = countPaths(sr,sc+1,er,ec);
    return rightWays+downWays;
}

int main(){
    int row = 2, col = 3;
    cout<<countPaths(1,1,row,col)<<endl;
}