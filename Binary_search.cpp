#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) return -1;  // Base case: Key not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) return mid;   // Key found
    return (arr[mid] < key) 
        ? binarySearch(arr, mid + 1, high, key)  // Search right half
        : binarySearch(arr, low, mid - 1, key);  // Search left half
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearch(arr, 0, n - 1, key);
    printf(result == -1 ? "Element not found\n" : "Element found at index %d\n", result);

    return 0;
}

