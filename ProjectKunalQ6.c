//Program for Linear Queue's Insertion, deletion and Treaversing /////////

#include <stdio.h>
#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1, rear = -1;
void enqueue(int data);
int dequeue();
void display();

int main()
{
    int choice, data;

    while (1)
    {
        printf("\nMenu...\n");
        printf("1-> Enqueue\n");
        printf("2-> Dequeue\n");
        printf("3-> Display\n");
        printf("4-> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            data = dequeue();
            if (data != -1)
            {
                printf("Dequeued element: %d\n", data);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void enqueue(int data)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    queue[rear] = data;
    printf("Element enqueued: %d\n", data);
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow!\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
    return data;
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
