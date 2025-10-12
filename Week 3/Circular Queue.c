#include<stdio.h>
#define SIZE 5
int q[SIZE],front=-1,rear=-1;
void enqueue(int n1)
{
    if(front == 0 && rear==SIZE-1 || (rear+1)%SIZE==front)
    {
        printf("\n Queue is full");
        return;
    }
    if(front==-1)
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%SIZE;
    }
    q[rear]=n1;

}
void dequeue()
{
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    else if(front == rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        printf("\n Removed element=%d",q[front]);
        front=(front+1)%SIZE;
    }
}
void display()
{
    int i;
    if(front==-1)
    {
        printf("Queue is empty");
        return;
    }
    for(i=front;i!=rear;i=(i+1)%SIZE)
    {
        printf("%d\t",q[i]);
    }
    printf("%d",q[i]);
    printf("\n");
}
int main()
{
    int num,op;
    while(1)
    {
        printf("\nSelect Option:\n1)Insert\n2)delete\n3)display\n4)exit\n");
        scanf("%d",&op);
        if(op==1)
        {
            printf("\n Enter number to be inserted:");
            scanf("%d",&num);
            enqueue(num);
        }
        else if(op==2)
        {
            dequeue();
        }
        else if(op==3)
        {
            display();
        }
        else if(op==4)
        {
            break;
        }
        else
            printf("\n INVALID OPERATION");
    }
    printf("\n PROGRAM ENDED");
    return 0;
    }
