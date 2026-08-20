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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,
            vector<pair<int,ListNode*>>,
            greater<pair<int,ListNode*>>>mpp;

        for(auto list:lists){
            if(list){
                mpp.push({list->val,list});
            }
        }
        ListNode*dummy=new ListNode(0);
        ListNode*tail=dummy;

        while(!mpp.empty()){
            auto [val,node]=mpp.top();
            mpp.pop();

            tail->next=node;
            tail=tail->next;

            if(node->next){
                mpp.push({node->next->val,node->next});
            }
        }
        return dummy->next;


    }
};