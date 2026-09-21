/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
         if (!head || !head->next) return head;

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // Step 1: Push all values into the priority queue
    ListNode* temp = head;
    while (temp) {
        pq.push(temp->val);
        temp = temp->next;
    }

    // Step 2: Assign sorted values back to the list
    temp = head;
    while (!pq.empty()) {
        temp->val = pq.top();
        pq.pop();
        temp = temp->next;
    }

    return head;

    }
};