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
 void Display(struct Node *p)
 {
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
 void RDisplay(struct Node *p)
 {
 if(p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);  //tail recursion
    }
 }
int isLoop(struct Node *f)
 {
    struct Node *p,*q;
    p=q=f;
    
   do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q)
       return 1;
    else
       return 0;
 }
 int main()
 {
     struct Node *temp;
     int A[]={10,20,40,50,60};
    create(A,5);
    RDisplay(first);
    struct Node *t1,*t2;
    t1=first->next->next;
    t2=first->next->next->next->next; //making a loop
    t2->next=t1;
    printf("%d\n",isLoop(first)); 
     return 0;
 }
