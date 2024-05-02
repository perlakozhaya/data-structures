#include <stdio.h>
#include <stdbool.h>

#define MAX 3

// Exercice 1 - Somme et produit des éléments d’un vecteur
void sommeProduit(int vecteur[], int size) { // When you pass an array to a function in C, it decays into a pointer to its first element. You need to pass the array size as a parameter
    int somme = 0;
    int produit = 1;

    for(int i = 0; i < size; i++) {
        somme += vecteur[i];
        produit *= vecteur[i];
    }

    printf("La somme des elements du vecteur est: %d\n", somme);
    printf("Le produit des elements du vecteur est: %d\n", produit);

    // // Loop through an array and print its elements
    // // Step 1: Create a pointer to the array
    // int *vecteur_ptr = &vecteur;
    // // Step 2: Access and print elements of somme using the pointer
    // for(int i = 0; i < size; i++) {
    //     printf("%d\n", vecteur_ptr[i]);
    // }
}

// Exercice 2 - Inverser un vecteur dans un autre vecteur, puis sur lui-même.
void inverse(int v[], int size) {
    int t[size];
    int counter = 0;

    for(int i = size-1; i >= 0; i--) {
        t[counter] = v[i];
        counter++;
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", t[i]);
    }

    printf("\n");
}

void reverse(int v[], int size, int result[]) {
    for(int i = 0; i < size; i++) {
        result[i] = v[size - 1 - i];
    }
}

void reverseSelf(int v[], int size) {
    int tmp;
    for(int i = 0; i < size/2; i++) {
        tmp = v[i];
        v[i] = v[size-1-i];
        v[size-1-i] = tmp;
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }

    printf("\n");
}

// Exercice 3
void minMax(int t[], int size) {
    int min = t[0];
    int max = t[0];
    // int min = 0; barke el 0 mech mawjoud bel array???
    for(int i = 0; i < size; i++) {
        if(t[i] < min) {
            min = t[i];
        }
        if(t[i] > max) {
            max = t[i];
        }
    }

    printf("Maximum: %d\nMininum: %d\n", max, min);
}

// Exercice 4
bool estCroissant(int t[], int size) {
    for(int i = 0; i < size-1; i++) {
        if(t[i] > t[i+1]) {
            return true;
        }
    }
    return false;
}

// Exercice 5
int indexOf(int v[], int size, int n) {
    for(int i = 0; i < size; i++) {
        if(v[i] == n) {
            return i;
        }
    }
    return -1;
}

void supprimer(int t[], int size, int v) {
    while(indexOf(t, size, v) != -1) {
    int index = indexOf(t, size, v);
        for(int i = index; i < size-1; i++) {
            t[i] = t[i+1];
        }
    size--;
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", t[i]);
    }

    printf("\n");
}

// with pointer (without, it only ignores the elements == v without removing them)
void deleteAllOcc(int t[], int *n, int v) {
    int k = 0; // New index for the updated array
    for(int i = 0; i < *n; i++) {
        if(t[i] != v) {
            t[k++] = t[i]; // Copy non-matching elements to the beginning
        }
    }
    *n = k; // Update the size of the array

    // Print the updated array
    for(int i = 0; i < *n; i++) {
        printf("%d ", t[i]);
    }
    printf("\n");
}

int removeV(int t[], int n, int v) {
    for(int i = 0; i < n; i++) {
        if(t[i] == v) {
            for(int j = i + 1; j < n; j++) {
                t[j-1] = t[j];
            }
            i--;
            n--;
        }
    }
    return n;
}


// Exercice 6 - transposition d’une matrice: construction et affichage
void transposition(int t[][MAX], int row, int col) {
    int res[col][row];
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            res[j][i] = t[i][j];
        }
    }

    printf("\nTranspose Array:\n");
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
}

// Exercice 7 - Tableau majoritaire
bool elt_maj(int t[], int size, int e) {
    int counter = 0;
    for(int i = 0; i < size; i++) {
        if(t[i] == e) {
            counter++;
        }
    }
    if(counter > (size/2)) {
        return true;
    }
    return false;
}

bool tabMaj(int t[], int size) {
    for(int i = 0; i < size/2; i++) {
        if(elt_maj(t, size, t[i])) {
            return true;
        }
    }
    return false;
}

/* Exercice 8 - afficher les points-col d'une matrice. On appelle points-cols
les éléments d'une matrice qui sont à la fois un maximum sur leur ligne et un minimum sur leur 
colonne. */
void pointsCols(int M[][MAX], int row, int col) {
    // 8-a hayde enjezet Richard Simon Akiki
    for(int i = 0; i < row; i++) {
        int max = M[i][0];

        for(int j = 0; j < col; j++) {
            int min = M[0][j];

            for(int k = 0; k < row; k++) {
                if(M[i][k] > max) {
                    max = M[i][k];
                }
            }

            for(int l = 0; l < col; l++) {
                if(M[l][j] < min) {
                    min = M[l][j];
                }
            }

            if(max == min) { // he bet kaffe la2annon distincts wa ella kenit: max == min == M[i][j]
                printf("%d\t", M[i][j]);
            }
        }

    }
    printf("\n");
}

// 2e methode
void pointCol(int t[][MAX], int row, int col) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            bool estPointCol = true;
            for(int k = 0; k < row; k++) {
                if((t[i][j] < t[i][k]) || (t[i][j] > t[k][j])) {
                    estPointCol = false;
                    break;
                }
            }
            if(estPointCol) {
                printf("l'element t[%d][%d] = %d est un point col\n", i, j, t[i][j]);
            }
        }
    }
}

int symetrique(int M[][MAX], int row, int col) {
    // 8-b 3a amal tkoun enjez Perla Peter Kozhaya - mission accomplished
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(M[i][j] != M[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int sommeTriSup(int M[][MAX], int row, int col) {
    // 8-c - la somme des éléments de la partie triangulaire supérieure de la matrice M
    // teamwork :)
    int somme = 0;
    for(int i = 0; i < row; i++) {
        for(int j = i; j < col; j++) {
            somme += M[i][j];
        }
    }
    return somme;
}

int main() {
    int size = 7;
    int vecteur[] = {7, 34, 5, 7, 7, 3, 3};

    int row = 3, col = 3;
    int array[3][3] = {
        {1, 2, 3},
        {8, 5, 6},
        {8, 8, 4}
    };
    
    // // exercice 1
    // sommeProduit(vecteur, size);

    // // exercice 2
    // int reversedArray[size];
    // reverse(vecteur, size, reversedArray);

    // for(int i = 0; i < size; i++) {
    //     printf("%d ", reversedArray[i]);
    // }
    // printf("\n");

    // // exercice 3
    // minMax(vecteur, size);

    // // exercice 4
    // reverseSelf(vecteur, size);

    // exercice 5
    // supprimer(vecteur, size, 7);
    // deleteAllOcc(vecteur, &size, 7);
    // printf("%d", removeV(vecteur, size, 7));

    // exercice 6
    // transposition(array, row, col);

    // exercice 7
    // if(tabMaj(vecteur, size)) {
    //     printf("le tableau est majoritaire\n");
    // }
    // else {
    //     printf("le tableau n'est pas majoritaire\n");
    // }

    // exercice 8-a
    // pointsCols(array, row, col);
    // pointCol(array, row, col);

    // exercice 8-b
    // printf("%d", symetrique(array, row, col));

    // exercice 8-c
    // printf("%d", sommeTriSup(array, row, col));
}