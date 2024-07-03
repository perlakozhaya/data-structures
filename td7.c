#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Exercice 2
int stack[MAX];
int capacity = 0;

int queue[MAX];

bool isEmpty() {
    return capacity == 0;
}

bool isFull() {
    return capacity == MAX;
}

int pop() {
    if(isEmpty()) {
        printf("Stack already empty!");
        return 0;
    }
    else {
        int to_delete = stack[capacity];
        capacity--;
        return to_delete;
    }
}

void push(int element) {
    if(isFull()) {
        printf("Stack is full");
    }
    else {
        stack[capacity] = element;
        capacity++;
    }
}

void display() {
    for(int i = 0; i < capacity; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int estPalindrome(char word[], int length) {
    for(int i = 0; i < length; i++) {
        if(i < length/2) {
            push(word[i]);
        }
        else if (i > length/2) {
            if(pop() != word[i]) {
                return 0;
            }
            else {
                return 1;
            }
        }
    }
}

int main() {
    // push(3);
    // push(2);
    // push(5);
    // push(2);
    // push(3);
    char word[] = "ab";
    printf("%d", estPalindrome(word, 3));
}