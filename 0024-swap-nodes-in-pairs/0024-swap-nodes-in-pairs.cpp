class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) return head;

        ListNode* newHead = head->next;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr && curr->next) {

            ListNode* second = curr->next;

            curr->next = second->next;
            second->next = curr;

            if(prev)
                prev->next = second;

            prev = curr;
            curr = curr->next;
        }

        return newHead;
    }
};