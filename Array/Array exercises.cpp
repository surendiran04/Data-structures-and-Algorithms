//To find missing elements starting from 1 to n
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

//To find in bw missing elements in array 
#include <iostream>
using namespace std;
int missingInBwElement(int A[],int n){
    int diff=A[0]-0;
    for(int i=0;i<n;i++){
        if(A[i]-i!=diff){
            return i+diff;
        }
    }
    return -1;
}
int main(){
    int A[] = {6,7,8,9,10,11,13,14};
     int n = sizeof(A)/sizeof(A[0]);
    cout<<"Missing element is: "<<missingInBwElement(A,n);
    return 0;
}

//Finding multiple missing elements in an array
#include <iostream>
using namespace std;
void missingMultipleElement(int A[],int n){
    int diff=A[0]-0;
    for(int i=0;i<n;i++){
        if(A[i]-i!=diff){
            while(diff<A[i]-i){
              cout<<i+diff<<endl;
              diff++;   
            }
        }
    }
}
int main(){
    int A[] = {6,7,8,9,11,14};
     int n = sizeof(A)/sizeof(A[0]);
    cout<<"Missing elements are:\n ";
    missingMultipleElement(A,n);
    return 0;
}
