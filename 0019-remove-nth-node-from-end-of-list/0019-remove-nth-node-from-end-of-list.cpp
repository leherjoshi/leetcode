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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(!head)return NULL;

       ListNode*curr=head;
       int i=0;
      int cnt=0;
       while(curr){
        cnt++;
        curr=curr->next;
       }

       if(cnt==n){
        ListNode*temp=head;
        head=head->next;
        delete temp;
        return head;

       }


       curr=head;
       ListNode*pre=nullptr;

       for(int i=1;i<cnt-n;i++){
            curr=curr->next;
       }

       ListNode*temp=curr->next;       
       curr->next=temp->next;
       delete temp;


       return head;

    }
};