#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Définition de la structure de nœud pour une liste chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* creerNoeud(int data) {
    Node* nouveauNoeud = (Node*)malloc(sizeof(Node));
    nouveauNoeud->data = data;
    nouveauNoeud->next = NULL;
    return nouveauNoeud;
}

// Fonction pour ajouter un nœud à la fin de la liste chaînée
void ajouterNoeud(Node** head, int data) {
    Node* nouveauNoeud = creerNoeud(data);
    if (*head == NULL) {
        *head = nouveauNoeud;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nouveauNoeud;
}

// Fonction pour afficher une liste chaînée
void afficherListe(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Exercice 5: Fonction pour vérifier si liste1 est incluse dans liste2
bool estIncluse(Node* liste1, Node* liste2) {
    Node* current1 = liste1;
    Node* current2 = liste2;

    // Parcourir les deux listes tant que nous n'avons pas fini de parcourir liste1
    while (current1 != NULL && current2 != NULL) {
        if (current1->data < current2->data) {
            // Si l'élément courant de liste1 est plus petit que celui de liste2
            // alors current1->data ne peut pas être dans liste2
            return false;
        } else if (current1->data > current2->data) {
            // Si l'élément courant de liste1 est plus grand que celui de liste2
            // alors nous avançons dans liste2
            current2 = current2->next;
        } else {
            // Si les éléments sont égaux, avancer dans liste1
            current1 = current1->next;
            current2 = current2->next;
        }
    }

    // Si nous avons parcouru toute liste1, cela signifie que tous ses éléments
    // étaient présents dans liste2
    return current1 == NULL;
}

// Exercice 4: Fonction pour inverser les elements d'une liste
void inverse(Node* list) {
    Node* start = list;
    Node* end;
    Node* temp;
    Node* current = list;

    while(current->next != NULL) {
        current = current->next;
    }
    end = current;

    if(start != end) {
        temp->data = start->data;
        start->data = end->data;
        end->data = temp->data;

        current = start;
        while(current->next != end) {
            current = current->next;
        }
        end = current;
        start = start->next;
    }
}

// Exercice 3: Une liste doublement chainée
typedef int element;

typedef struct Doubly {
    element data;
    struct Doubly* next;
    struct Doubly* previous;
} Doubly;

Doubly* createDoubly() {
    Doubly* list = (Doubly*)malloc(sizeof(Doubly));
    list->next = NULL;
    list->previous = NULL;

    return list;
}

void addDoubly(Doubly** list, element e, int k) {
    int counter = 0;
    Doubly* newDoubly = (Doubly*)malloc(sizeof(Doubly));
    newDoubly->data = e;
    newDoubly->next = NULL;
    newDoubly->previous = NULL;

    // Handle insertion at the head of the list
    if (k == 0 || *list == NULL) {
        newDoubly->next = *list;
        if (*list != NULL) {
            (*list)->previous = newDoubly;
        }
        *list = newDoubly;
        return;
    }

    Doubly* current = *list;

    // Traverse to the k-th position or end of the list
    while (counter < k - 1 && current->next != NULL) {
        current = current->next;
        counter++;
    }

    // Insert the new node
    newDoubly->next = current->next;
    newDoubly->previous = current;

    if (current->next != NULL) {
        current->next->previous = newDoubly;
    }
    current->next = newDoubly;
}

void addElement(Doubly** list, element e, int k) {
    int counter = 0;
    Doubly* newDoubly = (Doubly*)malloc(sizeof(Doubly));
    newDoubly->data = e;
    newDoubly->next = NULL;
    newDoubly->previous = NULL;

    // Si la liste est vide et qu'on veut ajouter après la position 0
    if (*list == NULL) {
        *list = newDoubly;
        return;
    }

    Doubly* current = *list;

    // Parcours de la liste jusqu'à la position k
    while (counter < k && current->next != NULL) {
        current = current->next;
        counter++;
    }

    // Insertion du nouveau nœud après la position k
    newDoubly->next = current->next;
    newDoubly->previous = current;

    if (current->next != NULL) {
        current->next->previous = newDoubly;
    }
    current->next = newDoubly;
}

void afficher(Doubly* list) {
    while(list->next != NULL) {
        printf("%d", list->data);
        list = list-> next;
    }
}

int main() {
    Node* liste1 = NULL;

    ajouterNoeud(&liste1, 1);
    ajouterNoeud(&liste1, 3);
    ajouterNoeud(&liste1, 5);

    printf("Liste 1 avant: ");
    afficherListe(liste1);
    
    inverse(liste1);

    printf("Liste 1 apres: ");
    afficherListe(liste1);

    Doubly* list = createDoubly();
    addDoubly(&list, 4, 0);
    addDoubly(&list, 3, 1);
    addDoubly(&list, 2, 2);
    afficher(list);
    
    printf("\n");
    addElement(&list, 1, 1);
    afficher(list);
  
    return 0;
}