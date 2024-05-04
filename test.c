#include <stdio.h>

#define rows 3
#define cols 2

void transposeMatrix(int row, int col, int matrix[row][col]) {
    int transposedMatrix[col][row];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }

    printf("Transposed Matrix:\n");
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[rows][cols] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    
    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    transposeMatrix(rows, cols, matrix);
}