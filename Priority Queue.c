
#include <stdio.h>
#define MAX 100

struct item
{
    int data;
    int priority;
};

struct item pq[MAX];
int size = 0;

// INSERT operation
void insert()
{
    int value, p;

    if (size == MAX)
    {
        printf("Priority Queue Overflow!\n");
        return;
    }

    printf("Enter the value: ");
    scanf("%d", &value);

    printf("Enter the priority: ");
    scanf("%d", &p);

    pq[size].data = value;
    pq[size].priority = p;

    size++;

    printf("Element inserted successfully.\n");
}

// DELETE operation
void delete()
{
    int i, pos = 0;

    if (size == 0)
    {
        printf("Priority Queue Underflow!\n");
        return;
    }

    // Find highest priority (smallest number)
    for (i = 1; i < size; i++)
    {
        if (pq[i].priority < pq[pos].priority)
        {
            pos = i;
        }
    }

    printf("Deleted element: %d\n", pq[pos].data);

    // Shift remaining elements
    for (i = pos; i < size - 1; i++)
    {
        pq[i] = pq[i + 1];
    }

    size--;
}

// PEEK operation
void peek()
{
    int i, pos = 0;

    if (size == 0)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    for (i = 1; i < size; i++)
    {
        if (pq[i].priority < pq[pos].priority)
        {
            pos = i;
        }
    }

    printf("Highest priority element: %d\n", pq[pos].data);
    printf("Priority: %d\n", pq[pos].priority);
}

// DISPLAY operation
void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is Empty!\n");
        return;
    }

    printf("\nElement\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- PRIORITY QUEUE OPERATIONS ---\n");
        printf("1. INSERT\n");
        printf("2. DELETE\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
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
--- PRIORITY QUEUE OPERATIONS ---
1. INSERT
2. DELETE
3. PEEK
4. DISPLAY
5. EXIT

Enter your choice: 1
Enter the value: 10
Enter the priority: 3
Element inserted successfully.

Enter your choice: 1
Enter the value: 20
Enter the priority: 1
Element inserted successfully.

Enter your choice: 1
Enter the value: 30
Enter the priority: 2
Element inserted successfully.

Enter your choice: 4

Element  Priority
10       3
20       1
30       2

Enter your choice: 3
Highest priority element: 20
Priority: 1

Enter your choice: 2
Deleted element: 20

Enter your choice: 5
Exiting program...
*/