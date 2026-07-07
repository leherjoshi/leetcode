class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Insert copied nodes after original nodes
        Node* temp = head;

        while (temp) {
            Node* copy = new Node(temp->val);

            copy->next = temp->next;
            temp->next = copy;

            temp = copy->next;
        }

        // Step 2: Set random pointers
        temp = head;

        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        // Step 3: Separate the two lists
        temp = head;
        Node* copyHead = head->next;

        while (temp) {
            Node* copy = temp->next;

            temp->next = copy->next;

            if (copy->next)
                copy->next = copy->next->next;

            temp = temp->next;
        }

        return copyHead;
    }
};