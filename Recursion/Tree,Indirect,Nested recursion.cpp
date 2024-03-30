#include <iostream>
using namespace std;

void tree(int n){ //recursive call more than once. Time-O(2^n),space - O(n)
if(n>0){
   cout<<n<<endl;
     fun1(n-1);
     fun1(n-1); //it will be executed only after the 1st get's terminated fully
}
}

void funB(int n); //funB needs to defined globally it's called in funA which is before funB
void funA(int n)
{
 if(n>0)
 {
 printf("%d,",n);
 funB(n-1);
 }
}
void funB(int n)
{
 if(n>1)
 {
 printf("%d,",n);
 funA(n/2);
 }
}

int nes(int n){  // a recursive fn which has a  recursive fn as a parameter to a recursive fn
if (n > 100) {
        return n - 10;
}
return nes(nes(n + 11)); 
}

int main()
{
    cout <<"Tree recursion";
    tree(3); //3,2,1,1,2,1,1
   cout <<"Indirect recursion";
   funA(20); //20,19,9,8,4,3,1
   cout <<"Nested recursion";
   nes(95); //91 
}
