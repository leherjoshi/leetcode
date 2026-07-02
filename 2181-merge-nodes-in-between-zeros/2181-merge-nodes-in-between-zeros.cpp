class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        head = head->next;      // Skip the first zero
        int sum = 0;

        while (head) {

            if (head->val == 0) {
                tail->next = new ListNode(sum);
                tail = tail->next;
                sum = 0;
            } else {
                sum += head->val;
            }

            head = head->next;
        }

        return dummy->next;
    }
};