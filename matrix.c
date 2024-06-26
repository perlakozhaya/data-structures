#include <stdio.h>

/* VLAs lack direct initialization at declaration because their size is determined at runtime, 
which makes it impossible for the compiler to know the size of the array at compile time 
to allocate memory for it and assign the initial values.
int mat[n][n] = {{0}}; will throw an error

Static arrays, with their fixed size known at compile time, can be initialized directly at declaration 
because the compiler can determine the required memory size and perform the initialization during compilation. 
#define N 10;
int mat[N][N] = {{0}}; works

In this C program, we will be using variable-length arrays (VLA) */

// 1. Generate random values for a given matrix

// 2. Display elements of a matrix
void displayMatrix(int row, int col, int matrix[row][col]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// 3. Trouver la transposée d'une matrice
void transpose(int row, int col, int matrix[row][col]) {
    int res[col][row];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            res[j][i] = matrix[i][j];
        }
    }

    displayMatrix(col, row, res);
}

// 4.a Trouver le produit de deux matrices en supposant que les matrices sont carrés.
void squareProduct(int n, int m1[n][n], int m2[n][n]) {
    int produit[n][n];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            produit[i][j] = 0;
            for(int k = 0; k < n; k++) {
                produit[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    displayMatrix(n, n, produit);
}

// 4.b Trouver le produit de deux matrices quelconques
void product(int row1, int col1, int row2, int col2, int m1[row1][col1], int m2[row2][col2]) {
    int res[row1][col2];

    if(col1 == row2) {
        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < col2; j++) {
                res[i][j] = 0;
                for(int k = 0; k < col1; k++) { // k < row2
                    res[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        displayMatrix(row1, col2, res);
    }
    else {
        printf("le nombre de colonnes de m1 doit etre egal au nombre de lignes dans m2 pour effectuer une multiplication!");
    }
}

// 5. Trouver M^n
void selfProduct(int size, int matrice[][size], int degre) {
    int p[size][size];
    int sum;
    
    // Initialize p with a copy of matrice
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            p[i][j] = matrice[i][j];
        }
    }
    displayMatrix(size, size, p);

    // Perform matrix exponentiation
    for(int i = 1; i < degre; i++){
        int temp[size][size]; // Create a temporary matrix to store the updated values of p
        for(int row = 0; row < size; row++){
            for(int col = 0; col < size; col++){
                sum = 0;
                for(int e = 0; e < size; e++){
                    sum += p[row][e] * matrice[e][col];
                }
                temp[row][col] = sum; // Store the result in temp
            }
        }
        // Update p with the values from temp
        for(int row = 0; row < size; row++){
            for(int col = 0; col < size; col++){
                p[row][col] = temp[row][col];
            }
        }
    }
    // Display the result matrix
    displayMatrix(size, size, p);
}

// 6. Simplification d'une matrice en une forme triangulaire superieure
void upperTriangular(int size, double m[size][size]) {
    int tmp;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // ta ma tse2eb division par 0 baddalet bel awwal el ligne matrah ma m[i][i] == 0 ma3 el ligne li tahta ka2ano L1 <-> L2
            if(m[i][i] == 0) {
                for(int l = 0; l < size; l++) {
                    tmp = m[i][l];
                    m[i][l] = m[i+1][l];
                    m[i+1][l] = tmp;
                }
            }
            // l facteur double ta ma ta3mel arrondissement lal jaweb 
            double facteur = m[j][i] / m[i][i]; // m[j][i] -> element yali bado ysir 0; m[i][i] element yali faw2o bi sater

            for (int k = i; k < size; k++) {
                m[j][k] -= facteur * m[i][k]; // ka2an L2 <- L2 - (facteur x L1)
            }
        }
    }

    // Print the result
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%.2f\t", m[i][j]); // %.2f kermel to3rodle bas 2 chiffres apres la virgule
        }
        printf("\n");
    }
}

// 7. Trouver la somme de deux matrices

// 8. Remplir une matrice identité

int main() {
    int m1[3][3] = {
        {2, -1, 2},
        {4, 3, -3},
        {-2, 2, 1}
    };

    int m2[3][2] = {
        {1, 2},
        {8, 5},
        {8, 8}
    };

    int m3[2][2] = {
        {1, 2},
        {1, 3}
    };

    double m4[3][3] = {
        {1, 0, 0},
        {0, 0, 2},
        {0, 3, 4}
    };

    // transpose(3, 2, m2);
    // product(3, 2, 2, 2, m2, m3);
    // upperTriangular(3, m4);

    return 0;
}