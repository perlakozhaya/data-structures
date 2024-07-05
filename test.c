#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud de l'arbre
typedef struct node {
    int val;
    struct node *fg; // Fils gauche
    struct node *fd; // Fils droit
} node;

// Définition de la structure d'une cellule de la liste chaînée
typedef struct cellule {
    int val;
    struct cellule *suivant;
} cellule;

// Fonction pour ajouter un élément au début d'une liste chaînée
cellule *ajouter_debut(cellule *liste, int val) {
    cellule *nouveau = (cellule *)malloc(sizeof(cellule));
    nouveau->val = val;
    nouveau->suivant = liste;
    return nouveau;
}

// Fonction récursive pour trouver le chemin de la racine à un nœud avec la valeur X
cellule *get_path_aux(node *racine, int X) {
    if (racine == NULL) {
        return NULL;
    }
    if (racine->val == X) {
        // Crée une nouvelle liste avec le nœud trouvé
        cellule *nouvelle_liste = (cellule *)malloc(sizeof(cellule));
        nouvelle_liste->val = X;
        nouvelle_liste->suivant = NULL;
        return nouvelle_liste;
    }
    // Chercher dans le sous-arbre gauche
    cellule *chemin_gauche = get_path_aux(racine->fg, X);
    if (chemin_gauche != NULL) {
        // Ajouter la valeur actuelle à la liste si X est trouvé dans le sous-arbre gauche
        return ajouter_debut(chemin_gauche, racine->val);
    }
    // Chercher dans le sous-arbre droit
    cellule *chemin_droite = get_path_aux(racine->fd, X);
    if (chemin_droite != NULL) {
        // Ajouter la valeur actuelle à la liste si X est trouvé dans le sous-arbre droit
        return ajouter_debut(chemin_droite, racine->val);
    }
    // Si X n'est pas trouvé dans les sous-arbres gauche et droit
    return NULL;
}

// Fonction pour imprimer la liste
void imprimer_liste(cellule *liste) {
    printf("{");
    cellule *current = liste;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->suivant != NULL) {
            printf(", ");
        }
        current = current->suivant;
    }
    printf("}\n");
}