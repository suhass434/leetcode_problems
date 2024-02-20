/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    struct ListNode *odd,*even,*evenHead;
    odd=head;
    even=head->next;
    evenHead=even;

    while(even!=NULL && even->next!=NULL)
    {
        odd->next=odd->next->next;
        even->next=even->next->next;
        even=even->next;
        odd=odd->next;
    }
    odd->next=evenHead;
    return head;
}
