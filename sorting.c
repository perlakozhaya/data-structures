#include <stdio.h>

#define N 5

// Insertion Sort
void tri_insertion(int T[], int n) {
    int i, j, k;
    int tmp;
    for (i = 1; i < n; i++) {
        j = 0;
        while (T[j] < T[i]) {
            j = j + 1;
        }
        tmp = T[i];
        for (k = i; k >= j + 1; k--) {
            T[k] = T[k - 1];
        }
        T[j] = tmp;
    }
}

void tri_insertion2(int T[], int n) {
    int i, j, P, E;
    for (i = 1; i < N; i++) {
        E = T[i];
        j = i - 1;
        while (j >= 0) {
            if (T[j] > E) {
                T[j + 1] = T[j];
                P = j;
                j = j - 1;
            }
            else {
                P = j + 1;
                j = -1;
            }
        }
        T[P] = E;
    }
}

void tri_insertion3(int T[], int n) {
    int i, j, k;
    for (i = 1; i < n; i++) {
        for (j = 0; T[j] < T[i]; j++);
        int tampon = T[i];
        for (k = i; k > j; k--) {
            T[k] = T[k - 1];

        }
        T[j] = tampon;
    }
}

int main() {
    int vecteur[N] = {3, 5, -10, 0, 0};

    for(int i = 0; i < N; i++) {
        printf("%d " , vecteur[i]);
    }
    printf("\n");

    tri_insertion3(vecteur, N);

    for(int i = 0; i < N; i++) {
        printf("%d " , vecteur[i]);
    }
    printf("\n");
}