#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int top;
    int size;
    int *arr;
};
void push(struct stack *sp,int data)
{
  if(sp->top==sp->size-1)
  {
   printf("stack is overflow");
  }
  else
  {
    sp->top++;
    sp->arr[sp->top]=data;
  }
}
int pop(struct stack *sp)
{
  int val;
  if(sp->top==-1){
  printf("underflow");
  return -1;}
  val=sp->arr[sp->top];
  sp->top--;
  return val;
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp,1);
    push(sp,2);
    push(sp,4);
    push(sp,0);
    push(sp,6);
    for(int i=0;i<6;i++)
    printf("%d ",pop(sp));
}