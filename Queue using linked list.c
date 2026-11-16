
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

// ENQUEUE operation
void enqueue()
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &newNode->data);

    newNode->next = NULL;

    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue.\n", newNode->data);
}

// DEQUEUE operation
void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow!\n");
    }
    else
    {
        temp = front;

        printf("Deleted element: %d\n", front->data);

        front = front->next;

        if (front == NULL)
            rear = NULL;

        free(temp);
    }
}

// PEEK operation
void peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        printf("Front element: %d\n", front->data);
    }
}

// DISPLAY operation
void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        temp = front;

        printf("Queue elements are: ");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
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
        printf("\n--- QUEUE USING LINKED LIST ---\n");
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
--- QUEUE USING LINKED LIST ---
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
Queue elements are: 10 20 30

Enter your choice: 3
Front element: 10

Enter your choice: 2
Deleted element: 10

Enter your choice: 4
Queue elements are: 20 30

Enter your choice: 5
Exiting program...
*/