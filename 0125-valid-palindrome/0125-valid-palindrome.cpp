class Solution {
public:
    bool ispan(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-i-1])return false;
        }
        return true;
    }
    bool isPalindrome(string s) {
         string t;

        for (char c : s) {
            if (isalnum(c))
                t += tolower(c);
        }

       
        return ispan(t);
    }
};