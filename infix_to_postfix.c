//convert infix expression into post expression
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define STACKSIZE 100
struct stack
{
  int arr[STACKSIZE];
  int top;
};
typedef struct stack STACK;
STACK s;
void push(char);
char pop();
int priority(char);
void main()
{
   char infix[100],postfix[100],c[30],x;
   int i=0,j=0,k=0;
   s.top=-1;
   printf("enter infix expression\n");
   scanf("%s",infix);
   printf("post expression:\t");
   //while(infix[i]!=NULL)//for pointer i can wite it
   for(i=0;i<strlen(infix);i++)
   {
     if(isalnum(infix[i]))
     postfix[j]=infix[i];
     else if(infix[i]=='(')
          push(infix[i]);
          else if(infix[i]==')')
               {
                   while((x=pop())!='(')
                  // postfix[j]=x;

                   if(s.arr[s.top]=='(')
                   c[k++]=pop();
                   else
                   postfix[j]=x;
                }
               else
               {
                 while(priority(s.arr[s.top])>=priority(infix[i]))
                 {
                   if(s.arr[s.top]==infix[i])
                   push(infix[i]);
                   else
                   postfix[j]=pop();
                 }
                 push(infix[i]);
               }
         j++;
    }
    while(s.top==-1)
    {
      if(s.arr[s.top]=='(')
      c[k++]=pop();
      else
      postfix[j++]=pop();
    }
      printf("%s",postfix);
}
void push(char ch)
{
  if(s.top==STACKSIZE-1)
  {
    printf("overflow");
   // return 0;
  }
  else
  s.arr[++s.top]=ch;
}
char pop()
{
  if(s.top==-1)
  {
   printf("underflow");
   return 0;
  }
  else
  return(s.arr[s.top--]);
}
int priority(char t)
{
  if(t=='(')
  return 0;
  else  if(t=='+'||t=='-')
  return 1;
  else if(t=='*'||t=='/'||t=='%')
  return 2;
  else
  return 3;
}

   
