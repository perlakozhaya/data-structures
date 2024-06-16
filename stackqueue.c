#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int element;

// Stack - Array
int pile[MAX];
int size;

bool estVide() {
    return size == 0;
}

bool estPleine() {
    return size == MAX;
}

void afficher(int pile[MAX]) {
    if(estVide()) {
        printf("Pile vide");
    }
    else {
        printf("[ ");
        for(int i = 0; i < MAX; i++) {
            printf("%d ", pile[i]);
        }
        printf("]\n");
    }
}

void push(int pile[MAX], int val) {
    if(!estPleine()) {
        for(int i = MAX-2; i >= 0; i--) {
            pile[i + 1] = pile[i];
        }
        pile[0] = val;
        size++;
    }
    else {
        printf("Pile est pleine");
    }
    printf("size: %d", size);
}

void pop(int pile[MAX]) {
    if(!estVide()) {
        for(int i = 0; i < MAX-1; i++) {
            pile[i] = pile[i+1];
        }
        pile[MAX-1] = 0;
        size--;
    }
    else {
        printf("Pile est deja vide");
    }
    printf("size: %d", size);
}

element* removeElement() {
    element *val;
    if(estVide()) {
        printf("message d'erreur\n");
        return NULL;
    }
    else {
        size = size -1;
        val = &pile[size];
    }
    return val;
}

// Stack - LinkedList
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* stack;

void display(Node* stack) {
    Node* current = stack;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void empiler(Node** stack, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(*stack != NULL) {
        newNode->next = *stack;
    }
    newNode->data = val;
    *stack = newNode;
}

void depiler(Node** stack) {
    Node* temp = *stack;
    if(*stack != NULL) {
        *stack = (*stack)->next;
    }
    free(temp);
}

int main() {
    // empiler(&stack, 4);
    // display(stack);
    // empiler(&stack, 7);
    // display(stack);
    // depiler(&stack);
    // display(stack);
    push(pile, 3);
    afficher(pile);
    push(pile, 4);
    afficher(pile);
    pop(pile);
    afficher(pile);
}