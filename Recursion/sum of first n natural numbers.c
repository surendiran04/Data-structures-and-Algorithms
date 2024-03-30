#include<stdio.h>
int sum(int n)  // Time - O(n) space - O(n)
{
 if(n==0)
 return 0;
 return sum(n-1)+n;
}
int formulaSum(int n){ // Time - O(1) space - O(1)
  return n*(n+1)/2;
}
int Isum(int n) // Time - O(n) space - O(1)
{
 int s=0,i; 
 for(i=1;i<=n;i++) 
 s=s+i;
 
 return s; //15
}
int main()
{
 int r=sum(5); //15
 printf("%d ",r);
 return 0;
}
