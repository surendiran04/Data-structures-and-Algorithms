#include <iostream>    //both fn takes time - O(n) , space - O(n)
using namespace std;

int head(int n){
if(n>0){
   fun1(n-1);  //fn is called initially then printing is done at retuning time
   cout<<n<<endl;  
}
return 0;
}

int tail(int n){
if(n>0){
  cout<<n<<endl; //printed then the fn is called nothing performed at returning time instead it is done at calling time
  fun1(n-1);
}
return 0;
}

int main()
{
    int a=5;
    cout <<"ans:1 - "<<tail(a)<<endl;  //5,4,3,2,1
    cout <<"ans:2 - "<<head(a);        //1,2,3,4,5
    return 0;
}

//same process using loop   time - O(n) , space - O(1)
void head_loop(int n){
    int i=1;
  while(i<=n){
    printf("%d\n",i);
    i++;
  }
}
void tail_loop(int n){
  while(n>0){
    printf("%d\n",n);
    n--;
  }
}
