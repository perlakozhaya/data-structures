#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Binary Tree
typedef int element;

typedef struct noeud {
    struct noeud *gauche;
    element info;
    struct noeud *droite;
} noeud;

// traiter un arbre
void traiter(noeud* racine) {
    printf("%d ", racine->info);
}

// parcours prefixe: profondeur du gauche a droite
void prefixe(noeud *racine){
    if(racine != NULL) {
        traiter(racine);
        prefixe((*racine).gauche);
        prefixe((*racine).droite);
    }
}

// parcours infixe
void infixe(noeud *racine) {
    if(racine != NULL){
        infixe((*racine).gauche);
        traiter(racine);
        infixe((*racine).droite);
    }
}

// parcours postfixe
void postfixe(noeud *racine) {
    if(racine != NULL){
        postfixe((*racine).gauche);
        postfixe((*racine).droite);
        traiter(racine);
    }
}

// taille d'un arbre binaire
int taille(noeud *racine) {
    if(racine == NULL) return 0;
    else return 1+taille((*racine).gauche)+taille((*racine).droite);
}

// nombre de feuilles dans un arbre
int feuille(noeud* racine) {
    if(racine == NULL) return 0;
    else {
        if(((*racine).gauche == NULL) && ((*racine).droite == NULL)) {
            return 1;
        }
        else {
            return feuille((*racine).gauche)+feuille((*racine).droite);
        }
    }
}

bool nonDegenere(noeud *racine) {
    if(racine == NULL) return true;
    if (((*racine).gauche != NULL) && ((*racine).droite != NULL)) return true;
    else {
        if ( (*racine).gauche == NULL)
            return nondegenerer( (*racine).droite);
        else
            return nondegenerer( (*racine).gauche);
    }
}

int main() {
    noeud* racine = (noeud*)malloc(sizeof(noeud));
    noeud* noeud1 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud2 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud3 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud4 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud5 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud6 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud7 = (noeud*)malloc(sizeof(noeud));

    racine->info = 12;
    noeud1->info = 6;
    noeud2->info = 15;
    noeud3->info = 5;
    noeud4->info = 8;
    noeud5->info = 18;
    noeud6->info = 3;
    noeud7->info = 10;

    racine->gauche = noeud1;
    racine->droite = noeud2;

    noeud1->gauche = noeud3;
    noeud1->droite = noeud4;

    noeud2->droite = noeud5;

    noeud4->gauche = noeud6;
    noeud4->droite = noeud7;

    prefixe(racine);
    printf("\n");
    infixe(racine);
    printf("\n");
    postfixe(racine);
    printf("\n");
    printf("%d", feuille(racine));

    return 0;
}