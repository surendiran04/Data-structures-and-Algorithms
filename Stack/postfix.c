#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define MAX 100
char stack[MAX]; //it stores all the operators
char infix[MAX],postfix[MAX];
int top=-1;
int precedence(char symbol)
{
    switch(symbol){
    case '^':
        return 3;
    case '/':
    case '*':
         return 2;
    case '+':
    case '-':
         return 1;
    default:
       return 0;
     }
}
int space(char c)
{
    if(c==' ' || c=='\t')
        return 1;
    else
        return 0;
}
void push(char c)
{
    if(top== MAX - 1){
        printf("stack is full!");
        return;
    }
    else{
        top+=1;
        stack[top]=c;
    }
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
char pop(){
   char c=stack[top];
   top-=1;
   return c;
}
void intopost()
{
    int i,j=0;
    char symbol,next;
    for(i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        switch(symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while((next=pop())!='(') //pops until left paranthesis and pushes the number in-between to postfix array
                    postfix[j++]=next;
            break;
        case '^':
        case '/':
        case '*':
        case '+':
        case '-':
            while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
                postfix[j++]=pop();
                
            }
                push(symbol);
                break;
        default:
            postfix[j++]=symbol;
        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}
int post_eval()
{
   int i,a,b;
   for(i=0;i<strlen(postfix);i++){
    if(postfix[i]>='0' && postfix[i]<='9'){
        push(postfix[i] - '0'); //changes the string to number
    }
    else{
        a=pop();
        b=pop();
    switch(postfix[i]){
    case '+':
        push(b+a);
        break;
    case '-':
        push(b-a);
        break;
    case '*':
        push(b*a);
        break;
    case '/':
        push(b/a);
        break;
    case '^':
        push(pow(b,a));
        break;
     }
    }
   }
   return pop(); //final result
}
int main()
{
    int result;
    printf("enter the infix expression: ");
    gets(infix);
    intopost();
    result=post_eval();
    printf("Equivalent postfix expression:%s",postfix);
    printf("\n%d",result);
}
