#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Arbre {
    int valeur;
    struct Arbre* gauche;
    struct Arbre* droite;
} Arbre;

Arbre* construire_arbre(int n, Arbre* g, Arbre* d) {
    Arbre* root = (Arbre*)malloc(sizeof(Arbre));
    root->valeur = n;
    root->gauche = g;
    root->droite = d;
}

Arbre* deBasEnHaut() {
    Arbre* n1 = construire_arbre(10, NULL, NULL);
    Arbre* n2 = construire_arbre(3, NULL, NULL);
    Arbre* n3 = construire_arbre(4, n2, NULL);
    Arbre* n5 = construire_arbre(20, NULL, NULL);
    Arbre* n6 = construire_arbre(16, n1, n5);
    Arbre* racine = construire_arbre(8, n3, n6);

    return racine;
}

bool egalite_arbres(Arbre* arbre1, Arbre* arbre2) {
    // Check if both trees are NULL
    if (arbre1 == NULL && arbre2 == NULL) {
        return true;  // They are equal
    }
    
    // Check if both trees are not NULL
    if (arbre1 != NULL && arbre2 != NULL) {
        // Compare current node values and recursively check left and right subtrees
        return (arbre1->valeur == arbre2->valeur) 
               && egalite_arbres(arbre1->gauche, arbre2->gauche)
               && egalite_arbres(arbre1->droite, arbre2->droite);
    }
    
    // If one tree is NULL and the other is not, they are not equal
    return false;
}

// Exercice 4
int max_valeur(Arbre* a) {
    if(a == NULL) {
        printf("L'arbre est vide.\n");
        return -1;
    }
    if(a->droite == NULL) {
        return a->valeur;
    }
    return max_valeur(a->droite);
}

int supprimeMax(Arbre* a) {
    if(a == NULL) {
        printf("L'arbre est vide.\n");
        return -1;
    }

    Arbre* temp;
    if(a->droite->valeur == max_valeur(a)) {
        temp = a->droite;
        if(a->droite->gauche != NULL) {
            a->droite = a->droite->gauche;
        }
        else {
            a->droite = NULL;
        }
        int e = temp->valeur;
        free(temp);
        return e;
    }
    return supprimeMax(a->droite);
}

int main() {
    Arbre* arbre1 = deBasEnHaut();

    printf("%d", supprimeMax(arbre1));

    return 0;
}