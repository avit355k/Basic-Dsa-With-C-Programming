#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// A Structure To Represent A Stack !!
struct Stack
{
    int Arr[MAX_SIZE];
    int Top;
};
// Function to create an empty stack
void create(struct Stack *stack)
{
    stack->Top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack *stack)
{
    return stack->Top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack)
{
    return stack->Top == -1;
}
// function to insert an element to stack!!
void push(struct Stack *stack, int value)
{
    if (isFull(stack))
    {
        printf("Stack Is Overflow!! Cann;t Add Elment!!");

        return;
    }
    stack->Arr[++stack->Top] = value;
}
// Function to remove An Element From Stack!
void pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Is UnderFlow!! Cann't Delete ELement!!");
        return;
    }
    stack->Arr[stack->Top--];
};

// Function To Return The Top Element Without Removing It!!
void Peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Is Empty !! Cann't Peek!!");
        return;
    }
    printf("Top Of The Stack Is: %d\n", stack->Arr[stack->Top]);
};

// Function to Display The Stack!!
void Display(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("The Stack Is Empty!!");
    }
    printf("The Stack Is:\n");
    for (int i = 0; i <= stack->Top; i++)
    {
        printf("%d\t", stack->Arr[i]);
    }
    printf("\n");
};

int main()
{
    struct Stack stack;
    create(&stack);

    int choice, value;

    do
    {

        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Your Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to push: ");
            scanf("%d", &value);
            push(&stack, value);
            Display(&stack);
            break;
        case 2:
            pop(&stack);
            Display(&stack);
            break;
        case 3:
            Peek(&stack);
            break;
        case 4:
            Display(&stack);
            break;
        case 5:
            printf("Exit....");
            break;
        }
    } while (choice != 5);

    return 0;
}