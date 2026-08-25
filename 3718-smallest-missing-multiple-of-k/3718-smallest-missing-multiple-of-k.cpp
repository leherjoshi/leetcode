class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>seen(nums.begin(),nums.end());
        int i=1;
        while(true){
           int mul=k*i;
            if(!seen.count(mul)){
                return mul;
            }
            i++;
        }
        return 0;

    }
};