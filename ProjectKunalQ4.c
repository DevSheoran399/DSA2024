/*creations, traversing, insertion, deletion in singular LL*/

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
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct Node *head = NULL;
    int input, data, position;

    while (1)
    {
        printf("KUNAL\n B-36\n");
        printf("\n-- Menu --\n");
        printf("1-> Insertion (at the beginning)\n");
        printf("2-> Insertion at the end\n");
        printf("3-> Insertion after/before an element\n");
        printf("4-> Insertion at a particular position\n");
        printf("5-> Deletion at the beginning\n");
        printf("6-> Deletion at the end\n");
        printf("7-> Deletion after/before an element\n");
        printf("8-> Deletion at a particular position\n");
        printf("9-> Traversing\n");
        printf("0-> Exit\n");
        printf("Enter: ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            printf("Exiting...");
            exit(0);
        case 1:
            printf("Enter the value to insert at the beginning-> ");
            scanf("%d", &data);
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            if (newNode == NULL)
            {
                printf("Failed.\n");
                exit(1);
            }
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            printf("Value inserted.\n");
            break;
        case2:
            printf("Enter the value to insert at the end->> ");
            scanf("%d", &data);
            struct Node *endNode = (struct Node *)malloc(sizeof(struct Node));
            if (endNode == NULL)
            {
                printf("Failed.\n");
                exit(1);
            }
            endNode->data = data;
            endNode->next = NULL;
            if (head == NULL)
            {
                head = endNode;
            }
            else
            {
                struct Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = endNode;
            }
            printf("Value inserted.\n");
            break;
        case3:
            //process of insertion around an element
            break;
        case4:
            //  process of insertion at a particular location
            break;
        case5:
            if (head == NULL)
            {
                printf("Linked list is empty..\n");
            }
            else
            {
                struct Node *delHead = head;
                head = head->next;
                free(delHead);
                printf("Node deleted....\n");
            }
            break;
        case6:
            // deletion at the end
            break;
        case7:
            // deletion sround an element
            break;
        case8:
            ///deletion at a particular location
            break;
        case9:
            printf("Linked List-> ");
            traverse(head);
            break;
            printf("Invalid input.....\n");
        }
    }

    return 0;
}
