
#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

char stack[MAX];
int top = -1;

// PUSH operation
void push(char ch)
{
    stack[++top] = ch;
}

// POP operation
char pop()
{
    return stack[top--];
}

// Operator precedence
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) && ch != '^')))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

// Postfix Evaluation
int evalStack[MAX];
int evalTop = -1;

void evalPush(int value)
{
    evalStack[++evalTop] = value;
}

int evalPop()
{
    return evalStack[evalTop--];
}

int evaluatePostfix(char postfix[])
{
    int i, a, b;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (isdigit(ch))
        {
            evalPush(ch - '0');
        }
        else
        {
            b = evalPop();
            a = evalPop();

            switch (ch)
            {
                case '+':
                    evalPush(a + b);
                    break;

                case '-':
                    evalPush(a - b);
                    break;

                case '*':
                    evalPush(a * b);
                    break;

                case '/':
                    evalPush(a / b);
                    break;

                case '^':
                    evalPush((int)pow(a, b));
                    break;
            }
        }
    }

    return evalPop();
}

// Main function
int main()
{
    char infix[MAX], postfix[MAX];
    int choice;

    do
    {
        printf("\n--- INFIX AND POSTFIX OPERATIONS ---\n");
        printf("1. Infix to Postfix Conversion\n");
        printf("2. Postfix Evaluation\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                top = -1;

                printf("Enter infix expression: ");
                scanf("%s", infix);

                infixToPostfix(infix, postfix);

                printf("Postfix expression: %s\n", postfix);
                break;

            case 2:
                evalTop = -1;

                printf("Enter postfix expression: ");
                scanf("%s", postfix);

                printf("Result = %d\n", evaluatePostfix(postfix));
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}

/*
Sample Output
1. Infix to Postfix Conversion
--- INFIX AND POSTFIX OPERATIONS ---
1. Infix to Postfix Conversion
2. Postfix Evaluation
3. Exit

Enter your choice: 1
Enter infix expression: A+B*C
Postfix expression: ABC*+


2. Postfix Evaluation
Enter your choice: 2
Enter postfix expression: 23*5+
Result = 11
*/