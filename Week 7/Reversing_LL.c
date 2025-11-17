#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create_ll(struct node *start) {
    struct node *newnode, *ptr;
    int num;
    printf("\n Enter -1 to stop");
    printf("\n Enter the data: ");
    scanf("%d", &num);
    while (num != -1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;
        if (start == NULL) {
            newnode->next = NULL;
            start = newnode;
        } else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf(" Enter the data: ");
        scanf("%d", &num);
    }
    return start;
}

void display(struct node *start) {
    struct node *ptr;
    ptr = start;
    while (ptr != NULL) {
        printf("\t%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n"); 
    return;
}

struct node *reverse(struct node *start){
    struct node *prev=NULL,*next=NULL;
    struct node *current=start;
    while(current != NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    start=prev;
    return start;
}

int main() {
    printf("\n Enter elements of the list:");
    head = create_ll(head);

    printf("\n Before reversing the list : \n");
    display(head);

    printf("\n After reversing the list : \n");
    head=reverse(head);
    display(head);

    return 0;
}
