//What is the return value of f(p, p), if the value of p is initialised to 5 before the call? Note that the first parameter is passed by
//reference, whereas the second parameter is passed by value. 

int f (int &x, int c) 
{
  c = c — 1; 
if (c = = 0) return 1; 
x = x + 1; 
return f(x,c) * x;
}
//In this case,it is tail recursion and at the time of termination of all the cases then then x will be 9 so the ans:6561 9*9*9*9


int f(int n)
{
static int i = 1
if (n>=5)return n;
n = n+i;
i++;
return f(n);
}
//the value returned by f(1) ans is 7 ,static int keeps on increasing 


void foo (int n, int sum)
{
int k = 0, j = 0;
if (n = = 0) return;
k = n % 10;
j = n/10;
sum = sum + k;
foo (j, sum);
printf(“%d”, k)
}
int main ()
{
int a = 2048, sum = 0;
foo (a, sum);
printf(“%d\n”, sum);
}
//What does the above program print? ans: 2 0 4 8 0  It is head recursion so the ans will reversed from 8 4 0 2


int fun (int n)
{ 
int x=1, k; 
if (n==1) return x; 
for (k=1; k<n; ++k) 
x=x + fun (k) * fun (n — k); 
return x; 
}
//The return value of fun (5) ans is 51 


void count(int n) 
{
  static int d = 1; 
printf("%d", n); 
printf("%d", d); 
d++; 
if (n > 1) count (n-1); 
printf("%d", d);
} 
void main( ) 
{
  count (3);
} 
//ans is 3 1 2 2 1 3 4 4 4







