class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        vector<pair<int,int>> arr;

        // value, list number
        for(int i = 0; i < nums.size(); i++) {
            for(int x : nums[i]) {
                arr.push_back({x, i});
            }
        }

        sort(arr.begin(), arr.end());

        int k = nums.size();

        vector<int> freq(k, 0);

        int count = 0;
        int left = 0;

        int ansL = 0;
        int ansR = INT_MAX;

        for(int right = 0; right < arr.size(); right++) {

            int list = arr[right].second;

            if(freq[list] == 0)
                count++;

            freq[list]++;

            // We have all k lists
            while(count == k) {

                int l = arr[left].first;
                int r = arr[right].first;

                if(r - l < ansR - ansL) {
                    ansL = l;
                    ansR = r;
                }

                // Remove left
                int leftList = arr[left].second;

                freq[leftList]--;

                if(freq[leftList] == 0)
                    count--;

                left++;
            }
        }

        return {ansL, ansR};
    }
};