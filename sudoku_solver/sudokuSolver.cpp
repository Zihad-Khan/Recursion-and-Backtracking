#include<iostream>
#include<vector>
using namespace std;
bool flag = false;

void printBoard(vector<vector<string>> board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isValidSudoku(int sr,int sc,vector<vector<string>> board){
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

bool isValid(vector<vector<string>> board,int row,int col,string ele){
    //row check
    for(int i=0;i<9;i++){
        if(i==col) continue;
        if(ele == board[row][i]) return false;
    }
    //column check
    for(int i=0;i<9;i++){
        if(i==row) continue;
        if(ele == board[i][col]) return false;
    }
    //container check
    int contianerStarRow = (row/3)*3;
    int containerStartCol = (col/3)*3;
    for(int i=contianerStarRow;i<contianerStarRow+3;i++){
        for(int j=containerStartCol;j<containerStartCol+3;j++){
            if(i==row && j==col) continue;
            if(board[i][j] == ele) return false;
        }
    }
    return true;

}

void sudokuSolver(vector<vector<string>> &board,int row,int col){
    //base case
    if(row == 9){
        flag = true;
        return;
    }

    if(board[row][col] != "."){//already a number so move to the next
        if(col!=8) sudokuSolver(board,row,col+1);
        else sudokuSolver(board,row+1,0);
    }else{
        for(int i=1; i<=9; i++){
            if(isValid(board,row,col,to_string(i))){// number is ok, move to the next
                board[row][col] = to_string(i);
                if(col!=8) sudokuSolver(board,row,col+1);
                else sudokuSolver(board,row+1,0);
                if(flag) return;
                board[row][col] = "."; // backtrack if not reached the answer
            }
        }
    }
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
    cout<<isValidSudoku(0,0,board);
    cout<<endl;
    sudokuSolver(board,0,0);
    printBoard(board);
    cout<<isValidSudoku(0,0,board);
}