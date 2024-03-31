#include <stdio.h>
void TOH(int n,int A,int B,int C)
{
 if(n>0)
 {
 TOH(n-1,A,C,B);
 printf("(%d,%d)\n",A,C); //print the moves how to move from 1st tower to the 3rd tower
 TOH(n-1,B,A,C);
 }
}
int main()
{
 TOH(4,1,2,3);
 return 0;
}
