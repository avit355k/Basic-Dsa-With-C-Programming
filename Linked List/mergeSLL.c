#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to add a node at the end.
void insertAtEnd(struct Node** head, int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    ptr->data = value;
    ptr->next = NULL;

    if (*head == NULL) {
        *head = ptr;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = ptr;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    int n, value;

    // Input for the first linked list
    printf("Enter the number of elements in the first list: ");
    scanf("%d", &n);

    printf("Enter the elements for the first list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&list1, value);
    }

    // Input for the second linked list
    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n);

    printf("Enter the elements for the second list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertAtEnd(&list2, value);
    }

    // Print the first list
    printf("First List: ");
    printList(list1);

    // Print the second list
    printf("Second List: ");
    printList(list2);

    // Free the memory allocated for the lists
    freeList(list1);
    freeList(list2);

    return 0;
}
