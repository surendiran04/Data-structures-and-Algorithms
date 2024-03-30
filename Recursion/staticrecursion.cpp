#include <iostream>
using namespace std;

int fun1(int n){
if(n>0){
    return fun1(n-1)+n;  //normal recursion code
}
return 0;
}

int fun2(int n){
   static int x=0;       //which is equal to declare x globally
if(n>0){
        x++;
        // cout<<x<<endl;
    return fun2(n-1)+x;
}
return 0;
}

int main()
{
    int a=5;
    cout <<"ans:1 - "<<fun2(a)<<endl; //25
    cout <<"ans:2 - "<<fun2(a);  //50    //this fn call keep on increamenting the value of x from where the last fn call left
    return 0;
}
