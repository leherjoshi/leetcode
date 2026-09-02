class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>nums2(2*nums.size());
        int n=nums.size();
        for(int i=0;i<2*nums.size();i++){
            nums2[i]=nums[(n+i)%n];
        }
        return nums2;

    }
};