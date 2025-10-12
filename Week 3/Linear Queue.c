#include<stdio.h>
#define SIZE 5
int q[SIZE],front=0,rear=-1;
void enqueue(int n1)
{
    if(rear==SIZE-1)
    {
        printf("Queue is full");
        return;
    }
    rear+=1;
    q[rear]=n1;
}
void dequeue()
{
    if(front == -1 || front>rear)
    {
        printf("\n Queue is empty");
        return;
    }
    printf("\n Removed element is %d",q[front]);
    front+=1;
}
void display()
{
    int k;
    if(front==-1 || front>rear)
    {
        printf("Queue is empty");
        return;
    }
    printf("\n The Queue Elements are:\n");
    for(k=front;k<rear+1;k++)
    {
        printf("%d \t",q[k]);

    }
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

