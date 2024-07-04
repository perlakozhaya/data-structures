#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Exercice 2
int stack[MAX];
int capacity = 0;

int queue[MAX];

bool isEmpty(int s[]) {
    return capacity == 0;
}

bool isFull(int s[]) {
    return capacity == MAX;
}

int pop(int s[]) {
    if(isEmpty(s)) {
        printf("Stack already empty!");
        return 0;
    }
    else {
        int to_delete = s[capacity];
        capacity--;
        return to_delete;
    }
}

void push(int s[], int element) {
    if(isFull(s)) {
        printf("Stack is full");
    }
    else {
        s[capacity] = element;
        capacity++;
    }
}

void display(int s[]) {
    for(int i = 0; i < capacity; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
}

void sortArray(int tab[], int size) {
    int p1[MAX];
    int p2[MAX];

    for(int i = 0; i < size; i++) {
        if(isEmpty(p1)) {
            
        }
    }
}

int main() {
    int a[] = {5, 7, 2, 4, 8, 6, 3, 1 ,8};
}