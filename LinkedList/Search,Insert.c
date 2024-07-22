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
 struct Node * LSearch(struct Node *p,int key)
 {
    struct Node *q;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
    
}
 struct Node * RSearch(struct Node *p,int key)
 {
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next,key);
    
}
 int count(struct Node* p){
     if(p==0)
       return 0;
     return count(p->next)+1; 
 }
  void Display(struct Node *p)
 {
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
 void Insert(struct Node *p,int index,int x)
 {
    struct Node *t;
    int i;
    if(index < 0 || index > count(p))  //here we are using count fn
        return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    
    if(index == 0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
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
 int main()
 {
 struct Node *temp;
 int A[]={3,5,7,10,25,8,32,2};
 create(A,8);
 Insert(first,1,0);
 Display(first);
 struct Node*t=RSearch(first,25);
 if(t)
    printf("key is found");
 else
    printf("Key not found");

return 0;
 }
