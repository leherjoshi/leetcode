class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end());
        int start=interval[0][0];
        int end=interval[0][1];
        //unordered_set<pair<int,int>>st;
        vector<vector<int>>nw;
        for(int i=1;i<interval.size();i++){
            if(end>=interval[i][0]){
                end=max(end,interval[i][1]);
            }else{
                nw.push_back({start,end});
                start=interval[i][0];
                end=interval[i][1];

            }
        }
            nw.push_back({start,end});
        
        
        return nw;
    }
};