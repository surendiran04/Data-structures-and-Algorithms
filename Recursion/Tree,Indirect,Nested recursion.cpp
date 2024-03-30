#include <iostream>
using namespace std;

void tree(int n){ //recursive call more than once. Time-O(2^n),space - O(n)
if(n>0){
   cout<<n<<endl;
     fun1(n-1);
     fun1(n-1); //it will be executed only after the 1st get's terminated fully
}
}
int main()
{
    cout <<"Tree recursion";
    tree(3); //3,2,1,1,2,1,1
}
