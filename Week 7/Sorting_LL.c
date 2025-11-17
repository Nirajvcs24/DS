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

struct node *sort(struct node *start) {
    int temp;
    struct node *ptr1, *ptr2;
    ptr1 = start;
    while (ptr1 != NULL) {
        ptr2 = ptr1->next;
        while (ptr2 != NULL) {
            if (ptr1->data > ptr2->data) {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
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

int main() {
    printf("\n Enter elements for the first list:");
    head = create_ll(head);

    printf("\n Sorted list is: \n");
    head = sort(head);
    display(head);

    return 0;
}
