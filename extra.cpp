/*nQueen(n,board,0);
    print(n,n,nQueen(n,board,0)); */

    /*for(int col=0;col<n;col++){
        if(isSafe(n,board,currentRow,col)){   
            board[currentRow][col] = "Q";
            cout<<board[currentRow][col]<<' ';
            //nQueen(n,board,currentRow+1);
            board[currentRow][col] = ".";
        }
    } */

    //bug free

    /*//left diagonal check
    for(int r=row,c=col;r>=0 && c>=0;r--,c--){
        if(board[r][c] == "Q") {
            return false;
        }
    }
    //right diagonal check
    for(int r=row,c=col;r<n && c>=0;r--,c++){
        if(board[r][c] == "Q") {
            return false;
        }
    } */
#include<iostream>
using namespace std;

int main(){
    char ch = 'h';
    cout<<"hello"+ch;
}
/*void printVector(vector<vector<int>> maze,int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}*/