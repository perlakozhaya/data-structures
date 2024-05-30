#include <stdio.h>
#include <stdlib.h>

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

void freeList(node *list){
    node *temp;
    while (list != NULL) {
        temp = list;
        list = list->suivant;
        free(temp);
    }
}

// Main function to test the creer function
int main() {
    int V[] = {1, 2, 3, 4, 5};
    int Nb = sizeof(V) / sizeof(V[0]);

    node *list = createList(V, Nb);

    printListR(list);

    printf("%d", getInfo(list, 3));
    // Free the allocated memory
    freeList(list);

    return 0;
}