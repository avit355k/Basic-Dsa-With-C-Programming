#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char x)
{
    stack[++top] = x;
}

// Function to pop an element from the stack
char pop()
{
    // Check if the stack is empty
    if (top == -1)
        return -1; // Return -1 if the stack is empty
    else
        return stack[top--]; // Return and decrement the top index
}
// Function to determine the priority of an operator
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}
int main()
{
    char exp[MAX_SIZE];
    char *e, x;
    // Input the infix expression
    printf("Enter the infix expression : ");
    scanf("%s", exp);
    printf("The Postfix Expression is:");

    e = exp;
    // Process the expression
    while (*e != '\0')
    {
        if (isalnum(*e))
            printf("%c ", *e); // Output operand
        else if (*e == '(')
            push(*e); // Push '(' onto the stack
        else if (*e == ')')
        {
            // Pop and output operators until '(' is encountered
            while ((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            // Pop and output operators with higher or equal priority
            while (priority(stack[top]) >= priority(*e))
                printf("%c ", pop());
            push(*e); // Push the current operator onto the stack
        }
        e++;
    }
    // Output remaining operators on the stack
    while (top != -1)
    {
        printf("%c ", pop());
    }
    return 0;
}