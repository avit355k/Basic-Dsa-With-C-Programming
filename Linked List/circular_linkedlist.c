#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node* next;
};
struct Node* head = NULL;
// Function to create a circular linked list
void createCircularLinkedList() {
 int n, data;
 struct Node* new_node, * last;
 printf("Enter the number of nodes: ");
 scanf("%d", &n);
 for (int i = 0; i < n; i++) {
 new_node = (struct Node*)malloc(sizeof(struct Node));
 printf("Enter the data for node %d: ", i + 1);
 scanf("%d", &data);
 new_node->data = data;
 if (head == NULL) {
 head = new_node;
 head->next = head;
 last = head;
 } else {
 new_node->next = head;
 last->next = new_node;
 last = new_node;
 }
 }
}
// Function to display the circular linked list
void displayCircularLinkedList() {
 struct Node* temp = head;
 if (head == NULL) {
 printf("The list is empty.\n");
 return;
 }
 printf("Circular Linked List: ");
 do {
 printf("%d ", temp->data);
 temp = temp->next;
 } while (temp != head);
 printf("\n");
}
// Function to add a node at the beginning of the circular linked list
void addToBeginning(int data) {
 struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 new_node->data = data;
 if (head == NULL) {
 head = new_node;
 head->next = head;
 } else {
 struct Node* temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 new_node->next = head;
 head = new_node;
 temp->next = head;
 }
}
// Function to add a node at the end of the circular linked list
void addToEnd(int data) {
 struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 new_node->data = data;
 if (head == NULL) {
 head = new_node;
 head->next = head;
 } else {
 struct Node* temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 new_node->next = head;
 temp->next = new_node;
 }
}
// Function to add a node after a specified location in the circular linked list
void addAfterLocation(int data, int position) {
 struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 new_node->data = data;
 struct Node* temp = head;
 int count = 1;
 do {
 if (count == position) {
 new_node->next = temp->next;
 temp->next = new_node;
 return;
 }
 temp = temp->next;
 count++;
 } while (temp != head);
 printf("Invalid position.\n");
}
// Function to delete the first node from the circular linked list
void deleteFromBeginning() {
 if (head == NULL) {
 printf("The list is empty. Nothing to delete.\n");
 return;
 }
 struct Node* temp = head;
 while (temp->next != head) {
 temp = temp->next;
 }
 if (temp == head) {
 free(head);
 head = NULL;
 } else {
 struct Node* to_delete = head;
 head = head->next;
 temp->next = head;
 free(to_delete);
 }
}
// Function to delete the last node from the circular linked list
void deleteFromEnd() {
 if (head == NULL) {
 printf("The list is empty. Nothing to delete.\n");
 return;
 }
 struct Node* temp = head;
 struct Node* prev = NULL;
 while (temp->next != head) {
 prev = temp;
 temp = temp->next;
 }
 if (prev == NULL) {
 free(head);
 head = NULL;
 } else {
 prev->next = head;
 free(temp);
 }
}
// Function to delete a node after a specified location in the circular linked list
void deleteAfterLocation(int position) {
 if (head == NULL) {
 printf("The list is empty. Nothing to delete.\n");
 return;
 }
 struct Node* temp = head;
 int count = 1;
 do {
 if (count == position) {
 struct Node* to_delete = temp->next;
 temp->next = to_delete->next;
 free(to_delete);
 return;
 }
 temp = temp->next;
 count++;
 } while (temp != head);
 printf("Invalid position.\n");
}
int main() {
 int choice, data, position;
 do {
 printf("\nCircular Linked List Operations:\n");
 printf("1. Create and display the list\n");
 printf("2. Add a node to the beginning\n");
 printf("3. Add a node to the end\n");
 printf("4. Add a node after a specified location\n");
 printf("5. Delete a node from the beginning\n");
 printf("6. Delete a node from the end\n");
 printf("7. Delete a node after a specified location\n");
 printf("8. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 createCircularLinkedList();
 displayCircularLinkedList();
 break;
 case 2:
 printf("Enter the data to add at the beginning: ");
 scanf("%d", &data);
 addToBeginning(data);
 displayCircularLinkedList();
 break;
 case 3:
 printf("Enter the data to add at the end: ");
 scanf("%d", &data);
 addToEnd(data);
 displayCircularLinkedList();
 break;
 case 4:
 printf("Enter the data to add: ");
 scanf("%d", &data);
 printf("Enter the position after which to add: ");
 scanf("%d", &position);
 addAfterLocation(data, position);
 displayCircularLinkedList();
 break;
 case 5:
 deleteFromBeginning();
 displayCircularLinkedList();
 break;
 case 6:
 deleteFromEnd();
 displayCircularLinkedList();
 break;
 case 7:
 printf("Enter the position after which to delete: ");
 scanf("%d", &position);
 deleteAfterLocation(position);
 displayCircularLinkedList();
 break;
 case 8:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice. Try again.\n");
 }
 } while (choice != 8);
 return 0;
}
