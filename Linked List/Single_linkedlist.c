#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ->\t", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//function to add node at beginning.
void insertAtBegining(struct Node** head, int value){
struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
 ptr->data=value;
 ptr->next=*head;
 *head=ptr;
}

//function to add node at end.
void insertAtEnd(struct Node** head, int value){
struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
 ptr->data=value;
 ptr->next=NULL;

if(head == NULL){
    *head=ptr;
    return;
}
struct Node* current =*head;
    while (current->next != NULL) {
        current=current->next;
    }
    current->next=ptr;

}
//function to add node at position.
void insertAtbetween(struct Node**head,int value,int position){
    if(position <1){
        printf("Invalid position.\n");
        return;
    }
struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
       ptr->data=value;
       if(position == 1){
        ptr->next=*head;
        *head =ptr;
        return;
       }
 struct Node*current =*head;
 for(int i=1;i<position-1 && current !=NULL;i++){
    current=current->next;
 }
   if(current == NULL){
    printf("please Try again....\n");
    return;
   }
   ptr->next=current->next;
   current->next=ptr;
}
//function to delete node from beginning.
void DeleteAtBegining(struct Node** head){
if(*head == NULL){
    printf ("List is Empty..\n");
    return;
}
struct Node*ptr = *head;
 *head =(*head)->next;
 free(ptr);

}
//function to delete node from last.
void DeleteAtEnd(struct Node**head){
 if(*head == NULL){
    printf("LIst is Empty..\n");
    return;
}
if((*head)->next == NULL){
    free(*head);
    *head = NULL;
    return;
}
struct Node*current=*head;
while(current->next->next != NULL){
     current=current->next;
}
free(current->next);
current->next = NULL;

}
//delete from intermediate position.
void DeleteAtPOsition(struct Node**head,int position){
if(*head == NULL){
    printf("List is empty...\n");
    return;
}
if (position == 0){
    DeleteAtBegining(head);
    return;
}
struct Node*current = *head;
for(int i=1;i<position-1 && current !=NULL;i++){
    current = current->next;
}
if (current == NULL || current->next ==NULL){
    printf("Invalid position...!\n");
    return;
}
struct Node*nodetodelete = current->next;
current->next = nodetodelete->next;
free(nodetodelete);

}

int main() {
    int choice, count, value,position;
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
            temp = newNode;
        }
    }

    do {
        printf("1.Display List\n");
        printf("2.Insert at Beginning\n");
        printf("3.Insert at End\n");
        printf("4.insert at position.\n");
        printf("5.Delete from First.\n");
        printf("6.Delete from Last.\n");
        printf("7.Delete from intermediate position.\n");
        printf("8.   Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Linked List:\n");
                displayList(head);
                break;
            case 2:
                printf("Enter the value to be insert:\n");
                scanf("%d",&value);
                insertAtBegining(&head,value);
                displayList(head);
                break;
             case 3:
                printf("Enter the value to be insert:\n");
                scanf("%d",&value);
                insertAtEnd(&head,value);
                displayList(head);
                break;
             case 4:
                printf("Enter the value to be insert:\n");
                scanf("%d",&value);
                printf("Enter the position:\n");
                scanf("%d",&position);
                insertAtbetween(&head,value,position);
                displayList(head);
                break;
            case 5:
                 DeleteAtBegining(&head);
                 displayList(head);
                break;
            case 6:
                 DeleteAtEnd(&head);
                 displayList(head);
                break;
            case 7:
                 printf("Enter the position:\n");
                 scanf("%d",&position);
                 DeleteAtPOsition(&head,position);
                 displayList(head);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 8);

  // Free memory
    struct Node* current = head;
    while (current != NULL) {
       struct Node* temp = current;
        current = current->next;
        free(temp);
        }
return 0;
}