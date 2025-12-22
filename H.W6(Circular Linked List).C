#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void deleteAtPosition(Node** head, int pos) {
    if (*head == NULL) return;
    Node *temp = *head, *prev = NULL;
    if (pos == 0) {
        Node* last = *head;
        while (last->next != *head) last = last->next;
        if (*head == last) {
            free(*head);
            *head = NULL;
        } else {
            last->next = (*head)->next;
            *head = (*head)->next;
            free(temp);
        }
        return;
    }
    for (int i = 0; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == *head) return;
    }
    prev->next = temp->next;
    free(temp);
}

void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");

}
