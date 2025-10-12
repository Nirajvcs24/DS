#include<stdio.h>
#define SIZE 5
int top=-1,num;
int stack[SIZE];
void push()
{
    if(top==SIZE-1)
    {
        printf("\n Stack Overflow \n");
    }
    else{
        printf("\n Enter number:");
        scanf("%d",&num);
        top++;
        stack[top]=num;
    }
}
void pop()
{
    if(top==-1)
        printf("\n Stack Underflow \n");
    else
    {
        printf("\n Removed element=%d \n",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1){
        printf("\n The stack is empty");
        return;
    }
    printf("\n The Stack Elements are:");
    for(int i=top;i>-1;i--)
    {
        printf("\n %d",stack[i]);
    }
}
int main()
{
    int op;
    while(1){
        printf("\n Operations:\n 1.Push\n 2.Pop\n 3.Display\n 4.Exit \n");
        scanf("%d",&op);
        if(op==1){
            push();
        }
        else if(op==2)
        {
            pop();
        }
        else if(op==3){
            display();
        }
        else if(op==4){
            break;
        }
        else
        {
            printf("\n INVALID OPERATION");
        }
    }
    printf("\n PROGRAM ENDED");
    return 0;
}
