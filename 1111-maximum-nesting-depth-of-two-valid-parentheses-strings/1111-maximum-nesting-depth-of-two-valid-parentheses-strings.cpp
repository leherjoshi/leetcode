class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int cnt=0;
    vector<int>ans;
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                
                ans.push_back(cnt%2);
                cnt++;
            }else{
                cnt--;
                ans.push_back(cnt%2);
            }
        }
        return ans;
    }
};