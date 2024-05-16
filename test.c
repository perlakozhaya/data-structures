#include <stdio.h>

#define N 7

int position_dichotomique(int T[], int size, int n) {
    int inf, sup, mid;
    inf = 0;
    sup = size - 1;
    while(inf < sup) {
        mid = (inf + sup) / 2;
        if(T[mid] == n) {
            return mid;
        }
        if(T[mid] < n) {
            inf = mid + 1;
        }
        else {
            sup = mid - 1;
        }
    }
    return size;
}

int main() {
    int vecteur[N] = {4, 7, 3, 1, 8, 6, 2};

    printf("%d\n", position_dichotomique(vecteur, N, 6));
}