class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                int x = curr->val;

                curr = curr->next;

                while (curr && curr->val == x)
                    curr = curr->next;

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};