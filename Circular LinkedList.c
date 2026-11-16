
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted successfully.\n");
}

// Insert at end
void insertEnd()
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted successfully.\n");
}

// Insert at position
void insertPosition()
{
    struct node *newNode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        if (temp->next == head)
        {
            printf("Invalid position!\n");
            return;
        }

        temp = temp->next;
    }

    if (temp == NULL)
        return;

    newNode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node inserted successfully.\n");
}

// Delete from beginning
void deleteBeginning()
{
    struct node *temp, *last;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete from end
void deleteEnd()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    if (head->next == head)
    {
        head = NULL;
    }
    else
    {
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Delete from position
void deletePosition()
{
    struct node *temp, *prev;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (head == NULL || pos < 1)
    {
        printf("Invalid position or empty list!\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos; i++)
    {
        prev = temp;
        temp = temp->next;

        if (temp == head)
        {
            printf("Invalid position!\n");
            return;
        }
    }

    prev->next = temp->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display circular linked list
void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(HEAD)\n");
}

// Search an element
void search()
{
    struct node *temp;
    int key, pos = 1, found = 0;

    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    do
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }

        temp = temp->next;
        pos++;
    }
    while (temp != head);

    if (!found)
        printf("Element not found!\n");
}

// Main function
int main()
{
    int choice;

    do
    {
        printf("\n--- CIRCULAR LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                insertPosition();
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                deletePosition();
                break;

            case 7:
                display();
                break;

            case 8:
                search();
                break;

            case 9:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 9);

    return 0;
}
/*
--- CIRCULAR LINKED LIST ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Display
8. Search
9. Exit

Enter your choice: 1
Enter data: 10
Node inserted successfully.

Enter your choice: 2
Enter data: 20
Node inserted successfully.

Enter your choice: 2
Enter data: 30
Node inserted successfully.

Enter your choice: 7
Circular Linked List: 10 -> 20 -> 30 -> (HEAD)

Enter your choice: 8
Enter element to search: 20
Element found at position 2

Enter your choice: 4
Deleted element: 10

Enter your choice: 7
Circular Linked List: 20 -> 30 -> (HEAD)

Enter your choice: 9
Exiting program...
*/