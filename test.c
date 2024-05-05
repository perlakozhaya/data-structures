#include <stdio.h>

#define ROWS 3
#define COLS 3

void printMatrix(int mat[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void echelonForm(int mat[][COLS], int rows, int cols) {
    int lead = 0;

    for (int r = 0; r < rows; r++) {
        if (lead >= cols)
            break;

        int i = r;
        while (mat[i][lead] == 0) {
            i++;
            if (i == rows) {
                i = r;
                lead++;
                if (lead == cols)
                    return;
            }
        }

        // Swap rows i and r
        for (int j = 0; j < cols; j++) {
            int temp = mat[i][j];
            mat[i][j] = mat[r][j];
            mat[r][j] = temp;
        }

        // Reduce other rows
        for (int i = r + 1; i < rows; i++) {
            int lv = mat[i][lead];
            for (int j = 0; j < cols; j++) {
                mat[i][j] -= lv * mat[r][j];
            }
        }
        lead++;
    }
}

int main() {
    int matrix[ROWS][COLS] = {
    {2, -1, 2},
    {4, 3, -3},
    {-2, 2, 1}
    };

    printf("Original Matrix:\n");
    printMatrix(matrix, ROWS, COLS);

    echelonForm(matrix, ROWS, COLS);

    printf("\nEchelon Form:\n");
    printMatrix(matrix, ROWS, COLS);

    return 0;
}
