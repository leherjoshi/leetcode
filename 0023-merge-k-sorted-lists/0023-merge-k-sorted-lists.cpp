class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap by value
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // push all non-null heads
        for (ListNode* node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();
            curr->next = temp;
            curr = curr->next;
            if (temp->next) pq.push(temp->next);
        }

        return dummy->next;
    }
};