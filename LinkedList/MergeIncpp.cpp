#include <iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
};
 
class LinkedList
{
private:
Node *first;
public:
LinkedList(){first=NULL;}
LinkedList(int A[],int n);
// ~LinkedList();
void display();
LinkedList * merge(LinkedList *q);
 
};
//function definitions
LinkedList::LinkedList(int A[],int n){
int i=0;
Node *t,*last;
 
first= new Node;
first->data=A[0];
first->next=NULL;
last = first;
 
for(i=1;i<n;i++){
t= new Node;
t->data=A[i];
t->next=NULL;
last->next=t;
last=t;
}
}
LinkedList *LinkedList::merge(LinkedList *qq)
{
Node *p= first;
Node *q=qq->first;
Node *last;
LinkedList *result=new LinkedList;
if(p->data < q->data)
{
result->first=last=p;
p=p->next;
result->first->next=NULL;
}
else
{
result->first=last=q;
q=q->next;
result->first->next=NULL;
}
while(p!=NULL && q!=NULL)
{
if(p->data < q->data)
{
last->next=p;
last=p;
p=p->next;
last->next=NULL;
}
else
{
last->next=q;
last=q;
q=q->next;
last->next=NULL;
}
if(p!=NULL)last->next=p;
if(q!=NULL)last->next=q;
}
return result;
}
void LinkedList::display()
{
Node *temp=first;
while(temp)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}
int main()
{
int A[]={1,2,3,4,5};
int B[]={6,7,8,9,10};
LinkedList l(A,5);
LinkedList l1(B,5);
 
LinkedList *r=l.merge(&l1);
r->display();
return 0;
}
