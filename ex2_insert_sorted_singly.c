#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int data) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->next = NULL;
    return n;
}

void insertSorted(Node **head, int val) {
    Node *n = newNode(val);
    Node *temp = *head, *prev = NULL;

    while (temp && temp->data < val) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        n->next = *head;
        *head = n;
    } else {
        prev->next = n;
        n->next = temp;
    }
}

void display(Node *head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;

    insertSorted(&head, 10);
    insertSorted(&head, 5);
    insertSorted(&head, 15);
    insertSorted(&head, 8);

    printf("Liste triée : ");
    display(head);

    return 0;
}