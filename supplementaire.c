#include <stdio.h>

void displayMatrix(int row, int col, int matrix[row][col]) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Trouver le produit de deux matrices en supposant que les matrices sont carres.
void produit(int *m1, int *m2, int size) {
    int produit[size][size]; // int produit[size][size] = {0} ma mechyit btef2och la2an b sir badda malloc w mb3rf chou

    // leh 3abayna 0 abel: hon ken 3am ysayev valeurs khaf2a la2ano ma kenit el produit[][] initialized kenit undefined   
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            produit[i][j] = 0;
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                produit[i][j] += (*(m1 + i * size + k)) * (*(m2 + k * size + j));
            }
            printf("%d ", produit[i][j]);
        }
        printf("\n");
    }
}

void product(int *m1, int *m2, int row1, int col1, int row2, int col2) {
    int res[row1][col2];

    for(int row = 0; row < row1; row++) {
        for(int col = 0; col < col2; col++) {
            res[row][col] = 0;
        }
    }

    if(col1 == row2) {
        for(int i = 0; i < row1; i++) {
            for(int j = 0; j < col2; j++) {
                for(int k = 0; k < col1; k++) {
                    res[i][j] += (*(m1 + i * col1 + k)) * (*(m2 + k * col2 + j)) ;
                }
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("j must be equal to i'");
    }
}

// Simplification d'une matrice

// M^2, M^3 taba3 el graphes
void multiplication(int size, int matrice[][size], int degre) {
    int res[size][size];
    int tmp[size][size];

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            tmp[i][j] = matrice[i][j];
        }
    }

    if(degre < 2) {
        displayMatrix(size, size, matrice);
    }
    else {
        for(int d = 1; d < degre; d++) {
            for(int i = 0; i < size; i++) {
                for(int j = 0; j < size; j++) {
                    res[i][j] = 0;
                    for(int k = 0; k < size; k++) {
                        res[i][j] += tmp[i][k] * matrice[k][j];
                    }
                    tmp[i][j] = res[i][j];
                }
            }
        }
        displayMatrix(size, size, res);
    }
}

// void multiplicationNew(int size, int matrice[][size], int degre) {
//     int p[size][size];
//     int sum;
    
//     for(int i = 0; i < size; i++){
//         for(int j = 0; j < size; j++){
//             p[i][j] = matrice[i][j];
//         }
//     }
//     displayMatrix(size, size, p);

//     for(int i = 1; i < degre; i++){
//         for(int row = 0; row < size; row++){
//             for(int col = 0; col < size; col++){
//                 sum = 0;
//                 for(int e = 0; e < size; e++){
//                     sum += p[row][e] * matrice[e][col];
//                 }
//                 p[row][col] = sum;
//             }
//         }
//     }
//     displayMatrix(size, size, p);
// }

void multiplicationNew(int size, int matrice[][size], int degre) {
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

// Generate random values for a predefined matrix

int main() {
    // int vecteur[] = {7, 34, 5, 7, 7, 3, 7};

    // int row = 3, col = 3;
    int m1[3][3] = {
        {1, 2, 3},
        {8, 5, 6},
        {8, 8, 4}
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

    // product((int *)m3, (int *)m3, 2, 2, 2, 2);
    multiplicationNew(2, m3, 3);
}