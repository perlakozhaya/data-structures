#include <stdio.h>
#include <stdbool.h>

#define N 10

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

// Merge Sort
void fusion(int arr[], int gauche, int milieu, int droite) {
    int i, j, k;
    int n1 = milieu - gauche + 1;
    int n2 = droite - milieu;

    // Crée des tableaux temporaires pour stocker les données
    int L[n1], R[n2];

    // Copie les données dans les tableaux temporaires L[] et R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[gauche + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[milieu + 1 + j];
    }

    // Fusionne les tableaux temporaires en un seul tableau arr[]
    i = 0;
    j = 0;
    k = gauche;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie les éléments restants de L[], si des éléments sont restants
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copie les éléments restants de R[], si des éléments sont restants
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Fonction de tri fusion récursif
void tri_fusion(int arr[], int gauche, int droite) {
    if (gauche < droite) {
        // Trouve le point médian pour diviser le tableau en deux moitiés
        int milieu = (gauche + droite) / 2;

        // Trie les deux moitiés
        tri_fusion(arr, gauche, milieu);
        tri_fusion(arr, milieu + 1, droite);

        // Fusionne les deux moitiés triées
        fusion(arr, gauche, milieu, droite);
    }
}

// Quick Sort
void tri_rapide(int t[], int debut, int fin) {
    int orange = debut - 1;
    int pivot = t[fin];
    int tmp;

    while(debut < fin) {
        if(t[debut] <= pivot) {
            orange++;
            if(debut > orange) {
                tmp = t[debut];
                t[debut] = t[orange];
                t[orange] = tmp;
            }
            else {
                orange = debut;
            }
        }
        debut++;
    }

    orange++;
    if(debut > orange) {
        tmp = t[debut];
        t[debut] = t[orange];
        t[orange] = tmp;
    }

    printf("orange: %d \t", orange);
    printf("debut: %d \t", debut);
    printf("fin: %d \t", fin);
    printf("\n");
    tri_rapide(t, 0, orange-1);
    tri_rapide(t, orange+1, fin);
}

// void tri_rapide(int t[], int debut, int fin) {
//     if (debut >= fin) {
//         return;
//     }
    
//     int pivot = t[fin];
//     int orange = debut - 1;
//     int tmp;

//     for (int i = debut; i < fin; i++) {
//         if (t[i] <= pivot) {
//             orange++;
//             tmp = t[i];
//             t[i] = t[orange];
//             t[orange] = tmp;
//         }
//     }
    
//     orange++;
//     tmp = t[orange];
//     t[orange] = t[fin];
//     t[fin] = tmp;

//     tri_rapide(t, debut, orange - 1);
//     tri_rapide(t, orange + 1, fin);
// }

int main() {
    int vecteur[N] = {3, 2, 5, 0, 1, 8, 7, 6, 9, 4};
    display(vecteur, N);

    tri_rapide(vecteur, 0, N-1);

    display(vecteur, N);
}