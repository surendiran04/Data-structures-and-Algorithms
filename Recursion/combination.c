#include <stdio.h> 

int fact(int n)
{
 if(n==0)return 1;
 return fact(n-1)*n;
}

int nCr(int n,int r) //ncr = n!/(r!*(n-r)!;
{
 int num,den;
 
 num=fact(n);
 den=fact(r)*fact(n-r);
 
 return num/den;
}

int NCR(int n,int r) //pascal's triangle approach
{
 if(n==r || r==0)
 return 1;
 return NCR(n-1,r-1)+NCR(n-1,r);
 
}
int main()
{
 printf("%d \n",NCR(5,3));
 return 0
