class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n=hand.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        
        sort(hand.begin(),hand.end());
        //int si=0;
        for(int i=0;i<hand.size();i++){
            int x=hand[i];
             if(mp.find(x)!=mp.end()){
            for(int j=0;j<groupSize;j++){
                if(mp.find(x+j)!=mp.end()){
                    mp[x+j]--;
                    if(mp[x+j]==0)mp.erase(x+j);
                }else {
                    return false;
                }
            }
             }
        }
        

        return true;
    }
};