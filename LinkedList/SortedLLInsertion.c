#include <stdio.h>
#include <stdlib.h>
 struct Node
 {
    int data;
    struct Node *next;
 }*first=NULL,*second=NULL,*third=NULL;
 void Display(struct Node *p)
 {
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
 }
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
 void SortedInsert(struct Node *p,int x)
 {
    struct Node *t,*q=NULL;
    t=(struct Node*)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;
    
    if(first==NULL) //if thereare no nodes
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)  //if inserting the new node b4 1st Node
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}
 int count(struct Node *p){
     int c=0;
     if(p==NULL)
       return c;
    while(p){
        c++;
        p=p->next;
    }
    return c;
 }
 int Delete(struct Node *p,int index)
 {
    struct Node *q=NULL;
    int x=-1,i;
    if(index < 1 || index > count(p) ){
          return x;
    }
    if(index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }
    else
    {
        for(i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
 }
 int main()
 {
    int A[]={10,20,30,40,50};
    create(A,5);
    SortedInsert(first,15);
    Display(first);
   printf("Deleted element: %d",Delete(first,2)); 
    return 0;
 }
