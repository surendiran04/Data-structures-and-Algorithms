#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int partition(int arr[], int l, int h) {
    int pivot = arr[l];
    int i = l,j=h;  
    
   while(i<j){
       while(arr[i]<=pivot && i<=h-1){
           i++;
       }
       while(arr[j]>pivot && j>=l+1){
           j--;
       }
       if(i<j){
           swap(arr[i],arr[j]);
       }
       
   }
    
    swap(arr[l], arr[j]);
    return j; //returns the portion of the pivot
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1); //sorting the left portion of the array
        quickSort(arr, pi + 1, high); //sorting the right portion of the array
    }
}

int main() {
    int arr[] = {2,10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
