
    class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head)return NULL;
        if(!head->next)return head;

        ListNode*prev=head;
        ListNode*curr=head->next;

        prev->next=swapPairs(curr->next);
        curr->next=prev;

        return curr;
    }
};