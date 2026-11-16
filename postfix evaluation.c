
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value)
{
    stack[++top] = value;
}

// Pop operation
int pop()
{
    return stack[top--];
}

// Postfix evaluation
int evaluate(char exp[])
{
    int i, a, b;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (exp[i])
            {
                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    return pop();
}

// Main function
int main()
{
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d", evaluate(exp));

    return 0;
}
/*
Enter postfix expression: 23*54*+
Result = 26
Enter postfix expression: 23+5*
Result = 25
*/