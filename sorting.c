#include <stdio.h>
#include <stdbool.h>

#define N 7

//print all elements of an array
void display(int t[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", t[i]);
    }
    printf("\n");
}

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

// Insertion dichotomique
int position_dichotomique(int T[], int size, int n) {
    int position, inf, sup, mid;
    if(T[size - 1] <= n) {
        position = size;
    } 
    else {
        inf = 0;
        sup = size - 1;
        while(inf < sup) {
            mid = (inf + sup) / 2;
            if(T[mid] <= n) {
                inf = mid + 1;
            }
            else {
                sup = mid;
            }
        }
        position = sup;
    }
    return position;
}

void insertion_dichotomique(int t[], int size) {
    int i, k, j, tmp;
    for(i = 1; i < size; i++) {
        if(t[i] < t[i - 1]) {
            tmp = t[i];
            j = position_dichotomique(t, i-1, t[i]);
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

void fusion(int t1[], int t2[], int t[], int n1, int n2, int *n) {
    int l = t1[0];
    int r = t2[0];
    int i = 0;

    while (l < n1 && r < n2) {
        if (t1[l] <= t2[r]) {
            t[i] = t1[l];
            l++;
        } else {
            t[i] = t2[r];
            r++;
        }
        i++;
    }

    while (l < n1) {
        t[i] = t1[l];
        l++;
        i++;
    }

    while (r < n2) {
        t[i] = t2[r];
        r++;
        i++;
    }
    
    *n = n1 + n2;
}

int main() {
    int vecteur[N] = {4, 7, 3, 1, 8, 6, 2};
    display(vecteur, N);

    insertion_dichotomique(vecteur, N);
    display(vecteur, N);
}