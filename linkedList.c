#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node struct
typedef struct node {
    int info;
    struct node *suivant;
} node;

// Function to create a linked list from an array
node* createList(int t[], int size){
    node *list = NULL;
    node *newNode, *last = NULL;

    for(int i = 0; i < size; i++){
        newNode = (node*)malloc(sizeof(node));
        newNode -> info = t[i];
        newNode -> suivant = NULL;

        if(list == NULL){
            list = newNode;
        }else{
            last -> suivant = newNode;
        }
        last = newNode;
    }
    return list;
}
// Function to print the linked list
void printList(node *list){
    node *current = list;

    while(current != NULL){
        printf("%d ", current -> info);
        current = current -> suivant;
    }
    printf("\n");
}

void printListR(node *list){
    if(list == NULL){
        printf("\n");
    }else{
    printf("%d ", list -> info);
    printListR(list -> suivant);
    }
}

int getInfo(node *list, int index){
    int counter = 0;

    while(list != NULL){
        if(counter == index){
            return list -> info;
        }
        list = list -> suivant;
        counter++;
    }
    return 0;
}

node* acces_pos(node *liste, int k){
    node *current = liste;
    int i = 1;
    while(i < k && current != NULL){
        i++;
        current = current->suivant;
    }
    return current;
}

int getInfoR(node *list, int index){
    if(list != NULL) {
        if(index == 0) {
            return list->info;
        }
        else {
            return getInfoR(list->suivant, --index);
        }
    }
    else {
        return 0;
    }
}

int indexOf(node *list, int info) {
    node *current = list;
    int counter = 0;
    while(current != NULL) {
        if(info == current->info) {
            return counter;
        }
        current = current->suivant;
        counter++;
    }
    return -1;
}

int getIndex(node *list, int info, int index) {
    if(list != NULL) {
        if(list->info == info) {
            return index;
        }
        return getIndex(list->suivant, info, index+1);
    }
    else {
        return -1;
    }
}
int indexOfR(node *list, int info) {
    return getIndex(list, info, 0);
}

void freeList(node *list) {
    node *temp;
    while (list != NULL) {
        temp = list;
        list = list->suivant;
        free(temp);
    }
}

void addFirst(node **list, int value) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->info = value;
    newNode->suivant = *list;
    *list = newNode;
}

void removeFirst(node **list) {
    node *temp = *list;
    *list = (*list) -> suivant;
    free(temp);
}

bool supprimer(node **list, int index) {
    node* current = *list;
    if(index == 0 && *list != NULL) {
        removeFirst(list);
        return true;
    }
    if(index > 0) {
        while(current->suivant != NULL) {
            if(index == 1) {
                current->suivant = current->suivant->suivant;
                return true;
            }
            index--;
            current = current->suivant;
        }
        return false;
    }
    else {
        return false;
    }
}

// Main function to test the creer function
int main() {
    int V[] = {1, 2, 3, 4, 5};
    int Nb = sizeof(V) / sizeof(V[0]);

    node *list = createList(V, Nb);

    printListR(list);
    
    // printf("Index = %d\n", indexOf(list, 7));
    // printf("Recursive Index = %d\n", indexOfR(list, 7));

    // addFirst(&list, 3);
    // printListR(list);

    // removeFirst(&list);
    // printListR(list);

    supprimer(&list, 4);
    printListR(list);

    // Free the allocated memory
    freeList(list);

    return 0;
}