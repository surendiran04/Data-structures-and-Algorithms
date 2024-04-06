#include <iostream>
// #include<stdlib.h>
using namespace std;

int main()
{
    int *p=new int[5];  // p=(int*)malloc(5*sizeof(int));
    int *q=new int[10]; //a new pointer of extra size is created
    p[0]=6;
    p[1]=7;
    p[2]=8;
    p[3]=9;
    p[4]=10;
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    delete []p;
    for(int i=0;i<10;i++){
        cout<<q[i]<<",";
    }
    return 0;
}
