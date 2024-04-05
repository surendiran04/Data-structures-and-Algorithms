#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{ 
    // A[5] - static stack memory
    // int n; 
    // cin>>n;
    // int A[n]; - dynamic stack memory
    
    int A[5]={1,2,3,4,5};
    for(int i=0;i<5;i++){
        cout<<A[i]<<",";
    }
    cout<<endl;
    int *p;
    p=(int*)malloc(5*sizeof(int)); //head memory
    //p=new int[5];
    p[0]=6;
    p[1]=7;
    p[2]=8;
    p[3]=9;
    p[4]=10;
    for(int i=0;i<5;i++){
        cout<<p[i]<<",";
    }
    free(p); - deleting the heap memory after usage 
    //delete []p;    
    return 0;
}
