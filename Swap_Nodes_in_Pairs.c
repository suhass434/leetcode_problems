/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* cur;
struct ListNode* swap(struct ListNode* head)
{   struct ListNode* temp;
    if(head==NULL)
        return head;
    else{
        if(head->next!=NULL){
        temp=head->next;
        head->next=temp->next;
        temp->next=head;
        cur=swap(head->next);
        head->next=cur;
        }
        else
        return head;
    }
    return temp;
}
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    
    head=swap(head);
    return head;

}
