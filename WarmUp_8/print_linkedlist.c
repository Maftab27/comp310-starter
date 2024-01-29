#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

void push(Node** headRef, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *headRef;
    *headRef = new_node;
}

void deleteNode(Node** headRef, int key) {
    Node* temp = *headRef;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    Node* tnode = head;
    while (tnode != NULL) {
        printf("%d ", tnode->data);
        tnode = tnode->next;
    }
}
int main() {
    Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printf("\nCreated Linked list is:\n");
    printList(head);

    deleteNode(&head, 1);

    printf("\nLinked List after Deletion of 1:\n");
    printList(head);

    return 0;
}
