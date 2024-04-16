//Program for circular Queue's Insertion, deletion and Traversing

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5 

int queue[MAX_SIZE];
int front = -1, rear = -1;
void enqueue(int);
int dequeue();
void display();
int isFull();
int isEmpty();

int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                if (isFull()) {
                    printf("Overflow\n");
                } else {
                    printf("Enter the elements to insert-> ");
                    scanf("%d", &data);
                    enqueue(data);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Underflow\n");
                } else {
                    data = dequeue();
                    printf("Deleted element: %d\n", data);
                }
                break;
            case 3: 
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}

int isFull() {
    return (rear == (front - 1 + MAX_SIZE) % MAX_SIZE);
}


int isEmpty() {
    return front == -1;
}

void enqueue(int data) {
    if (front == -1) {
        front = rear = 0;
    } else if (isFull()) {
        printf("Queue Overflow\n"); 
        return;
    } else {
        rear = (rear + 1) % MAX_SIZE; 
    }
    queue[rear] = data;
}

int dequeue() {
    int data;

    if (isEmpty()) {
        printf("Queue Underflow\n"); 
        return -1;
    }

    data = queue[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");

    if (rear >= front) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        for (int i = front; i < MAX_SIZE; i++) {
            printf("%d ", queue[i]);
        }
        for (int i = 0; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}