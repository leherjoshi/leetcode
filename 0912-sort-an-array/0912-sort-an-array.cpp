class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        vector<int>num;
        while(!pq.empty()){
            int ans=pq.top();pq.pop();
            num.push_back(ans);
        }
        reverse(num.begin(),num.end());
        return num;
    }
};