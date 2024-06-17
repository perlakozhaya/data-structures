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
typedef struct Node{
    element data;
    struct Node* next;
}Node;

Node* stack = (Node*)malloc(sizeof(Node));

bool isEmpty(){
    return stack == NULL;
}

void push(Node** stack, element e){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode-> data = e;

    if(*stack == NULL){
    *stack = newNode;
    }

    while(*stack != NULL){
        *stack = (*stack)->next;
        printf("%d", (*stack)->data);
    }
    printf("%d", (*stack)-> data);
}

element pop(Node** stack){
    element temp;
    while((*stack)->next != NULL){
        *stack = (*stack)-> next;
    }
    temp = (*stack)-> data;
    (*stack)->next = NULL;
    return temp;
}

void display(){
    printf("[");
    while(!isEmpty){
        printf("%d ", stack-> data);
        stack = stack-> next;
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
}