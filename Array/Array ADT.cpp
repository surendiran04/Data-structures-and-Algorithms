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
struct Array{
int A[20]; //int *A - allocate dynamic space in main memory as well by getting arr.size and arr.A = (int*)malloc(arr.size*sizeof(int));
int size;
int length;
};
void Display(struct Array arr)
{
int i;
printf("\nElements are\n");
for(i=0;i<arr.length; i++)
printf("%d ", arr.A[i]);
}
int main()
{
struct Array arr={{2,3,4,5,6},20,5}; //{A,size,length}
Display(arr); 
return 0;
}
