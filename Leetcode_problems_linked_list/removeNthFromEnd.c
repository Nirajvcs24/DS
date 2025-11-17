/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *preptr,*ptr,*temp;
    if(head->next == NULL)
        return NULL;
    int len=0;
    ptr=head;
    while(ptr != NULL){
        len++;
        ptr=ptr->next;
    }
    int i=0;
    ptr=head;
    while(i<(len-n-1)){
        ptr=ptr->next;
        i++;
    }
    if(len == n){
        head=head->next;
        free(ptr);
        return head;
    }
    preptr=ptr;
    temp=ptr->next;
    ptr=ptr->next->next;
    free(temp);
    preptr->next=ptr;
    return head;
}
