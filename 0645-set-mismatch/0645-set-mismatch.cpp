class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>ans;
        int sumall=0;
        int sum=0;
        set<int> s(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
                sum+=i+1;
                sumall+=nums[i];
                

        }
        int ssum=0;
        for(auto st:s){
            ssum+=st;
        }
        int ms=sum-ssum;
        int nu=sumall-ssum;
        ans.push_back(nu);
        ans.push_back(ms);
        return ans;
    }
};