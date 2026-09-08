class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = speed.size();
        int res = 0;

        int p1 = position[n - 1];
        int s1 = speed[n - 1];

        for (int i = n - 2; i >= 0; i--) {

            if (position[i] + distance < p1 && speed[i] <= s1) {
                res++;
                s1 = speed[i];
            }

            p1 = position[i];
        }

        return res + 1;
    }
};