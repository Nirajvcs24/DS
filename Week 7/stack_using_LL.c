#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head=NULL;

struct node *insertion(struct node *start){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int num;
    printf("\n Enter the data:");
    scanf("%d",&num);
    newnode->data=num;
    if(start == NULL){
        start=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=start;
        start=newnode;
    }
    return start;
}

struct node *deletion(struct node *start){
    struct node *ptr;
    if(start == NULL){
        printf("\n Underflow");
        return NULL;
    }
    else if(start->next == NULL){
        printf("\n %d is removed",start->data);
        printf("\n The Linked List is now empty ");
        free(start);
    }
    else{
        ptr=start;
        printf("%d is removed",ptr->data);
        start=start->next;
        free(ptr);
    }
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
