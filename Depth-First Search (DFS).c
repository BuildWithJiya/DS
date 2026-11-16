
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

// DFS traversal
void DFS(int vertex)
{
    int i;

    visited[vertex] = 1;

    printf("%d ", vertex);

    for (i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

// Main function
int main()
{
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        return 1;
    }

    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    DFS(start);

    printf("\n");

    return 0;
}
/*
Enter the number of vertices: 5

Enter the adjacency matrix:
0 1 1 0 0
1 0 0 1 1
1 0 0 0 1
0 1 0 0 0
0 1 1 0 0

Enter the starting vertex (0 to 4): 0

DFS Traversal: 0 1 3 4 2
*/