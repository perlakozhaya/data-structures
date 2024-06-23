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
//Queue - Array
element queue[MAX];
int addPointer = 0;
int removePointer = 0;
int numberOfElements = 0;

bool isEmptyQueue(){
    return numberOfElements == 0;
}

bool isFullQueue(){
    return numberOfElements == MAX;
}

/*fi chi esmo initialisation lal queue 
yali hiye menzid zeroyet 3al array*/

void addQueue(element e){
    if(addPointer == MAX){
        addPointer = 0;
    }
    
    if(isEmptyQueue() || addPointer != removePointer){
        queue[addPointer] = e;
        numberOfElements++;
        addPointer++;
    }else{
        printf("\nl file melyene :|\n");
    }
}

void removeQueue(){
    if(removePointer == MAX) {
        removePointer = 0;
    }
    if(!isEmptyQueue()) {
        queue[removePointer] = 0;
        numberOfElements--;
        removePointer++;
    }
    else {
        printf("No more elements to remove hoonnn bi hottouwa Perla!!!!!!!!!");
    }
}

void displayQueue(){
    printf("[  ");
    for(int i = 0; i < MAX; i++){
        printf("%d  ", queue[i]);
    }
    printf("]\n");
}

//Queue - LinkedList
typedef struct Queue{
    Node* APointer;
    Node* DPointer;
}Queue;

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q-> APointer = NULL;
    q-> DPointer = NULL;

    return q;
}


void addQueueList(Queue* q, element e){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = NULL;

    if (q->APointer == NULL) {
        // If the queue is empty, both pointers should point to the new node
        q->APointer = newNode;
        q->DPointer = newNode;
    } else {
        // Otherwise, add the new node to the end and update APointer
        q->APointer->next = newNode;
        q->APointer = newNode;
    }
}

element removeQueueList(Queue* q) {
    if(q->DPointer != NULL) {
        Node* temp = q->DPointer;
        element e = q->DPointer->data;
        q->DPointer = q->DPointer->next;
        free(temp);
        return e;
    }
}

void displayQueueList(Queue* q){
    Node* current = q->DPointer;
    printf("[  ");
    while (current != NULL) {
        printf("%d  ", current->data);
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

    // push(&stack,1);
    // push(&stack,3);
    // push(&stack,30);
    // push(&stack,13);
    // display();
    // pop(&stack);
    // display();
    
    //queue - array
    // addQueue(1);
    // addQueue(2);
    // addQueue(3);
    // addQueue(4);
    // addQueue(5);
    // addQueue(6);
    // addQueue(7);
    // addQueue(8);
    // addQueue(9);
    // addQueue(10);
    
    // displayQueue();

    // removeQueue();
    // displayQueue();

    //queue - LinkedList
    Queue* q = createQueue();

    addQueueList(q, 4);
    addQueueList(q, -2);
    addQueueList(q, 3);
    addQueueList(q, 32);
    addQueueList(q, 13);
    displayQueueList(q);
    removeQueueList(q);
    removeQueueList(q);
    removeQueueList(q);
    removeQueueList(q);
    removeQueueList(q);
    removeQueueList(q);
    removeQueueList(q);
    displayQueueList(q);
}