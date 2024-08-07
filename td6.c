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
    Doubly* list = NULL;
    return list;
}

void addDoubly(Doubly** list, element e) {
    Doubly* newDoubly = (Doubly*)malloc(sizeof(Doubly));
    newDoubly->data = e;
    newDoubly->previous = NULL;
    newDoubly->next = NULL;

    if(*list == NULL) {
        *list = newDoubly;
    }
    else {
        Doubly* current = *list;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newDoubly;
        newDoubly->previous = current;
        newDoubly->next = NULL;
    }
}

void addElement(Doubly** list, element e, int k) {
    Doubly* new_node = (Doubly*)malloc(sizeof(Doubly));
    new_node->data = e;

    if (*list == NULL) {
        if (k == 0) {
            new_node->next = NULL;
            new_node->previous = NULL;
            *list = new_node;
            printf("Inserted at the beginning\n");
        } else {
            printf("Index Out Of Bounds\n");
            free(new_node);
        }
        return;
    }

    Doubly* current = *list;
    int counter = 0;

    // Traverse to the k-th element
    while (current != NULL && counter < k) {
        current = current->next;
        counter++;
    }

    if (counter != k || current == NULL) {
        printf("Index Out Of Bounds\n");
        free(new_node);
        return;
    }

    // Insert the new node after the k-th element
    new_node->next = current->next;
    new_node->previous = current;
    if (current->next != NULL) {
        current->next->previous = new_node;
    }
    current->next = new_node;

    printf("Element added after index %d\n", k);
}

void removeDoubly(Doubly** list, element e) {
    if(*list == NULL){
        printf("List Is Empty");
        return;
    }
    Doubly* current = *list;

    while(current != NULL) {
        if(current->data == e) {
            Doubly* temp = current;
            if(current->previous == NULL) {
                *list = current->next;
                current->next->previous = NULL;
                free(temp);
            }

            else if(current->next == NULL) {
                current->previous->next = NULL;
                free(temp);
            }

            else {
                current->previous->next = current->next;
                current->next->previous = current->previous;
                free(temp);
            }
            current = temp->next;
        }
        else {
            current = current->next;
        }
    }
}

// Exercice 2: egalite entre deux listes
bool egalite(Node* l1, Node* l2) {
    while(l1 != NULL && l2 != NULL) {
        if(l1->data != l2->data) {
            return false;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return true;
}

int rangPair(Node* list) {
    int i = 1;
    int somme = 0;
    while(list != NULL) {
        if(i % 2 == 0) {
            somme += list->data;
        }
        i++;
        list = list->next;
    }
    return somme;
}

void deleteAllOcc(Node* list) {

}

void deleteOcc(Node** list, element e) {
    Node* temp;
    Node* current = *list;
    int occ = 0;
    while(current != NULL) {
        if(current->data == e) {
            occ++;
        }
        if(occ > 1) {
            temp = current;
            current = current->next;
            free(temp);
        }
        current = current->next;
    }
}

void delete_occ(Node** list, element e){
    Node* temp = (*list);
    Node* current = (*list);
    
    if(*list == NULL){
        printf("list is empty");
        return;
    }

    while(current != NULL){
        if(current->data == e) {
            break;
        }
        current = current->next;
    }

    while(current->next != NULL){
        if(current->next->data == e){
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            current = current->next;
        }
    }
}

void afficher(Doubly* list) {
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main() {
    Node* liste1 = NULL;

    ajouterNoeud(&liste1, 3);
    ajouterNoeud(&liste1, 3);
    ajouterNoeud(&liste1, 5);
    ajouterNoeud(&liste1, 3);
    ajouterNoeud(&liste1, 7);
    ajouterNoeud(&liste1, 3);

    afficherListe(liste1);
    delete_occ(&liste1, 3);
    afficherListe(liste1);

    // printf("Liste 1 avant: ");
    // afficherListe(liste1);
    // inverse(liste1);
    // printf("Liste 1 apres: ");
    // afficherListe(liste1);

    // Doubly* list = createDoubly();
    // addDoubly(&list, 4);
    // addDoubly(&list, 3);
    // addDoubly(&list, 2);
    // afficher(list);
    
    // addElement(&list, 1, 0);
    // afficher(list);

    // removeDoubly(&list, 1);
    // afficher(list);
 
    return 0;
}