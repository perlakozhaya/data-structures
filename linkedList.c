#include <stdio.h>
#include <stdlib.h>

// Define the cellule struct
typedef struct cellule {
    int info;
    struct cellule *suivant;
} cellule;

// Function to create a linked list from an array


// Function to print the linked list


// Main function to test the creer function
int main() {
    int V[] = {1, 2, 3, 4, 5};
    int Nb = sizeof(V) / sizeof(V[0]);

    cellule *liste = creer(V, Nb);

    if (liste != NULL) {
        printList(liste);
    }

    // Free the allocated memory
    cellule *temp;
    while (liste != NULL) {
        temp = liste;
        liste = liste->suivant;
        free(temp);
    }

    return 0;
}