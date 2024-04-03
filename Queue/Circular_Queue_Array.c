#include <stdio.h>
#define MAX_SIZE 7

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((rear + 1) % MAX_SIZE == front) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = value;
        printf("%d enqueued successfully.\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued.\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

int peek() {
    if (front == -1) {
        printf("Queue is empty. Peek operation cannot be performed.\n");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        int i = front;
        printf("Queue: ");
        do {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\n\n------ Queue Menu ------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                value = peek();
                if (value != -1)
                    printf("Front element: %d\n", value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
