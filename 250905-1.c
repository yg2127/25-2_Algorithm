//
// Created by 유건 on 25. 4. 20.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *prev, *next;
    char data;
}Node;

Node* getnode() {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> prev = NULL;
    newnode -> next = NULL;
    return newnode;
}
void init(Node **Head,Node **Tail) {
    *Head = getnode();
    *Tail = getnode();
    (*Head) -> next = *Tail;
    (*Tail) -> prev = *Head;
}

//===================================================================
Node* search(Node* Head, int l_num) { // search의 범위 = Head 다음노드 ~ Tail까지
    Node* curr = Head;
    for (int i = 0; i < l_num; i++) {
        curr = curr->next;
        if (curr == NULL) {
            printf("invalid position\n");
            return NULL;
         }
    }
    return curr;
}

void add(Node* Head, int l_num, char data) { // l_num 앞자리에 newnode 추가됨
    Node* Newnode = getnode();
    Newnode -> data = data;

    Node* curr = search(Head, l_num);
    if (curr == NULL) return;

    // 만약 curr = Tail이 되면 Tail 앞자리에 newnode가 추가됨 (맨 끝자리에 노드 추가!)
    // 만약 curr = 3번 노드라면 2번, 3번 사이에 newnode가 추가됨 (l_num번째 노드 앞에 추가!)

    Newnode -> next = curr;
    Newnode -> prev = curr -> prev;
    (curr -> prev) -> next = Newnode;
    curr -> prev = Newnode;
}
void print(Node* Head, Node* Tail) {
    Node* curr = Head;
    while (1) {
        curr = curr -> next;
        if (curr == Tail) break;
        printf("%c", curr -> data);
    }
    printf("\n");
}
void get(Node* Head, Node* Tail, int l_num) {
    Node* curr = search(Head, l_num);
    if (curr == Tail) {
        printf("invalid position\n");
        return;
    }

    printf("%c\n", curr -> data);
}
void delete(Node* Head, Node* Tail, int l_num){
    Node* curr = search(Head, l_num);
    if (curr == NULL) return;
    else if (curr == Tail) {
        printf("invalid position\n");
        return;
    }

    (curr -> next)->prev = curr -> prev;
    (curr -> prev)->next = curr -> next;
    free(curr);
}
//===================================================================
int main() {
    Node *Head, *Tail;
    init(&Head, &Tail);

    int n, l_num;
    char ADT, data;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &ADT);
        if (ADT == 'A') { // 순위 l_num노드 앞에 원소추가
            scanf("%d", &l_num);
            getchar();
            scanf("%c", &data);
            add(Head, l_num, data);
        }
        else if (ADT == 'P') { // 출력
            print(Head, Tail);
        }
        else if (ADT == 'G') { // 접근
            scanf("%d", &l_num);
            get(Head,Tail,l_num);
        }
        else { // 삭제
            scanf("%d", &l_num);
            delete(Head, Tail, l_num);
        }
    }


}