#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arbre {
    int valeur;
    struct arbre* gauche;
    struct arbre* droite;
} arbre;

arbre* construire_arbre(int n, arbre* g, arbre* d) {
    arbre* root = (arbre*)malloc(sizeof(arbre));
    root->valeur = n;
    root->gauche = g;
    root->droite = d;
}

arbre* deBasEnHaut() {
    arbre* n1 = construire_arbre(10, NULL, NULL);
    arbre* n2 = construire_arbre(3, NULL, NULL);
    arbre* n3 = construire_arbre(-4, n2, NULL);
    arbre* n4 = construire_arbre(0, NULL, n1);
    arbre* n5 = construire_arbre(2, NULL, NULL);
    arbre* n6 = construire_arbre(6, n4, n5);
    arbre* racine = construire_arbre(8, n3, n6);

    return racine;
}

bool egalite_arbres(arbre* arbre1, arbre* arbre2) {
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

arbre* get_path_aux(arbre* T, int arrivee) {
    arbre* Q = (arbre*)malloc(sizeof(arbre));

    if(T->valeur == arrivee) {
        return Q;
    }
    get_path_aux(T->gauche, arrivee);
    get_path_aux(T->droite, arrivee);
}

int main() {
    arbre* arbre1 = deBasEnHaut();
    arbre* arbre2 = deBasEnHaut();

    printf("%d", egalite_arbres(arbre1, arbre2));

    return 0;
}