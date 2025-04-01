#include <stdio.h>

// Function to swap two elements without using pointers
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to partition the array for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the first element as pivot
    int i = low;
    int j = high;
    
    while (i < j) {
        // Find element larger than the pivot from the left
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        
        // Find element smaller than the pivot from the right
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        
        if (i < j) {
            swap(arr, i, j);  // Swap the elements
        }
    }
    
    swap(arr, low, j);  // Swap pivot to the correct position
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);  // Sort the left part
        quickSort(arr, partitionIndex + 1, high); // Sort the right part
    }
}

// Main function
int main() {
    int arr[] = {19, 17, 15, 12, 16, 18, 4, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}

