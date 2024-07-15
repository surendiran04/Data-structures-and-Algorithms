#include <iostream>
using namespace std;
int missingElement(int A[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
    }
    int s=A[n-1]*(A[n-1]+1)/2;
    return s-sum;
}
int main(){
    int A[] = {1,2,3,4,5,6,8};
     int n = sizeof(A)/sizeof(A[0]);  //find array size and pass here ...Don't find size in the fn ....It treats the array as a pointer
    cout<<"Missing element is: "<<missingElement(A,n);
    return 0;
}
