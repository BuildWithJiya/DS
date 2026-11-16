
#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Insert at front
void insertFront()
{
    int value;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = MAX - 1;
    }
    else
    {
        front--;
    }

    deque[front] = value;

    printf("%d inserted at front.\n", value);
}

// Insert at rear
void insertRear()
{
    int value;

    if ((front == 0 && rear == MAX - 1) ||
        (front == rear + 1))
    {
        printf("Deque Overflow!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = value;

    printf("%d inserted at rear.\n", value);
}

// Delete from front
void deleteFront()
{
    if (front == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

// Delete from rear
void deleteRear()
{
    if (front == -1)
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
    {
        rear--;
    }
}

// Display deque
void display()
{
    int i;

    if (front == -1)
    {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Deque elements are: ");

    i = front;

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- DOUBLE ENDED QUEUE ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 6);

    return 0;
}
/*
--- DOUBLE ENDED QUEUE ---
1. Insert at Front
2. Insert at Rear
3. Delete from Front
4. Delete from Rear
5. Display
6. Exit

Enter your choice: 2
Enter the value: 10
10 inserted at rear.

Enter your choice: 2
Enter the value: 20
20 inserted at rear.

Enter your choice: 1
Enter the value: 5
5 inserted at front.

Enter your choice: 5
Deque elements are: 5 10 20

Enter your choice: 3
Deleted element: 5

Enter your choice: 4
Deleted element: 20

Enter your choice: 5
Deque elements are: 10

Enter your choice: 6
Exiting program...
*/