class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode();
        ListNode* second = new ListNode();

        ListNode* prev1 = first;
        ListNode* prev2 = second;
        ListNode* curr = head;

        while (curr) {
            if (curr->val < x) {
                prev1->next = curr;
                prev1 = curr;
            }
            else {
                prev2->next = curr;
                prev2 = curr;
            }

            curr = curr->next;
        }

        prev2->next = nullptr;
        prev1->next = second->next;

        return first->next;
    }
};