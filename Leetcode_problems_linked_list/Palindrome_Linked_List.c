/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    int count=0;
    int flag=1;
    struct ListNode *ptr;
    ptr=head;
    while(ptr != NULL){
        count++;
        ptr=ptr->next;
    }
    int arr[count];
    ptr=head;
    for(int i=0;i<count;i++){
        arr[i]=ptr->val;
        ptr=ptr->next;
    }
    for(int j=0;j<=(count)/2;j++){
        if(arr[j] == arr[count-j-1]){
            continue;
        }
        else{
            flag=0;
        }
    }
    return flag;
}
