#include <iostream>
using namespace std;
 //collections of items of same data type stored in contigous memory locations
int main()
{
    int A[]={1,2,3,4,5};  //A[5]={1,2,3,4,5} ,A[5]={0} ,A[5]={1,2}
    for(int i=0;i<sizeof(A)/sizeof(A[0]);i++){
        printf("%d\n",*(A+i)); // printf("%d\n",i[A]);  printf("%d\n",A[i]);
    }
    return 0;
}

//printf("%u\n",(A+i)); - print the address of the locations
