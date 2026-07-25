#include <stdio.h>

#include <stdlib.h>

#define MAX 100

int stack[MAX];

int top = -1;

int enqueue(int data)
{

    if (top == MAX - 1)
    {
        printf("stack overflow");
    };
    top++;
    stack[top] = data;

    return 0;
}

int dequeue()
{

    if (top == -1)
    {
        printf("stack is empty");
    };

    int item = stack[top];
    top++;

    printf("element removed %d", item);
};

int main()
{

    enqueue(10);
    enqueue(20);

    dequeue();

    return 0;
}