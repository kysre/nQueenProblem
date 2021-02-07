// functions pre-definitions:
int nQueenSolve(int queenN, int grid[maxX][maxY]);
int queenNum(int *n, int grid[maxX][maxY]);
int queenCheck(int row, int col, int grid[maxX][maxY]);
int solve(int row, int col, int *n, int grid[maxX][maxY]);
void printGrid(int grid[maxX][maxY]);
int exportFile(int grid[maxX][maxY]);


// functions:
int nQueenSolve(int queenN, int grid[maxX][maxY]) {
    int total = queenNum(&queenN, grid);
    printf("\n There is %d ways to put %d queens in a %d by %d board.\n", total, queenN, maxX, maxY);
    printf("----------------------------------------------------------------\n\n\n");
    return 0;
}


int queenNum(int *n, int grid[maxX][maxY]) {
    return solve(0, 0, n, grid);;
}

int solve(int row, int col, int *n, int grid[maxX][maxY]) {

    // Finding the place of the next queen
    for (int i = row; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            if (queenCheck(i, j, grid)) {

                if (*n == 1) {
                    grid[i][j] = 1;
                    queenTotal++;
                    // make file or print grid if needed:
                    if (printQueen == 1) printGrid(grid);
                    if (makeFile == 1) exportFile(grid);

                    grid[i][j] = 0;
                } else {
                    grid[i][j] = 1;
                    *n -= 1;

                    solve(i, j + 1, n, grid);

                    grid[i][j] = 0;
                    *n += 1;
                }
            }
        }
    }

    return queenTotal;
}



// Checks if we can put queen returns 1 else returns 0:
int queenCheck(int row, int col, int grid[maxX][maxY]) {
    // check that (row, col) is empty
    if (grid[row][col] == 1) return 0;
    // check row
    for (int c = 0; c < maxY; c++) {
        if (grid[row][c] == 1) return 0;
    }
    // check column
    for (int r = 0; r < maxX; r++) {
        if (grid[r][col] == 1) return 0;
    }
    // check diagonal UP/LEFT
    for (int i = row, j = col; (i >= 0) && (j >= 0); i--, j--){
        if (grid[i][j] == 1) return 0;
    }
    // check diagonal UP/RIGHT
    for (int i = row, j = col; (i >= 0) && (j < maxY); i--, j++){
        if (grid[i][j] == 1) return 0;
    }
    // check diagonal DOWN/LEFT
    for (int i = row, j = col; (i < maxX) && (j >= 0); i++, j--){
        if (grid[i][j] == 1) return 0;
    }
    // check diagonal DOWN/RIGHT
    for (int i = row, j = col; (i < maxX) && (j < maxY); i++, j++){
        if (grid[i][j] == 1) return 0;
    }

    return 1;
}

void printGrid(int grid[maxX][maxY]) {
    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------------------------------\n");
}

int exportFile(int grid[maxX][maxY]) {
    FILE *destFilePtr;
    destFilePtr = fopen(fileName, "a");

    for (int i = 0; i < maxX; i++) {
        for (int j = 0; j < maxY; j++) {
            fprintf(destFilePtr, "%d", grid[i][j]);
        }
        fprintf(destFilePtr, "\n");
    }
    fprintf(destFilePtr, "----------------------------------------------------------------\n");

    fclose(destFilePtr);
}

