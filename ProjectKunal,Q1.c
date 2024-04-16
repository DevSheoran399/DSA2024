/* Program for Array creation, Array traversing, Array insertion, Array Deletion */

#include <stdio.h>

#define MAX_SIZE 25

int size = 0, array[MAX_SIZE];


void traverse()
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    int input, data, position;
    printf("Ola ----------- \n");
    while (1)
    {
        printf("\n Menu -> \n");
        printf("1 -> Create/Insert (at the beginning)\n");
        printf("2-> insert at the end\n");
        printf("3-> insert after/before an element\n");
        printf("4-> Insert at a particular position\n");
        printf("5-> Delete at the beginning\n");
        printf("6-> delete at the end\n");
        printf("7-> delete after/before an element\n");
        printf("8-> Delete at a particular position\n");
        printf("9-> Traverse\n");
        printf("0-> Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
            printf("Exiting the program......\n");
            return 0;
        case 1:
            printf("Enter the value to insert at the beginning-? ");
            scanf("%d", &data);
            for (int i = size; i >= 1; i--)
            {
                array[i] = array[i - 1];
            }
            array[0] = data;
            size++;
            printf("Value inserted successfully...\n");
            break;
        case 2:
            printf("Enter the value to insert at the end-> ");
            scanf("%d", &data);
            array[size++] = data;
            printf("Value inserted successfully\n");
            break;
        case 3:
            printf("Enter the value to insert-> ");
            scanf("%d", &data);
            printf("Enter the element after which you want to insert-> ");
            scanf("%d", &position);
            for (int i = 0; i < size; i++)
            {
                if (array[i] == position)
                {
                    for (int j = size; j > i + 1; j--)
                    {
                        array[j] = array[j - 1];
                    }
                    array[i + 1] = data;
                    size++;
                    printf("Value inserted successfully.\n");
                    break;
                }
            }
            break;
        case 4:
            printf("Enter the value to insert-> ");
            scanf("%d", &data);
            printf("Enter the position at which you want to insert-> ");
            scanf("%d", &position);
            for (int i = size; i > position; i--)
            {
                array[i] = array[i - 1];
            }
            array[position] = data;
            size++;
            printf("Value inserted.\n");
            break;
        case 5:
            if (size == 0)
            {
                printf("Array is empty.\n");
            }
            else
            {
                for (int i = 0; i < size - 1; i++)
                {
                    array[i] = array[i + 1];
                }
                size--;
                printf("Value deleted from the beginning.\n");
            }
            break;
        case 6:
            if (size == 0)
            {
                printf("Array is empty.\n");
            }
            else
            {
                size--;
                printf("Value deleted from the end.\n");
            }
            break;
        case 7:
            printf("Enter the element after which you want to delete-> ");
            scanf("%d", &position);
            for (int i = 0; i < size; i++)
            {
                if (array[i] == position)
                {
                    for (int j = i + 1; j < size; j++)
                    {
                        array[j - 1] = array[j];
                    }
                    size--;
                    printf("Value deleted.\n");
                    break;
                }
            }
            break;
        case 8:
            printf("Enter the position at which you want to delete-> ");
            scanf("%d", &position);
            for (int i = position; i < size - 1; i++)
            {
                array[i] = array[i + 1];
            }
            size--;
            printf("Value deleted.\n");
            break;
        case 9:
            traverse();
            break;
        default:
            printf("Invalid input");
        }
    }
    return 0;
}
