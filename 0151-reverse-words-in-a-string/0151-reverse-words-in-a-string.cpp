class Solution {
public:
 
    string reverseWords(string s) {
        int n=s.size();

    int i=n-1;
    string ans = "";
        while(i>=0){
            int j=i;
            while(j>=0&&s[j]==' ')j--;
            i = j;
            int l=j;
            string words="";
            while(l>=0 && s[l]!=' '){
                words+=s[l];
                l--;
            }
            words=" "+words;
            reverse(words.begin(), words.end());
           ans += words;
            i=l;

        }
        int e = ans.size() - 1;
        while (e >= 0 && ans[e] == ' ')
            e--;

        return ans.substr(0, e + 1);
    }
};