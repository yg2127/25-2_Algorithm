//
// Created by À¯°Ç on 25. 9. 5.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    struct Node *Next, *Prev;
    char data;
}Node;

Node* getnode() {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> Prev = NULL;
    newnode -> Next = NULL;
    return nownode;
}