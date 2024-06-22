#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef int element;

// Stack - Array
element pile[MAX];
int capacity = 0; // as programmers based on Richard capacity = ade fiya el array mech adde bet se3

bool estVide() {
    return capacity == 0;
}

bool estPleine() {
    return capacity == MAX;
}

void empiler(element e) {
    if(estPleine()) {
        printf("Pile est pleine!");
    }
    else {
        pile[capacity] = e;
        capacity++;
    }
}

element depiler() {
    if(estVide()) {
        printf("Pile est deja vide!");
    }
    else {
        element temp = pile[capacity-1];
        capacity--;
        return temp;
    }
}

void afficher() {
    if(estVide()) {
        printf("Pile vide");
    }
    else {
        for(int i = 0; i < capacity; i++) {
            printf("%d ", pile[i]);
        }
        printf("\n");
    }
}

// Stack - LinkedList
typedef struct Node {
    element data;
    struct Node* next;
}Node;

Node* stack;

bool isEmpty() {
    return stack->next == NULL;
}

void push(Node** stack, element e) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = *stack;
    *stack = newNode;
}

element pop(Node** stack) {
    Node* temp = *stack;
    element e = (*stack)->data;
    *stack = (*stack)->next;
    free(temp);
    return e;
}

void display() {
    Node* current = stack;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("]\n");
}

int main() {
    // empiler(3);
    // empiler(5);
    // empiler(4);
    // empiler(7);
    // empiler(1);
    // afficher();
    // depiler();
    // afficher();

    push(&stack,1);
    push(&stack,3);
    push(&stack,30);
    push(&stack,13);
    display();
    pop(&stack);
    display();
    // printf("Removed: %d\n", pop(&stack));
    // display();
}