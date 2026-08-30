class Solution {
public:
    vector<int> grayCode(int n) {
        int t=1<<n;
        vector<int>ans(t);
        for(int i=0;i<t;i++){
            ans[i]=i^(i>>1);
        }
        return ans;
    }
};