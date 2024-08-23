//quicksort - sorts by picking 1 element as pivot(whether it may be any element in the array) and partitions the given array 
//around the picked pivot element.Then sorts the dived arrays by the same procedure.

// best and avg time complexity - O(nlogn) ,worst case - O(n^2) if(pivot is chosen poorly)
//suited for large amount of data,uses low amount of memory

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);  //knows how much elements are patitally sorted until
    
    for (int j = low; j <= high; j++) {
        if (arr[j] < pivot) {  //the elements which are lesser than pivot are stored in the starting index of the array
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); //returns the portion of the pivot
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); //sorting the left portion of the array
        quickSort(arr, pi + 1, high); //sorting the right portion of the array
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
