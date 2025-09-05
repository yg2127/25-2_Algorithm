//
// Created by 유건 on 25. 9. 5.
//
//
// Created by 유건 on 25. 6. 10.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int curr = 0;
int data[1000][3];

typedef struct Node {
    struct Node *left, *right;
    int data;
}Node;

Node *mknode(int data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}
Node *mktree() { // 현재 몇번노드인지 데이터 위치를 찾아주기 위해
    int rootdata = data[curr][0];
    int ldata = data[curr][1];
    int rdata = data[curr][2];
    curr++;
    Node* newnode = mknode(rootdata);

    if (ldata != 0) newnode -> left = mktree();
    if (rdata != 0) newnode -> right = mktree();
    return newnode;
}
void traversal(char *pass, Node *root) {
    int i;
    Node *curr = root;
    for (i = 0; i < strlen(pass); i++) {
        printf(" %d", curr -> data);
        if (pass[i] == 'R') curr = curr -> right;
        else if (pass[i] == 'L') curr = curr -> left;
    }
    printf(" %d\n", curr -> data);
}
int main() {
    int nn, nt;
    char pass[100];
    scanf("%d", &nn);
    getchar();

    for (int i = 0; i < nn; i++) {
        scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
    }
    Node t1, *root = &t1;
    root = mktree();
    scanf("%d", &nt);
    for (int i = 0; i < nt; i++) {
        scanf("%s", pass);
        traversal(pass, root);
    }
}