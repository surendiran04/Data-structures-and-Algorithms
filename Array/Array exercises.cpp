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

//Finding missing elements even if the array is not  sorted
#include <iostream>
#include <algorithm>
using namespace std;
void missingMultipleElement(int A[],int n){
    int l=*min_element(A, A + n); //included in algorithm
    int h=*max_element(A, A + n);
    int H[h] = {0} ;  // fill(H, H+h, 0);  similiar to vector<int> arr(n, 0); 
     for(int i=0;i<n;i++){
         H[A[i]]++;
     }
    for(int i=l;i<=h;i++){
        if(H[i]==0){
            cout<<i<<endl;
        }
    }
}
int main(){
    int A[] = {3,1,5,8};
     int n = sizeof(A)/sizeof(A[0]);
    cout<<"Missing elements are:"<<endl;
    missingMultipleElement(A,n);
    return 0;
}

//finding duplicates in a sorted array
#include <iostream>
using namespace std;
void DulpicateElements(int A[],int n){
    int lastDuplicate=0;
    for(int i=0;i<n-1;i++){
        if(A[i]==A[i+1] && A[i]!=lastDuplicate){
            cout<<A[i]<<endl;
            lastDuplicate=A[i];
        }
    }
}
int main(){
    int A[] = {3,6,8,8,10,12,15,15,15,20};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Duplicate elements are:"<<endl;
    DulpicateElements(A,n);
    return 0;
}

//duplicate elements and its frequency
#include <iostream>
using namespace std;
void DulpicateElementsTimes(int A[],int n){
    int j=0;
    for(int i=0;i<n-1;i++){
        if(A[i]==A[i+1]){
            j=i+1;
            while(A[j]==A[i]) j++;
            cout<<A[i]<<" is appearing "<<j-i<<" times"<<endl;
            i=j-1;
        }
    }
}
int main(){
    int A[] = {3,6,8,8,10,12,15,15,15,20};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Duplicate elements are:"<<endl;
    DulpicateElementsTimes(A,n);
    return 0;
}

//fining duplicates elements via hash table
#include <iostream>
#include <algorithm>
using namespace std;
void DulpicateElement(int A[],int n){
    int h=*max_element(A, A + n);
    int H[h+1] = {0} ;   
     for(int i=0;i<n;i++){
         H[A[i]]++;
     }
    for(int i=0;i<=h;i++){
        if(H[i]>1){
            cout<<i<<" has appeared "<<H[i]<<" times"<<endl;
        }
    }
}
int main(){
    int A[] = {3,6,8,8,10,12,15,15,15,20};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<"Duplicate elements are:"<<endl;
    DulpicateElement(A,n);
    return 0;
}
