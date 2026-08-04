#include <stdio.h>
#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int data)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = data;
};
void dequeue()
{

    queue[front++];
}

int isEmpty()
{
    return front == -1 || front > rear;
};

void bfs(int start)
{

    visited[start] = 1;
    enqueue(start);

    while (!isEmpty())
    {

        int current = dequeue();
        printf("%d", current);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (graph[visited][i] == 1 && !visited[i])
                {
                    visited[i] = 1;
                    enqueue(i);
                }
            }
        }
    }
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}