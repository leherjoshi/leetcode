class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()||s.empty()||t.size()>s.size()){
            return "";
        }

        unordered_map<char,int>dict;
        for(char c:t)dict[c]++;

        int required=dict.size();
        int formed=0;

        int left=0;
        int right=0;

        unordered_map<char,int>windowcounts;
        int ans=INT_MAX;
        int ansleft=0;
        // int ansright=0;

    while(right<s.size()){
        char c=s[right];
        windowcounts[c]++;

        if(dict.find(c)!=dict.end()&&windowcounts[c]==dict[c]){
            formed++;
        }

        while(left<=right&&formed==required){
            c=s[left];

            if(right-left+1<ans){
                ans=right-left+1;
                ansleft=left;
                // ansright=right;
            }

            windowcounts[c]--;
            if(dict.find(c)!=dict.end()&&windowcounts[c]<dict[c]){
                formed--;
            }

            left++;

        }
        right++;
    }
    return (ans==INT_MAX)?"":s.substr(ansleft,ans);
    }
};