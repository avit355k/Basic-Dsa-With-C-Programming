#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack
{
    char Arr[MAX_SIZE];
    int Top;
};

// Function to create an empty stack
void Create(struct Stack *Stack)
{
    Stack->Top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *Stack)
{
    return Stack->Top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *Stack)
{
    return Stack->Top == MAX_SIZE - 1;
}

// Function to insert an element into the stack
void push(struct Stack *Stack, char item)
{
    if (isFull(Stack))
    {
        printf("Stack Overflow!! Can't Add Element!!");
        return;
    }
    Stack->Arr[++Stack->Top] = item;
}

// Function to remove an element from the stack
char pop(struct Stack *Stack)
{
    if (isEmpty(Stack))
    {
        printf("Stack Underflow!! Can't Delete Element!!");
        return '\0';
    }
    return Stack->Arr[Stack->Top--];
}

// Function to reverse a string
void reverseString(char *input)
{
    struct Stack Stack;
    Create(&Stack);

    // Push each character onto the stack
    for (int i = 0; i < strlen(input); i++)
    {
        push(&Stack, input[i]);
    }

    // Pop each character from the stack to reverse the string
    for (int i = 0; i < strlen(input); i++)
    {
        input[i] = pop(&Stack);
    }
}

int main()
{
    char input[MAX_SIZE];

    // Get user input for the string
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    // Remove the newline character from the input
    input[strcspn(input, "\n")] = '\0';

    // Reverse the string
    reverseString(input);

    // Display the reversed string
    printf("Reversed string: %s\n", input);

    return 0;
}
