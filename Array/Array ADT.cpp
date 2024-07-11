// • Array ADT (Abstract Data Type) 
// • The representation of data is define by the compiler itself , However 
// the operations on the data must be given by the program . The 
// combination of theses 2 on an array is called Array ADT
//  • Some possible operations on array are :
//  Display( )
//  Add( x ) / Append( x )
//  Insert( index , x )
//  Delete( index )
//  Search( x )
//  Get( index )
//  Set( index , x )
//  Max( ) / Min( )
//  Reverse( )
//  Shift( ) / Rotate()


#include <iostream>
using namespace std;
class Array{

private:
    int* A; //if these attributes are in public then we can easily access these one's in the main fn itself
    int size;
    int length;
 
public:
    Array(int size){ 
        this->size = size;
        A = new int [size];
    }
    void create(){
        cout << "Enter number of elements: " << flush;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++){
            cout << "Array element: " << i << " = " << flush;
            cin >> A[i];
        }
    }
    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
    }
 
    ~Array(){  //destructor - It deletes the dynamically allocated array A to prevent memory leaks. 
      // You don’t need to explicitly call the destructor; it happens automatically.
      // When an Array object goes out of scope (e.g., when the main function ends), the destructor is invoked.
      // The destructor ensures that the memory allocated with new (in the constructor) is properly deallocated (using delete[]).
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main() {
    Array arr(10);
    arr.create();
    arr.display();
    return 0;
}

//same implementation in c language
#include<stdio.h>
#include<stdlib.h>
 struct Array
 {
    // int A[10]; - static array
    int *A;  //int *A - allocate dynamic space in main memory as well by getting arr.size and arr.A = (int*)malloc(arr.size*sizeof(int));
    int size;
    int length;
 };
void Display(struct Array arr)
{
        int i;
        printf("\nElements are\n");
        for(i=0;i<arr.length;i++)
            printf("%d ",arr.A[i]);
}
 void Append(struct Array *arr,int x)
 {
        if(arr->length<arr->size)
            arr->A[arr->length++]=x;
}
void Insert(struct Array *arr,int index,int x)
{
    int i; 
    if(index>=0 && index <=arr->length)
    {
        for(i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }
}
 int Delete(struct Array *arr,int index)
 {
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return 0;
 }
 int main()
 {
     struct Array arr1;
     arr1.size=10;
     arr1.A=(int *)malloc(arr1.size*(sizeof(int)));
     arr1.length=5;
     for (int i = 0; i < arr1.length; ++i)
    {
        arr1.A[i] = i + 2; // Assign values 2, 3, 4, 5, 6
    }
     // struct Array arr1={{2,3,4,5,6},10,5};  //{A,size,length}
    Insert(&arr1,0,1);
    Append(&arr1,7);
    printf("%d",Delete(&arr1,0));
    Display(arr1);
    free(arr1.A);
    return 0;
 }
 
