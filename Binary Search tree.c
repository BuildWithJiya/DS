
#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct node
{
    int data;
    struct node *left, *right;
};

// Create a new node
struct node* createNode(int value)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// INSERT operation
struct node* insert(struct node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);

    else if (value > root->data)
        root->right = insert(root->right, value);

    else
        printf("Duplicate values are not allowed!\n");

    return root;
}

// SEARCH operation
void search(struct node *root, int key)
{
    if (root == NULL)
    {
        printf("Element not found!\n");
        return;
    }

    if (root->data == key)
    {
        printf("Element found!\n");
    }
    else if (key < root->data)
    {
        search(root->left, key);
    }
    else
    {
        search(root->right, key);
    }
}

// INORDER traversal
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// PREORDER traversal
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// POSTORDER traversal
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find minimum value node
struct node* findMin(struct node *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

// DELETE operation
struct node* deleteNode(struct node *root, int key)
{
    struct node *temp;

    if (root == NULL)
    {
        printf("Element not found!\n");
        return root;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        // Node with no child or one child
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Main function
int main()
{
    struct node *root = NULL;
    int choice, value;

    do
    {
        printf("\n--- BINARY SEARCH TREE OPERATIONS ---\n");
        printf("1. INSERT\n");
        printf("2. SEARCH\n");
        printf("3. INORDER\n");
        printf("4. PREORDER\n");
        printf("5. POSTORDER\n");
        printf("6. DELETE\n");
        printf("7. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(root, value);
                break;

            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}
/*
--- BINARY SEARCH TREE OPERATIONS ---
1. INSERT
2. SEARCH
3. INORDER
4. PREORDER
5. POSTORDER
6. DELETE
7. EXIT

Enter your choice: 1
Enter value to insert: 50

Enter your choice: 1
Enter value to insert: 30

Enter your choice: 1
Enter value to insert: 70

Enter your choice: 1
Enter value to insert: 20

Enter your choice: 1
Enter value to insert: 40

Enter your choice: 3
Inorder Traversal: 20 30 40 50 70

Enter your choice: 4
Preorder Traversal: 50 30 20 40 70

Enter your choice: 5
Postorder Traversal: 20 40 30 70 50

Enter your choice: 2
Enter value to search: 40
Element found!

Enter your choice: 6
Enter value to delete: 30

Enter your choice: 3
Inorder Traversal: 20 40 50 70

Enter your choice: 7
Exiting program...
*/