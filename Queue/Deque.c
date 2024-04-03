#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct deque {
    int data[MAX_SIZE];
    int front, rear;
};

void initDeque(struct deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(struct deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1));
}

int isEmpty(struct deque *dq) {
    return (dq->front == -1);
}

void insertFront(struct deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0)
        dq->front = MAX_SIZE - 1;
    else
        dq->front = dq->front - 1;

    dq->data[dq->front] = value;
}

void insertRear(struct deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX_SIZE - 1)
        dq->rear = 0;
    else
        dq->rear = dq->rear + 1;

    dq->data[dq->rear] = value;
}

void deleteFront(struct deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else {
        if (dq->front == MAX_SIZE - 1)
            dq->front = 0;
        else
            dq->front = dq->front + 1;
    }
}

void deleteRear(struct deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear) {
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->rear == 0)
        dq->rear = MAX_SIZE - 1;
    else
        dq->rear = dq->rear - 1;
}

void display(struct deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    int i;
    printf("Deque elements: ");
    i = dq->front;
    if (dq->front <= dq->rear) {
        while (i <= dq->rear)
            printf("%d ", dq->data[i++]);
    } else {
        while (i <= MAX_SIZE - 1)
            printf("%d ", dq->data[i++]);
        i = 0;
        while (i <= dq->rear)
            printf("%d ", dq->data[i++]);
    }
    printf("\n");
}

int main() {
    struct deque dq;
    initDeque(&dq);
    int choice, element;
    while (1) {
        printf("\n1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Delete from rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted at front: ");
                scanf("%d", &element);
                insertFront(&dq, element);
                break;
            case 2:
                printf("Enter the element to be inserted at rear: ");
                scanf("%d", &element);
                insertRear(&dq, element);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
