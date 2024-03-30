//Array as parameter to a function

#include <iostream>
using namespace std;

void func(int *A,int n){
for(int i=0;i<5;i++){
    printf("%d\n",A[i]);
}
}

int *arr(int size){ //returning pointer
int *ptr;
ptr=new int[size]; //creating memory
for(int i=0;i<size;i++)
    ptr[i]=i+2;

 return ptr;
}

int main()
{
    int n=5;
    int A[n]={1,2,3,4,5};
    func(A,n); //1,2,3,4,5

    //Function returning  array
    int *p;
    p=arr(5);
    for(int i=0;i<5;i++){
        cout<<p[i]<<endl; //2,3,4,5,6
    }
    return 0;
}

