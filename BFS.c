#include <stdio.h>

#define MAX 100

// Define colours
enum color
{
    white, grey, black
};

// Queue structure
struct queue
{
    int arr[MAX];
    int front;
    int rear;
};

// Initialize queue
void init(struct queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check whether queue is empty
int isempty(struct queue *q)
{
    return (q->front == -1);
}

// Insert element into queue
void enqueue(struct queue *q, int x)
{
    if (q->rear == MAX - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->arr[q->rear] = x;
}

// Remove element from queue
int dequeue(struct queue *q)
{
    int x;

    x = q->arr[q->front];

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }

    return x;
}

// Breadth First Search function
void bfs(int adj[MAX][MAX], int s, int p[],
         int d[], int n, enum color c[])
{
    int u, v;
    struct queue q;

    // Initialize all vertices
    init(&q);

    for (v = 0; v < n; v++)
    {
        c[v] = white;
        d[v] = 0;
        p[v] = -1;
    }

    // Initialize source vertex
    c[s] = grey;
    d[s] = 0;
    p[s] = -1;

    enqueue(&q, s);

    do
    {
        u = dequeue(&q);

        for (v = 0; v < n; v++)
        {
            if (adj[u][v] == 1)
            {
                if (c[v] == white)
                {
                    enqueue(&q, v);

                    d[v] = d[u] + 1;
                    p[v] = u;
                    c[v] = grey;
                }
            }
        }

        c[u] = black;

    } while (!isempty(&q));
}

// Main function
int main()
{
    int adj[MAX][MAX];
    int p[MAX], d[MAX];
    enum color c[MAX];

    int n, s, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices!");
        return 0;
    }

    printf("\nEnter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nEnter source vertex (0 to %d): ", n - 1);
    scanf("%d", &s);

    if (s < 0 || s >= n)
    {
        printf("Invalid source vertex!");
        return 0;
    }

    // Call BFS
    bfs(adj, s, p, d, n, c);

    // Display results
    printf("\nVertex\tDistance\tParent\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t", i);

        if (c[i] == white)
            printf("Not Reached\t");
        else
            printf("%d\t\t", d[i]);

        printf("%d\n", p[i]);
    }

    return 0;
}

/*
Enter number of vertices: 5

Enter adjacency matrix:
0 1 1 0 0
1 0 0 1 0
1 0 0 1 1
0 1 1 0 1
0 0 1 1 0

Enter source vertex (0 to 4): 0
Vertex  Distance    Parent
0       0           -1
1       1           0
2       1           0
3       2           1
4       2           2
*/