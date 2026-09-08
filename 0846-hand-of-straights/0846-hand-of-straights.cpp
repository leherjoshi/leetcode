class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupsize) {
         if(hand.size() % groupsize != 0) return false;
        sort(hand.begin(),hand.end());
        int cnt=0;
        unordered_map<int,int>mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++;
        }

        for(int i=0;i<hand.size();i++){
            int x=hand[i];
            if(mp[x]==0)continue;
            mp[x]--;
            int cnt=1;
            while(cnt<groupsize){

                if(mp[x+1]==0)return false;
                mp[x+1]--;
                cnt++;
                x++;
            }
            
        }
        return true;
       
    }
};