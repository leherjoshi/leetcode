/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        
        unordered_map<Node*,Node*>mp;
        Node*temp= head;
        while(temp){
            Node*new_node=new Node(temp->val);
            mp[temp]=new_node;
            temp=temp->next;
        }

        temp=head;
        Node*dummy;
        while(temp){
           dummy= mp[temp];
           dummy->next=mp[temp->next];
           dummy->random=mp[temp->random];
            temp=temp->next;
        }


        return mp[head];
    }
};