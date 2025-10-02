#include <stdio.h>
#include <stdlib.h>

typedef struct DCNode {
    int data;
    struct DCNode *prev, *next;
} DCNode;

DCNode* newDCNode(int data) {
    DCNode* n = (DCNode*)malloc(sizeof(DCNode));
    n->data = data;
    n->prev = n->next = n;
    return n;
}

void insertHeadDC(DCNode **head, int val) {
    DCNode* n = newDCNode(val);
    if (*head == NULL) {
        *head = n;
    } else {
        DCNode *last = (*head)->prev;
        n->next = *head;
        n->prev = last;
        last->next = n;
        (*head)->prev = n;
        *head = n;
    }
}

void insertTailDC(DCNode **head, int val) {
    DCNode* n = newDCNode(val);
    if (*head == NULL) {
        *head = n;
    } else {
        DCNode *last = (*head)->prev;
        n->next = *head;
        n->prev = last;
        last->next = n;
        (*head)->prev = n;
    }
}

void display(DCNode *head) {
    if (!head) return;
    DCNode *p = head;
    do {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(retour à tête)\n");
}

int main() {
    DCNode *head = NULL;

    insertHeadDC(&head, 10);
    insertHeadDC(&head, 5);
    insertTailDC(&head, 20);
    insertTailDC(&head, 30);

    printf("Liste doublement circulaire : ");
    display(head);

    return 0;
}