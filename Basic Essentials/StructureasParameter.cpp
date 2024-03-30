#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct rectangle{
int length;
int breadth;
};
int area(struct rectangle r1){
return r1.length*r1.breadth;
}
//here we can change the length by address and reference
void fun(struct rectangle *r){
    r->length=20;
cout<<r->length<<endl<<r->breadth<<endl;
}
int main(){
struct rectangle r={10,5};
printf("%d\n",area(r));

fun(&r);//for pointer we have to pass address
printf("length:%d breadth:%d",r.length,r.breadth);

return 0;
}
