class Solution {
public:

    int divide(string s,int start,int end,int k){
        if(start>end)return 0;
         int countMap[26] = {0};
      
        for (int i = start; i < end; i++)
            countMap[s[i] - 'a']++;

        for(int i=start;i<end;i++){
            if(countMap[s[i]-'a']<k){
            int left=divide(s,start,i,k);

            int right=divide(s,i+1,end,k);
            return max(left,right);
            }
        }
        return end-start;
    }
    int longestSubstring(string s, int k) {
       // unordered_map<char,int>mp;
        int n=s.size();
        return divide(s,0,n,k);
    }
};















// int j=0;
        // int cnt=0;
        // for(int i=0;i<s.size();i++){
        //     mp[s[i]]++;
        //     bool t=true;
        //     for(auto m:mp){
        //         if(m<k){
        //             t=false;
        //             i++;

        //     }
        //     if(t)cnt++;
        //     j++;
        // }
        // return cnt;