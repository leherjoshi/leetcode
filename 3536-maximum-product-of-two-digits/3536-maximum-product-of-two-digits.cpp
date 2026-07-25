class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        int nu=s.size();
        return (s[nu-1]-'0')*(s[nu-2]-'0');
    }
};