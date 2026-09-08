class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size();
        int ans=0;
        int s1=INT_MAX;
        int p1=INT_MAX;

        for(int i=n-1;i>=0;i--){
            
            if(p1-distance>position[i] && speed[i]<=s1){
                ans+=1;
                s1=speed[i];
            }
            p1=position[i];
        }
        return ans;

    }
};