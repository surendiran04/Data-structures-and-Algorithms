#include <iostream>
using namespace std;

double e(int x,int n){    // Time-O(n)
  static double p=1,f=1;
  double r;
  if(n==0){
    return 1;
  }
  r=e(x,n-1);
  p=x*p;
  f=n*f;
  return r+p/f;

}

double e1(int x,int n){   //slightly optimised Taylor series Honer's rule                                            )
  static double s=1;
  if(n==0){                // Time-O(n
    return s;
  }
  s=1+x*s/n;
  return e1(x,n-1);

}

int main()
{
    cout <<"ans: - "<<e(1,10); //2.718
    return 0;
}
