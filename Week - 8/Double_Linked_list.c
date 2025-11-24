#include<stdio.h>
#include<stdlib.h>

//

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
struct node *creation(struct node *start)
{
    int num;
    struct node *ptr;

    printf("\nEnter -1 to stop");

    while(1)
    {
        printf("\nEnter Data: ");
        if(scanf("%d", &num) != 1) {
            printf("\nInvalid input. Exiting creation.");
            while(getchar() != '\n');
            break;
        }

        if (num == -1)
            break;

        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = num;
        newnode->next = NULL;
        newnode->prev = NULL;
        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = newnode;
            newnode->prev = ptr;
        }
    }
    return start;
}

struct node *InsertBefore(struct node *start)
{
    struct node *newnode, *ptr;
    int num1, num2;

    if (start == NULL) {
        printf("\nThe list is empty. Cannot insert.");
        return start;
    }

    printf("\nEnter the data before which to insert:");
    scanf("%d", &num1);

    ptr = start;
    while(ptr != NULL && ptr->data != num1) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("\nNode with data %d not found.", num1);
        return start;
    }

    printf("\nEnter data to be inserted:");
    scanf("%d", &num2);

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num2;
    if (ptr == start) {
        newnode->next = start;
        newnode->prev = NULL;
        start->prev = newnode;
        start = newnode;
    } else {
        newnode->next = ptr;
        newnode->prev = ptr->prev;
        ptr->prev->next = newnode;
        ptr->prev = newnode;
    }

    return start;
}
struct node *DeleteNode(struct node *start)
{
    struct node *ptr;
    int num;

    if (start == NULL) {
        printf("\nThe list is empty. Nothing to delete.");
        return start;
    }
    printf("\nEnter data to be deleted:");
    scanf("%d", &num);
    ptr = start;
    while(ptr != NULL && ptr->data != num) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("\nNode with data %d not found.", num);
        return start;
    }
    if (ptr->prev == NULL) {
        start = ptr->next;
        if (start != NULL) {
            start->prev = NULL;
        }
    } else {
        ptr->prev->next = ptr->next;
    }

    if (ptr->next != NULL) {
        ptr->next->prev = ptr->prev;
    }

    free(ptr);
    printf("\nNode with data %d deleted successfully.\n", num);
    return start;
}

void display(struct node *start)
{
    struct node *ptr;
    ptr = start;

    if (start == NULL) {
        printf("\nThe list is empty.");
        return;
    }

    while(ptr != NULL)
    {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    return;
}

int main()
{
    int ch;
    while(1)
    {
        printf("\nEnter Choice:\n ");
        printf("1. Creation\n");
        printf("2. Insert Before\n");
        printf("3. Delete Node\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        if (scanf("%d", &ch) != 1) {
            printf("\nInvalid input. Exiting program.");
            while(getchar() != '\n');
            break;
        }

        switch(ch) {
            case 1:
                head = creation(head);
                break;
            case 2:
                head = InsertBefore(head);
                break;
            case 3:
                head = DeleteNode(head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("\nProgram Ended");
                return 0;
            default:
                printf("\nInvalid Choice");
                break;
        }
    }
    return 0;
}
