//Merge Sort - a recursive algorithm which divides the array into 2 halves until it cannot be futher divided (ie,the array has only one element)
//It is well-suited for large data sets and it has a time-complexity of O(nlogn)
//The main disadvantage is it requires large memory space(more space complexity)
#include<stdio.h>
void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    //copying the array in temp arrays
    for(i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(j=0;j<n1;j++){
        R[j]=arr[m+1+j];
    }
    i=0,j=0,k=l;
    //copying the temp aray into original array
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    //copying the remaining elements
    while(i<n1){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=R[j];
        k++;
        j++;
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l) /2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);    
    }
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    mergesort(arr, 0, n-1);
    
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
