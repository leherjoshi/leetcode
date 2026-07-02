class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {

        ListNode* dummy = head;

        while (dummy->next != nullptr) {

            int one = dummy->val;
            int two = dummy->next->val;

            int gc = __gcd(one, two);

            ListNode* p = new ListNode(gc);

            p->next = dummy->next;
            dummy->next = p;

            dummy = p->next;   // Move to the next original node
        }

        return head;
    }
};