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

// // taille d'un arbre binaire
// int taille(noeud *racine) {
//     if(racine == NULL) return 0;
//     else return 1+taille((*racine).gauche)+taille((*racine).droite);
// }

// // nombre de feuilles dans un arbre
// int feuille(noeud* racine) {
//     if(racine == NULL) return 0;
//     else {
//         if(((*racine).gauche == NULL) && ((*racine).droite == NULL)) {
//             return 1;
//         }
//         else {
//             return feuille((*racine).gauche)+feuille((*racine).droite);
//         }
//     }
// }

// // Lorsque tous les noeuds d'un arbre binaire ont deux ou zéro successeurs nous dirons que l'arbre binaire est homogène.
// bool nonDegenere(noeud *racine) {
//     if(racine == NULL) return true;
//     if(((racine->gauche != NULL) && (racine->droite == NULL)) ||
//     ((racine->gauche == NULL) && (racine->droite != NULL))) return false;
//     return nonDegenere(racine->gauche) && nonDegenere(racine->droite);
// }

// // Un arbre binaire est arbre binaire dégénéré si tous ses noeuds n'ont qu'un seul descendant.
// // to be written by Richard Akiki

// // Recherche associative dans un arbre binaire
// bool rechassoc(noeud *racine, element val) {
//     if(racine == NULL) return false;
//     else {
//         if((*racine).info == val) return true;
//         else {
//             if(rechassoc((*racine).gauche, val)) return true;
//             else return rechassoc((*racine).droite, val);
//         }
//     }
// }

// BINARY SEARCH TREE
// L’arbre est ordonné => On peut choisir le sous-arbre dans lequel il faut rechercher val (BST)
bool rechdicho(noeud *racine, element val) {
    if(racine == NULL) return false;
    else {
        if((*racine).info == val) return true;
        else { 
            if((*racine).info < val)
                return rechdicho((*racine).droite, val);
            else
                return rechdicho((*racine).gauche, val);
        }
    }
}

// // insertion dans un arbre binaire ordonné
// void insertion(noeud **racine, element val) {
//     if(*racine == NULL) {
//         noeud* nouveau = (noeud*)malloc(sizeof(noeud));
//         nouveau->info = val;
//         nouveau->gauche = NULL;
//         nouveau->droite = NULL;
//         *racine = nouveau;
//     }
//     else {
//         if((*racine)->info <= val) {
//             return insertion(&((*racine)->droite), val);
//         }
//         else {
//             return insertion(&((*racine)->gauche), val);
//         }
//     }    
// }

// suppression
// void supprimer(noeud *racine, element val) {
//     if (racine != NULL) {
//         if ((*racine).info = val)
//             delete_node(racine);
//         else {
//             if ((*racine).info > val)
//                 supprimer((*racine).gauche, val);
//             else
//                 supprimer((*racine).droite, val);
//         }
//     }
// }

// void delete_node(noeud *target) {
//     // Pointers for the node to be deleted and its replacement
//     noeud *node_to_delete, *replacement;
//     node_to_delete = target;

//     // If the node has a right child
//     if (target->droite != NULL) {
//         replacement = target->droite;

//         // Find the leftmost child in the right subtree
//         while (replacement->gauche != NULL) {
//             replacement = replacement->gauche;
//         }

//         // Attach the left subtree of the node to be deleted
//         replacement->gauche = node_to_delete->gauche;

//         // Replace the node with its right child
//         target = target->droite;
//     } else {
//         // If the node does not have a right child, replace it with its left child
//         target = target->gauche;
//     }

//     // Free the memory of the deleted node
//     free(node_to_delete);
// }

int main() {
    noeud* racine = (noeud*)malloc(sizeof(noeud));
    noeud* noeud1 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud2 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud3 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud4 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud5 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud6 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud7 = (noeud*)malloc(sizeof(noeud));
    noeud* noeud8 = (noeud*)malloc(sizeof(noeud));

    racine->info = 12;
    noeud1->info = 6;
    noeud2->info = 15;
    noeud3->info = 5;
    noeud4->info = 8;
    noeud5->info = 18;
    noeud6->info = 3;
    noeud7->info = 10;
    noeud8->info = 11;

    racine->gauche = noeud1;
    racine->droite = noeud2;

    noeud1->gauche = noeud3;
    noeud1->droite = noeud4;

    noeud2->droite = noeud5;
    noeud2->gauche = noeud8;

    noeud4->gauche = noeud6;
    noeud4->droite = noeud7;

    prefixe(racine);
    printf("\n");
    infixe(racine);
    printf("\n");
    postfixe(racine);
    printf("\n");
   
    return 0;
}