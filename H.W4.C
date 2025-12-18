#include <stdio.h>
#include <stdlib.h>

// ============================
// Node Structure for Doubly Linked List
// Time Complexity: O(1)
// ============================
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


// ============================
// Insert at the End of Doubly Linked List
// Time Complexity: O(1) if tail pointer maintained, otherwise O(n)
// ============================
void insertAtEnd(Node** head, Node** tail, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {       // List empty
        *head = newNode;
        *tail = newNode;
        return;
    }

    (*tail)->next = newNode;   // Append after tail
    newNode->prev = *tail;
    *tail = newNode;           // Update tail
}


// ============================
// Delete All Elements of Linked List Recursively
// Time Complexity: O(n)
// ============================
void deleteListRecursive(Node* head) {
    if (head == NULL) return;
    deleteListRecursive(head->next);
    free(head);
}


// ============================
// Insert at a Specific Position in Doubly Linked List
// Time Complexity: O(n) to reach position
// ============================
void insertAtPosition(Node** head, Node** tail, int value, int position) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 0) {  // Insert at head
        newNode->next = *head;
        if (*head != NULL) (*head)->prev = newNode;
        *head = newNode;
        if (*tail == NULL) *tail = newNode;
        return;
    }

    Node* temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;
    else
        *tail = newNode;

    temp->next = newNode;
}


// ============================
// Example Main Function to Test the Above Functions
// ============================
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtEnd(&head, &tail, 10);
    insertAtEnd(&head, &tail, 20);
    insertAtPosition(&head, &tail, 15, 1);  // Insert 15 at position 1

    // Print List Forward
    printf("List forward: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Delete all nodes recursively
    deleteListRecursive(head);
    head = NULL;
    tail = NULL;

    return 0;
} 




// Difference between Circular Linked List and Normal Linked List
//
// - Normal Linked List ends with a NULL pointer,
//   while Circular Linked List's last node points back to the head.
//
// - Traversal in Normal Linked List stops at NULL,
//   but in Circular Linked List you must be careful to avoid infinite loops.
//
// - Circular Linked List is useful for applications needing continuous looping.
//
// - Sorting algorithms on Circular Linked List require extra handling
//   to detect the loop end and avoid infinite traversal,
//   whereas sorting on Normal Linked List is straightforward.
//
// Time Complexity for traversal and sorting is generally O(n) for both,
// but circular lists need special care to avoid infinite loops.
