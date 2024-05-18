#include <stdio.h>
#include <stdbool.h>

// Les vecteurs et les matrices occupent de la place successive dans la mémoire (contigües)

#define N 7

// 1. Traversing a vector
void displayVector(int v[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// 2. Somme des elements d'un vecteur: O(n)
int somme(int v[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += v[i];
    }
    return sum;
}

// 3.a Recherche séquentielle d’un élément e dans un vecteur non trié
bool recherche(int v[], int size, int e) {
    for(int i = 0; i < size; i++) {
        if(v[i] == e) {
            return true;
        }
    }
    return false;
}

// 3.b Recherche séquentielle d’un élément e dans un vecteur trié
bool recherche_trie(int T[], int n, int e) {
    int i = 0;
    while(i < n && T[i] < e) {
        i++;
    }
    return T[i] == e;
}

// 3.c Recherche dichotomique d’un élément e dans un vecteur trié
bool recherche_dichotomique(int v[], int size, int e) {
    int mid;
    int inf = 0;
    int sup = size - 1;
    while(inf <= sup) {
        mid = (inf + sup) / 2;
        if(v[mid] == e) {
            return true;
        }
        if(v[mid] < e) {
            inf = mid + 1;
        }
        else {
            sup = mid - 1;
        }
    }
    return false;
}

int main() {
    int vecteur[N] = {4, 7, 3, 1, 8, 6, 2};

    printf("Original Array:\n");
    displayVector(vecteur, N);

    recherche_dichotomique(vecteur, N, 8);

    printf("After:\n");
    displayVector(vecteur, N);
}