#include <stdio.h>
#include <string>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

// FUNCTION TO PUSH ONTO THE STACK!!
void push(char X)
{
    stack[++top] = X;
}

// function to remove from stack!!
int pop()
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW!!");
        return -1;
    }
    else
        return stack[top--];
}
int main()
{
    char exp[MAX_SIZE];
    char *e;
    int n1, n2, n3, num;

    printf("ENTER THE POSTFIX EQUATION:");
    scanf("%s", exp);

    e = exp;
    // process the equation!!
    while (*e != '\0')
    {
        if (isdigit(*e))
        {                   // If the character is a digit, convert it to an integer and push onto the stack!!
            num = *e - '0'; // convert character into integer!!
            push(num);
        }
        else
        {
            // If the character is an operator, pop two operands, perform the operation, and push the result back
            n1 = pop();
            n2 = pop();

            switch (*e)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n1 - n2;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            }
            // push the result back
            push(n3);
        }
        e++;
    }
    // The final result should be at the top of the stack
    printf("The result of expression %s = %d\n", exp, pop());

    return 0;
}
