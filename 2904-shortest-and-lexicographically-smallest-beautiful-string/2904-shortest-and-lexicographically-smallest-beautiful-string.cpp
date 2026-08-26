class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left=0;
        string best="";
        int cnt=0;
        for(int right=0;right<s.size();right++){
                if(s[right]=='1')cnt++;
            while(cnt>=k){
                while(s[left]=='0')left++;
                string curr=s.substr(left,right-left+1);
                if(best.empty()||(best.size()>curr.size())||(best.size()==curr.size()&&best>curr)){
                    best=curr;
                }
                cnt--;
                left++;
            }
        }
    return best;
    }
};