
#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// ENQUEUE operation
void enqueue()
{
    int value;

    if (rear == MAX - 1)
    {
        printf("Queue Overflow!\n");
    }
    else
    {
        printf("Enter the value: ");
        scanf("%d", &value);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue.\n", value);
    }
}

// DEQUEUE operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// PEEK operation
void peek()
{
    if (front == -1)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

// DISPLAY operation
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Queue elements are:\n");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 5);

    return 0;
}
/*
--- QUEUE OPERATIONS ---
1. ENQUEUE
2. DEQUEUE
3. PEEK
4. DISPLAY
5. EXIT

Enter your choice: 1
Enter the value: 10
10 inserted into queue.

Enter your choice: 1
Enter the value: 20
20 inserted into queue.

Enter your choice: 1
Enter the value: 30
30 inserted into queue.

Enter your choice: 4
Queue elements are:
10 20 30

Enter your choice: 3
Front element: 10

Enter your choice: 2
Deleted element: 10

Enter your choice: 4
Queue elements are:
20 30

Enter your choice: 5
Exiting program...*/