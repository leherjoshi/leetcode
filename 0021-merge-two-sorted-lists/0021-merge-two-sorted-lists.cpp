class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head1 = list1;
        ListNode* head2 = list2;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while(head1 != NULL && head2 != NULL) {

            if(head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            }
            else {
                curr->next = head2;
                head2 = head2->next;
            }

            curr = curr->next;
        }

        if(head1 != NULL) {
            curr->next = head1;
        }

        if(head2 != NULL) {
            curr->next = head2;
        }

        return dummy->next;
    }
};