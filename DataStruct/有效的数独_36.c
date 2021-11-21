#include <stdio.h>

#define bool int
#define TRUE 1
#define FALSE 0

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    for (int i = 0; i < boardSize; i++) {
        int checkRow[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0 };
        int checkCol[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0 };

        for (int j = 0; j < boardSize; j++) {
            if (board[i][j] != '.') {
                checkRow[board[i][j] - '0']++;
            }
            if (board[j][i] != '.') {
                checkCol[board[j][i] - '0']++;
            }
            if ((i == 0 && j == 0) || (i == 0 && j == 3) || (i == 0 && j == 6) ||
                (i == 3 && j == 0) || (i == 3 && j == 3) || (i == 3 && j == 6) ||
                (i == 6 && j == 0) || (i == 6 && j == 3) || (i == 6 && j == 6) ) {
                int checkInBlock[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 , 0 };
                for (int inRow = i; inRow < i + 3; inRow++) {
                    for (int inCol = j; inCol < j + 3; inCol++) {
                        if (board[inRow][inCol] != '.') {
                            checkInBlock[board[inRow][inCol] - '0']++;
                        }
                    }
                }for (int cnt = 0; cnt < 10; cnt++) {
                    if (checkInBlock[cnt] > 1) {
                        return FALSE;
                    }
                }
            }
        }

        for (int j = 0; j < 10; j++) {
            if (checkRow[j] > 1 || checkCol[j] > 1) {
                printf("point 2");
                return FALSE;
            }
        }

    }
    return TRUE;
}

int main() {
    char board[][9] = {
        {'.','.','.','.','5','.','.','1','.'},
        {'.','4','.','3','.','.','.','.','.'},
        {'.','.','.','.','.','3','.','.','1'},
        {'8','.','.','.','.','.','.','2','.'},
        {'.','.','2','.','7','.','.','.','.'},
        {'.','1','5','.','.','.','.','.','.'},
        {'.','.','.','.','.','2','.','.','.'},
        {'.','2','.','9','.','.','.','.','.'},
        {'.','.','4','.','.','.','.','.','.'}};
    int boardColSize = 9;
    int* arr[9];
    for (int i = 0; i < 9; i++) {
        arr[i] = board[i];
    }
    printf("%d", isValidSudoku(arr, 9, &boardColSize));
    return 0;
}