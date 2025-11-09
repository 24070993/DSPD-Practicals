#include <stdio.h>
#include <stdlib.h>


int binarySearch(int *arr, int n, int key) {
    if (arr == NULL || n == 0) {
        return -1;  
    }

    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        printf("Examining middle value: %d\n", arr[mid]);

        if (arr[mid] == key) {
            return 1; // found
        }
        else if (arr[mid] < key) {
            printf("Key is greater than middle, adjusting start to index %d\n", mid + 1);
            start = mid + 1;
        }
        else {
            printf("Key is less than middle, adjusting end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }
    return 0; 
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result == 1)
        printf("Element %d found!\n", key);
    else if (result == 0)
        printf("Element %d not found.\n", key);
    else
        printf("Invalid input (NULL array or empty list).\n");
return 0;
}

