#include<iostream>
#include<vector>
using namespace std;
void printBoard(vector<vector<string>> board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isValid(int sr,int sc,vector<vector<string>> board){
    for(int r=sr;r<9;r++){
        for(int c=sc;c<9;c++){
            string ele = board[r][c];
            if(ele == ".") continue;
            //row check
            for(int i=0;i<9;i++){
                if(i==c) continue;
                if(ele == board[r][i]) return false;
            }
            //column check
            for(int i=0;i<9;i++){
                if(i==r) continue;
                if(ele == board[i][c]) return false;
            }
            //container check
            int contianerStarRow = (r/3)*3;
            int containerStartCol = (c/3)*3;
            for(int i=contianerStarRow;i<contianerStarRow+3;i++){
                for(int j=containerStartCol;j<containerStartCol+3;j++){
                    if(i==r && j==c) continue;
                    if(board[i][j] == ele) return false;
                }
            }
        }
    }
    return true;
}

int main(){
    vector<vector<string>> board = {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}
    };
    //printBoard(board);
    cout<<isValid(0,0,board)<<endl;
}