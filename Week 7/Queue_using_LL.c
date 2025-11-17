#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *rear=NULL,*front=NULL;

struct node *insertion(struct node *start){
    struct node *newnode,*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n Enter the data to be inserted:");
    int num;
    scanf("%d",&num);
    newnode->data=num;
    if(start == NULL){
        newnode->next=NULL;
        start=newnode;
    }
    if(rear == NULL){
        rear=start;
        front=start;
    }
    else{
        ptr=start;
        while(ptr->next != NULL)
            ptr=ptr->next;
        ptr->next=newnode;
        newnode->next=NULL;
    }
    return start;
}

struct node *deletion(struct node *start){
    if(front == NULL){
        printf("\n UNDERFLOW");
        return NULL;
    }
    struct node *ptr;
    ptr=start;
    start=start->next;
    front=start;
    free(ptr);
    return start;
}

void display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr != NULL){
        printf("\t%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
    return;
}

int main(){
    int ch;
    while(1){
        printf("\nEnter Choice:\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        if(ch == 1){
            head=insertion(head);
        }
        else if(ch == 2)
            head=deletion(head);
        else if(ch == 3)
            display(head);
        else if (ch == 4)
            break;
        else
            printf("\n INVALID CHOICE");
    }
    printf("\n PROGRAM ENDED");
}
