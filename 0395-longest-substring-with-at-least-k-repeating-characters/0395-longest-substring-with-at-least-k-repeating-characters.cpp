class Solution {
public:

    int longestSubstring(string s, int k) {
       // unordered_map<char,int>mp;
        int mx=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            vector<int>mp(26,0);
            for(int j=i;j<n;j++)
            {
               mp[s[j]-'a']++;
               bool tr=true;

        for(int c=0;c<26;c++){
              if(mp[c]!=0 && mp[c]<k){
                 tr=false;
               break;
                  }
                }

            if(tr)
              mx=max(mx,j-i+1);
           
                  }
          }


        return mx;
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