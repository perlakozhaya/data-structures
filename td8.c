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

void parcours_arbre(arbre* arbre) {
    parcours_arbre(arbre->gauche);
    parcours_arbre(arbre->droite);
}

bool egalite_arbres(arbre* arbre1, arbre* arbre2) {

}

int main() {
    arbre* arbre1 = deBasEnHaut();
    arbre* arbre2 = deBasEnHaut();

    return 0;
}