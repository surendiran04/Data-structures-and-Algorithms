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
        for(i=0;i<arr.length;i++) //here we access arr.length and arr is not a pointer
            printf("%d ",arr.A[i]);
}
 void Append(struct Array *arr,int x)
 {
        if(arr->length<arr->size)  //here we are using -> beacause the arr is pointer here
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
 void swap(int *x,int *y)
 {
     int temp=*x;
     *x=*y;
     *y=temp;
 }
 void Reverse(struct Array *arr)
 {
    int *B;
    int i,j;
    
    B=(int *)malloc(arr->length*sizeof(int));
    for(i=arr->length-1,j=0;i>=0;i--,j++)
        B[j]=arr->A[i];
    for(i=0;i<arr->length;i++)
        arr->A[i]=B[i];
    
}
 void Reverse2(struct Array *arr)
 {
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        swap(&arr->A[i],&arr->A[j]);
    }
 }
void leftshift(struct Array *arr){  //arr.A={1,2,3,4,5}
     for(int i=0;i<arr->length-1;i++){
         arr->A[i]=arr->A[i+1];
     }
     arr->A[arr->length-1]=0;   //arr.A={2,3,4,5,0}
 }
 void rightshift(struct Array *arr){  //arr.A={1,2,3,4,5}
     for(int i=arr->length;i>0;i--){
         arr->A[i]=arr->A[i-1];
     }
     arr->A[0]=0; //arr.A={0,1,2,3,4}
 }
 void rotate(struct Array *arr){   //arr.A={1,2,3,4,5}
     int x=arr->A[0];
     for(int i=0;i<arr->length-1;i++){
         arr->A[i]=arr->A[i+1];
     }
      arr->A[arr->length-1]=x;  //arr.A={2,3,4,5,1}
 }
 void InsertSort(struct Array *arr, int x)  //inserting or appending elements in a sorted array
{
    int i=arr->length-1;
    if(arr->length==arr->size)
        return;
    while (i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
      }
    arr->A[i+1]=x;
    arr->length++;
}
int isSorted(struct Array arr) //checking an array is sorted or not
 {
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
 }
 struct Array* Merge(struct Array *arr1,struct Array *arr2) //merging two arrays into a new array in a sorted order
 {
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
            if(arr1->A[i]<arr2->A[j])
                arr3->A[k++]=arr1->A[i++];
            else
                arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=arr1->length+arr2->length;
    arr3->size=10;
    
    return arr3;
 }
struct Array* Union(struct Array *arr1,struct Array *arr2)  //similiar to merge fn
 {
    int i,j,k;
    i=j=k=0;
    
struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    
    arr3->length=k;
    arr3->size=10;
    
    return arr3;
}
 struct Array* Intersection(struct Array *arr1,struct Array 
*arr2)
 {
    int i,j,k;
    i=j=k=0;
    
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));
    
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;  
    return arr3;
 }
 struct Array* Difference(struct Array *arr1,struct Array *arr2)
 {
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array)); 
    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
 for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=10;
 return arr3;
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
    // struct Array arr2={{2,3,16,18,28},10,5};
    // struct Array *arr3; 
    // arr3=Merge(&arr1,&arr2);
    Display(arr1);
    free(arr1.A);
    return 0;
 }
 //same in c++ using template class
#include <iostream>
 using namespace std;
 template<class T>
 class Array
 {
 private:
    T *A;
    int size;
    int length;
 public:
    Array()
    {
        size=10;
        A=new T[10];
        length=0;
    }
    Array(int sz)
    {
        size=sz;
        length=0;
        A=new T[size];
    }
    ~Array()
    {
        delete []A;
    }
    void Display();
    void Insert(int index,T x);
    T Delete(int index);
 };
 template<class T>
 void Array<T>::Display()
 {
    for(int i=0;i<length;i++)
        cout<<A[i]<<" ";
    cout<<endl;
 }
 template<class T>
 void Array<T>::Insert(int index,T x)
 {
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>=index;i--)
A[i+1]=A[i];
 A[index]=x;
 length++;
    }
 }
 template<class T>
 T Array<T>::Delete(int index)
 {
    T x=0;
 if(index>=0 && index<length)
    {
        x=A[index];
 for(int i=index;i<length-1;i++)
 A[i]=A[i+1];
 length--;
    }
 return x;
 }
 int main()
 {
 Array<char> arr(10);
    arr.Insert(0,'a');
    arr.Insert(1,'c');
    arr.Insert(2,'d');
    arr.Display();
 cout<<arr.Delete(0)<<endl;
    arr.Display();
 return 0;
 }
