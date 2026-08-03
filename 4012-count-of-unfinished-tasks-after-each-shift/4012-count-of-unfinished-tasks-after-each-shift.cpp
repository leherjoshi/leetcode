class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {

        int n = tasks.size();
        int m = shifts.size();

        vector<int> ans(m);

        // Build prefix sum array
        vector<long long> prefix(n);
        prefix[0] = tasks[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + tasks[i];
        }

        // Total time required to complete all tasks
        long long totalTime = prefix[n - 1];

        // Total work completed in the current cycle
        long long currentCompletedWork = 0;

        for (int i = 0; i < m; i++) {

            // Use the current shift time
            currentCompletedWork += shifts[i];

            // All tasks finished in this shift
            if (currentCompletedWork >= totalTime) {
                ans[i] = 0;

                // Restart from task 0 for the next shift
                currentCompletedWork = 0;
            } else {

                int low = 0;
                int high = n - 1;

                // Find the first prefix sum greater than
                // currentCompletedWork
                while (low <= high) {

                    int mid = low + (high - low) / 2;

                    if (prefix[mid] <= currentCompletedWork)
                        low = mid + 1;
                    else
                        high = mid - 1;
                }

                // 'low' is the index of the current task.
                // All tasks from 'low' to 'n-1' are unfinished.
                ans[i] = n - low;
            }
        }

        return ans;
    }
};