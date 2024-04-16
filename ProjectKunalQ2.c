/*Program to perform search an array using Linear and binary*/   // ----------google



#include <stdio.h>
int arr[], n, key;
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binary_search(int arr[], int low, int high, int key) {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == key)
            return mid;
        
        if (arr[mid] > key)
            return binary_search(arr, low, mid - 1, key);
        
        return binary_search(arr, mid + 1, high, key);
    }
    
    return -1;
}

int main() {
    int arr[] = {3,6,9,12,15,18,21};

    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int linear_result = linear_search(arr, n, key);
    if (linear_result != -1)
        printf("Element %d found at index %d using linear search.\n", key, linear_result);
    else
        printf("Element %d not found in linear search.\n", key);

    int binary_result = binary_search(arr, 0, n - 1, key);
    if (binary_result != -1)
        printf("Element %d found at index %d using binary search.\n", key, binary_result);
    else
        printf("Element %d not found in binary search.\n", key);

    return 0;
}
