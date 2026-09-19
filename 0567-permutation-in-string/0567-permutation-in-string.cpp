class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>target;

        for(char c:s1)target[c]++;

        int req=target.size();

        int formed=0;
        

        unordered_map<char,int>window;

        int left=0;

        for(int i=0;i<s2.size();i++){
            char c=s2[i];
            window[s2[i]]++;

            if(target.find(c)!=target.end() &&window[c]==target[c] ){
                formed++;
            }

            if(i-left+1>s1.size()){
                char c=s2[left];
                if(target.find(c)!=target.end() &&window[c]==target[c]){
                   formed--;
                }
                 window[c]--;
                 left++;

            }

            if(formed==req)return true;


            

        }

        if(formed==req)return true;
        return false;
    }
};