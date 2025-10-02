#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

CNode* newCNode(int data) {
    CNode* n = (CNode*)malloc(sizeof(CNode));
    n->data = data;
    n->next = n;
    return n;
}

void insertHeadC(CNode **last, int val) {
    CNode *n = newCNode(val);
    if (*last == NULL) {
        *last = n;
    } else {
        n->next = (*last)->next;
        (*last)->next = n;
    }
}

void insertTailC(CNode **last, int val) {
    CNode *n = newCNode(val);
    if (*last == NULL) {
        *last = n;
    } else {
        n->next = (*last)->next;
        (*last)->next = n;
        *last = n;
    }
}

void display(CNode *last) {
    if (!last) return;
    CNode *p = last->next;
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("(retour à tête)\n");
}

int main() {
    CNode *last = NULL;

    insertHeadC(&last, 10);
    insertHeadC(&last, 5);
    insertTailC(&last, 20);
    insertTailC(&last, 25);

    printf("Liste simplement circulaire : ");
    display(last);

    return 0;
}