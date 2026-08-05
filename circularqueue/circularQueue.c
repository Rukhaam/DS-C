#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int front = -1;
int rear = -1;
int queue[MAX];

void enqueue(int data) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
        queue[rear] = data;
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = data;
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("The data deleted is %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
