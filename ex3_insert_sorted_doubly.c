#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

DNode* newDNode(int data) {
    DNode* n = (DNode*)malloc(sizeof(DNode));
    n->data = data;
    n->prev = n->next = NULL;
    return n;
}

void insertSortedD(DNode **head, int val) {
    DNode *n = newDNode(val);
    DNode *temp = *head;

    if (*head == NULL || (*head)->data >= val) {
        n->next = *head;
        if (*head) (*head)->prev = n;
        *head = n;
        return;
    }

    while (temp->next && temp->next->data < val)
        temp = temp->next;

    n->next = temp->next;
    if (temp->next) temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
}

void display(DNode *head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    DNode *head = NULL;

    insertSortedD(&head, 20);
    insertSortedD(&head, 5);
    insertSortedD(&head, 15);
    insertSortedD(&head, 25);
    insertSortedD(&head, 10);

    printf("Liste doublement chaînée triée : ");
    display(head);

    return 0;
}