
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char x)
{
    stack[++top] = x;
}

// Pop operation
char pop()
{
    return stack[top--];
}

// Return precedence of operators
int precedence(char x)
{
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char infix[])
{
    char postfix[MAX];
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        // If operand, add to postfix
        if (isalnum(x))
        {
            postfix[j++] = x;
        }

        // If opening bracket
        else if (x == '(')
        {
            push(x);
        }

        // If closing bracket
        else if (x == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (top != -1)
                pop();
        }

        // If operator
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(x) ||
                   (precedence(stack[top]) == precedence(x) && x != '^')))
            {
                postfix[j++] = pop();
            }

            push(x);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s", postfix);
}

// Main function
int main()
{
    char infix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}
/*
Enter infix expression: A+B*C
Postfix Expression: ABC*+*/