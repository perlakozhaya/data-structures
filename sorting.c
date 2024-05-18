#include <stdio.h>
#include <stdbool.h>

#define N 7

// Bubble Sort
void tri_naif(int t[], int n) {
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (t[i] > t[j]) {
                tmp = t[i];
                t[i] = t[j];
                t[j] = tmp;
            }
        }
    }
}

void tri_bulle(int T[], int n) {
    int i, j, E;
    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (T[j] > T[j + 1]) {
                E = T[j + 1];
                T[j + 1] = T[j];
                T[j] = E;
            }
        }
    }
}

// Insertion Sort
void tri_insertion(int t[], int n) {
    int i, j, k;
    int tmp;
    for (i = 1; i < n; i++) {
        j = 0;
        while (t[j] < t[i]) { // for(j = 0; t[j] < t[i]; j++);
            j = j + 1;
        }
        tmp = t[i];
        for (k = i; k >= j + 1; k--) { // k >= j | k > j
            t[k] = t[k - 1]; // Shift elements to the right to make space for insertion
        }
        t[j] = tmp; // Insert the element into its correct position
    }
}

// Binary Insertion Sort
int position_dichotomique(int t[], int size, int e) {
    int inf, sup, mid;
    if(t[size - 1] <= e) {
        return size;
    }
    else {
        inf = 0;
        sup = size - 1;
        while(inf <= sup) {
            mid = (inf + sup) / 2;
            if(t[mid] == e) {
                return mid;
            }
            if(t[mid] < e) {
                inf = mid + 1;
            }
            else {
                sup = mid - 1;
            }
        }
    }
}

void insertion_dichotomique(int t[], int size) {
    int i, k, j, tmp;
    for(i = 1; i < size; i++) {
        if(t[i] < t[i - 1]) {
            tmp = t[i];
            j = position_dichotomique(t, i, t[i]);
            for(k = i; k > j; k--) {
                t[k] = t[k - 1];
            }
            t[j] = tmp;
        }
    }
}

// Selection Sort
void selection_sort(int t[], int n) {
    int min, tmp;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(t[j] < t[min]) {
                min = j;
            }
        }
        tmp = t[min];
        t[min] = t[i];
        t[i] = tmp;
    }
}

int main() {
    int vecteur[N] = {4, 7, 3, 1, 8, 6, 2};

    printf("Original Array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");

    insertion_dichotomique(vecteur, N);

    printf("After:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vecteur[i]);
    }
    printf("\n");
}