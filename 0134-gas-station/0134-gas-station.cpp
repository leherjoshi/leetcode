class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    
        int diff=0;
        int mxdiff=0;
        int idx=0;
        for(int i=0;i<gas.size();i++){
                diff+=gas[i]-cost[i];
                mxdiff+=gas[i]-cost[i];
                if(mxdiff<0){
                    mxdiff=0;
                    idx=i+1;
                }
               
        }
        if(diff<0)return -1;
        return idx;

    }
};