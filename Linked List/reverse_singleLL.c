#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse the linked list
void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;         // Move pointers one position ahead
        current = next;
    }
    *head = prev;  // Update head to point to the new first node (last node of original list)
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n; // Number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    struct Node* head = NULL;

    // Input data for each node
    printf("Enter the data for each node:\n");
    for (int i = 0; i < n; ++i) {
        int data;
        scanf("%d", &data);
        insertAtEnd(&head, data);
    }

    printf("Original List: ");
    printList(head);

    // Reverse the linked list
    reverseLinkedList(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}
