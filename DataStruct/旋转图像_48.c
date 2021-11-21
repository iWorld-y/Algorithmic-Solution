#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for (int i = 0; i < matrixSize - 1; i++) {
        for (int j = 0; j < matrixSize - 1; j++) {
            if (i + j >= matrixSize - 1) {
                continue;
            }
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][matrixSize - i - 1];
            matrix[matrixSize - j - 1][matrixSize - i - 1] = temp;
        }
    }
    for (int i = 0; i < matrixSize / 2; i++) {
        for (int j = 0; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - i - 1][j];
            matrix[matrixSize - i - 1][j] = temp;
        }
    }
}

int main() {
    int matrix[][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int size = 3;
    rotate(matrix, 3, &size);
    return 0;
}