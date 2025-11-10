#include <stdio.h>
#include<stdlib.h>
#include<process.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;

struct node *create_ll(struct node *start){
    struct node *newnode,*ptr;
    int num;
    printf("\n Enter -1 to stop");
    printf("\nEnter the data:");
    scanf("%d",&num);
    while(num != -1){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=num;
        if(num == -1)
        {
            return;
        }
        if(start==NULL){
            newnode->next=NULL;
            start=newnode;
        }
        else{
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=NULL;
        }
        printf("\n Enter the data:");
        scanf("%d",&num);
    }
    return start;
}

struct node *display(struct node *start){
    struct node *ptr;
    ptr=start;
    while(ptr->next!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\t",ptr->data);
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *newnode;
    int num;
    printf("\n Enter the data to be inserted:");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=start;
    start=newnode;
    return start;
}

struct node *insert_end(struct node *start){

    struct node *newnode,*ptr;
    ptr=start;
    int num;
    printf("\n Enter the data to be inserted:");
    scanf("%d",&num);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return start;
}

struct node *insert_after(struct node *start){
    struct node *newnode,*ptr,*preptr;
    int num,pos;
    printf("\n Enter the data to be inserted and after which the data should be inserted:");
    scanf("%d %d",&num,&pos);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=num;
    ptr=start;
    preptr=ptr;
    while(ptr->data!=pos){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->next=ptr;
    return start;
}

struct node *insert_before(struct node *start){
    struct node *newnode,*ptr,*preptr;
    int num,pos;
    printf("\n Enter the data to be inserted and before which the data should be inserted:");
    scanf("%d %d",&num,&pos);
    newnode->data=num;
    ptr=start;
    while(ptr->data!=pos){
        preptr=ptr;
        ptr=ptr->next;
    }
    ptr->next=newnode;
    return start;
}

struct node *delete_beg(struct node *start){
    struct node *ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
}

struct node *delete_end(struct node *start){
    struct node *ptr,*preptr;
    ptr=start;
    while(ptr->next!=NULL){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
}

struct node *delete_node(struct node *start){
    struct node *ptr,*preptr;
    int val;
    printf("\n Enter the value to be deleted in the list:");
    scanf("%d",&val);
    ptr=start;
    if(ptr->data == val){
        start=delete_beg(start);
        return start;
    }
    else{
        while(ptr->data!=val){
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        return start;
    }
}

struct node *delete_after(struct node *start){
    struct node *preptr,*ptr;
    int val;
    printf("\n Enter the value after which the node should be deleted:");
    scanf("%d",&val);
    ptr=start;
    while(ptr->data!=val){
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
}

struct node *delete_list(struct node *start){
    struct node *ptr;
    if(start!=NULL)
    {
        ptr=start;
        while(ptr!=NULL){
            printf("%d is deleted\n",ptr->data);
            start=delete_beg(ptr);
            ptr=start;
        }
    }
    return start;
}

int main()
{
    int choice;
    while(1){
    printf("\nEnter choice:\n1.Create list\n2.Insert at beg\n3.Insert at end\n4.Insert before\n5.Insert after\n6.Delete begining\n7.Delete end\n8.Delete node\n9.Delete After\n10.Delete list\n11.Display\n12.Exit");
    scanf("%d",&choice);
        switch(choice){
            case 1:start=create_ll(start);
                    printf("\n Linked list is created");
                    break;
            case 2:start=insert_beg(start); break;
            case 3:start=insert_end(start); break;
            case 4:start=insert_after(start); break;
            case 5:start=insert_before(start); break;
            case 6:start=delete_beg(start); break;
            case 7:start=delete_end(start); break;
            case 8:start=delete_node(start); break;
            case 9:start=delete_after(start); break;
            case 10:start=delete_list(start); break;
            case 11:start=display(start); break;
            case 12:printf("\n PROGRAM ENDED"); exit(0); break;
            default:printf("\n Invalid Choice");
        }
    }
    return 0;
}
