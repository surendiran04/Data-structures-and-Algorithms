#include <stdio.h>
 #include <stdlib.h>
 struct Node
 {
    int data;
    struct Node *next;
 }*first=NULL;
 void create(int A[],int n)
 {
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
 }
int count(struct Node *p)
 {
    int l=0;
    while(p)
    {
        l++;
        p=p->next;
    }
    return l;
 }
 int Rcount(struct Node *p)
 {
    if(p!=NULL)
        return Rcount(p->next)+1;
    else
        return 0;
} 
int sum(struct Node *p)
 {
    int s=0;
    
    while(p!=NULL)
    {
        s+=p->data;
        p=p->next;
    }
    return s;
 }
 int Rsum(struct Node *p)
 {
    if(p==NULL)
        return 0;
    else
        return Rsum(p->next)+p->data;
 }
 int Max(struct Node *p)
 {
    int max=-999;
    
    while(p)
    {
        if(p->data>max)
            max=p->data;
        p=p->next;
    }
    return max;
    
}
 int RMax(struct Node *p)
 {
    int x=0;
    if(p==0)
       return -10^6;
    x=RMax(p->next);
    return x>p->data?x:p->data;
 }
 int main()
 {
 struct Node *temp;
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);
 printf("Length of the Nodes: %d\n",Rcount(first));
 printf("Sum of the Nodes: %d",Rsum(first));
 printf("Max Node: %d\n",RMax(first));
 return 0;
 }
