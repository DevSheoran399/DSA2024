/*creations, traversing, insertion, deletion in circular LL*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};


void traverse(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Circular Linked List is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
int main()
{
    struct Node *head = NULL;
    struct Node *last = NULL;
    int choice, value, position;
    while (1)
    {
        printf("Menu\n");
        printf("1. Create/Insert (at the beginning)\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after/before an element\n");
        printf("4. Insert at a particular position\n");
        printf("5. Delete at the beginning\n");
        printf("6. Delete at the end\n");
        printf("7. Delete after/before an element\n");
        printf("8. Delete at a particular position\n");
        printf("9. Traverse\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Exiting...");
            exit(0);
        case 1:
            printf("Enter the value to insert at the beginning->");
            scanf("%d", &value);
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->data = value;
            if (head == NULL)
            {
                head = newNode;
                newNode->next = newNode;
                last = newNode;
            }
            else
            {
                newNode->next = head;
                last->next = newNode;
                head = newNode;
            }
            printf("Value inserted..\n");
            break;
        case2:
            printf("Enter the value to insert at the end-> ");
            scanf("%d", &value);
            struct Node *lastNode = (struct Node *)malloc(sizeof(struct Node));
            lastNode->data = value;
            if (head == NULL)
            {
                head = lastNode;
                lastNode->next = lastNode;
                last = lastNode;
            }
            else
            {
                lastNode->next = head;
                last->next = lastNode;
                last = lastNode;
            }
            printf("Value inserted...\n");
            break;
        case3:
            // insertion around an element
            break;
        case4:
            // insertion at a particular position
            break;
        case5:
            if (head == NULL)
            {
                printf("Circular Linked List is empty.\n");
            }
            else if (head->next == head)
            {
                free(head);
                head = NULL;
                last = NULL;
            }
            else
            {
                struct Node *temp = head;
                head = head->next;
                last->next = head;
                free(temp);
            }
            printf("Node deleted from the beginning..\n");
            break;
        case6:
            // deletion at the end
            break;
        case7:
            // deletion around an element
            break;
        case8:
            //  proces ofdeletion at a particular locaton
            break;
        case9:
            traverse(head);
            break;

            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
