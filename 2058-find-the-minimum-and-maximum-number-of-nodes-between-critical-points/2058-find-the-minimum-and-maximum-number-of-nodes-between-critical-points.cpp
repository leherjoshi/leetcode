class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nodes;

        while (head) {
            nodes.push_back(head->val);
            head = head->next;
        }

        int firstpeak = -1;
        int prevpeak = -1;

        int minDist = INT_MAX;
        int maxDist = -1;

        for (int i = 1; i < nodes.size() - 1; i++) {

            // Check critical point
            if ((nodes[i] > nodes[i-1] && nodes[i] > nodes[i+1]) ||
                (nodes[i] < nodes[i-1] && nodes[i] < nodes[i+1])) {

                // First critical point
                if (firstpeak == -1) {
                    firstpeak = i;
                    prevpeak = i;
                }
                else {
                    // Distance from previous critical point
                    minDist = min(minDist, i - prevpeak);

                    // Distance from first critical point
                    maxDist = i - firstpeak;

                    prevpeak = i;
                }
            }
        }

        if (maxDist == -1)
            return {-1, -1};

        return {minDist, maxDist};
    }
};