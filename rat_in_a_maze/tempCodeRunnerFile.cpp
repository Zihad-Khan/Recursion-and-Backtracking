printPath(maze,sr,sc-1,er,ec,path+"L");
    //up move
    printPath(maze,sr-1,sc,er,ec,path+"U");

    //backtracking
    maze[sr][sc] = 1;