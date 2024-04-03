#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* current = head;
    printf("Double Linked List:\n");
    while (current != NULL) {
        printf(" %d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, count, value;
    struct Node* head = NULL;
    struct Node* temp = NULL;

    printf("Enter the number of nodes: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Enter the value for node %d: ", i + 1);
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    do {
        printf("1. Display List\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Double Linked List:\n");
                display(head);
                break;
            case 2:
                // Free memory
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 2);

    return 0;
}
