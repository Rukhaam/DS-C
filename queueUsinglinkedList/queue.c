#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue
void enqueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory Overflow\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    // Queue is empty
    if (front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted successfully\n", data);
}

// Dequeue
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;

    printf("%d removed\n", front->data);

    front = front->next;

    // If queue becomes empty
    if (front == NULL)
    {
        rear = NULL;
    }

    free(temp);
}

// Peek
void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}

// Display
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    peek();

    return 0;
}