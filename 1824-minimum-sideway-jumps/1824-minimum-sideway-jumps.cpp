class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int lane = 2;
        int jumps = 0;
        int n = obstacles.size();

        for (int i = 0; i < n - 1; i++) {

            // Can move straight
            if (obstacles[i + 1] != lane) {
                continue;
            }

            // Need side jump
            int bestLane = -1;
            int farthest = -1;

            for (int newLane = 1; newLane <= 3; newLane++) {
                if (newLane == lane || obstacles[i] == newLane)
                    continue;

                // Find how far this lane stays free
                int j = i + 1;

                while (j < n && obstacles[j] != newLane) {
                    j++;
                }

                if (j > farthest) {
                    farthest = j;
                    bestLane = newLane;
                }
            }

            lane = bestLane;
            jumps++;
        }

        return jumps;
    }
};