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

void deleteOccurrences(Node **head, int val) {
    Node *temp = *head, *prev = NULL;
    while (temp != NULL) {
        if (temp->data == val) {
            if (prev == NULL) {
                *head = temp->next;
                free(temp);
                temp = *head;
            } else {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
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
    head = newNode(3);
    head->next = newNode(5);
    head->next->next = newNode(3);
    head->next->next->next = newNode(7);

    printf("Liste initiale : ");
    display(head);

    int val;
    printf("Entrez la valeur à supprimer : ");
    scanf("%d", &val);

    deleteOccurrences(&head, val);

    printf("Liste après suppression : ");
    display(head);

    return 0;
}