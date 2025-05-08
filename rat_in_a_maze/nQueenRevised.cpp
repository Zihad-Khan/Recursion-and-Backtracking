#include<iostream>
#include<vector>
using namespace std;

void print(int dim,vector<vector<string>> board){
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            cout<<board[i][j];
        }
        cout<<"\n";
    }
}
bool isSafe(vector<vector<string>> &board,int row,int col,int dim){
    //horizontal check
    for(int c=0;c<dim;c++){
        if(board[row][c] == "Q") {
            return false;
        }
    }
    //vertical check
    for(int r=0;r<dim;r++){
        if(board[r][col] == "Q") {
            return false;
        }
    }
    //left diagonal check
    for(int r=row,c=col;r>=0 && c>=0;r--,c--){
        if(board[r][c] == "Q") {
            return false;
        }
    }
    //right diagonal check
    for(int r=row,c=col;r>=0 && c<dim;r--,c++){
        if(board[r][c] == "Q") {
            return false;
        }
    }
    //cout<<"isSafe is ok"<<endl;
    return true;
}
void nQueenSolve(int row,int dim,vector<vector<string>> &board){
    //base case
    if(row == dim){
        print(dim,board);
        cout<<endl;
        return;
    }
    for(int col=0;col<dim;col++){
        if(isSafe(board,row,col,dim)){
            board[row][col] = "Q";
            nQueenSolve(row+1,dim,board);
            board[row][col] = ".";
        }
    }
}
int main(){
    int n = 8;
    vector<vector<string>> board(n,vector<string>(n,"."));
    //print(n,board);
    cout<<endl;
    nQueenSolve(0,n,board);
}