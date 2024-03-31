#include <stdio.h>

int fib(int n)   //time - O(n)
{
 int t0=0,t1=1,s=0,i;
 
 if(n<=1) return n;
 for(i=2;i<=n;i++)
 {
 s=t0+t1;
 t0=t1;
 t1=s;
 }
 
 return s;
}

int rfib(int n) //time - O(2^n)
{
 if(n<=1)return n;
 return rfib(n-2)+rfib(n-1);
}

int F[10]; //can of size n

int mfib(int n) //memoization - caching the previous calls to avoid unwanted calls
{
 if(n<=1)             //time - O(n)
 {
 F[n]=n;
 return n;
 }
 else
 {
 if(F[n-2]==-1)
 F[n-2]=mfib(n-2);
 if(F[n-1]==-1)
 F[n-1]=mfib(n-1);
 F[n]=F[n-2]+F[n-1];
 return F[n-2]+F[n-1];
 }
}

int main()
{
 int i;
 for(i=0;i<10;i++)
 F[i]=-1;
 
 printf("%d \n",mfib(5));
 return 0;
}
