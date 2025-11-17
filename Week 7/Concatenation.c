#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head1=NULL;
struct node *head2=NULL;

struct node *create_ll(struct node *start){
    struct node *newnode,*ptr;
    int num;
    printf("\n Enter -1 to stop");
    printf("\n Enter the data:");
    scanf("%d",&num);
    while(num != -1){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=num;
        if(start==NULL){
            newnode->next=NULL;
            start=newnode;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("\n Enter the data");
        scanf("%d",&num);
    }
    return start;
}

struct node *concat(struct node *ls1,struct node *ls2){
    if(ls1 == NULL){
        return ls2;
    }
    if (ls2 == NULL){
        return ls1;
    }
    struct node *ptr;
    ptr=ls1;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=ls2;
    return ls1;
}
void display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        printf("\t%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\t%d",ptr->data);
    return;
}

int main()
{
    printf("\n Enter elements for the first list:");
    head1=create_ll(head1);
    printf("\n Enter elements for the second list:");
    head2=create_ll(head2);
    printf("\n Concatenated list is \n");
    head1=concat(head1,head2);
    display(head1);
}
