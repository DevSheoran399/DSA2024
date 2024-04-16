/*Program to sort elements of an array*/

#include <stdio.h>
void bubbleSort(int arr[], int size)
{
    for (int a = 0; a < size - 1; ++a)
    {
        for (int K = 0; K < size - a - 1; ++K)
        {
            if (arr[K] > arr[K + 1])
            {
                int temp = arr[K];
                arr[K] = arr[K + 1];
                arr[K + 1] = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {12, 5, 8, 17, 3, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array before sorting->\n");
    for (int a = 0; a < size; ++a)
    {
        printf("%d ", arr[a]);
    }
    printf("\n");
    bubbleSort(arr, size);
    printf("Array after sorting  ->\n");
    for (int a = 0; a < size; ++a)
    {
        printf("%d ", arr[a]);
    }
    printf("\n");
    return 0;
}
