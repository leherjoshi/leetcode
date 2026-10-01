class Solution {
public:
    bool ispred(string p, string s) {
        int t = p.size();
        int m = s.size();

        if (m % t != 0)
            return false;

        int repeat = m / t;
        string st = "";

        for (int i = 0; i < repeat; i++) {
            st += p;
        }

        return st == s;
    }

    string gcdOfStrings(string str1, string str2) {
        string strs = str1.size() > str2.size() ? str2 : str1;

        for (int i = strs.size(); i >= 1; i--) {
            string pref = strs.substr(0, i);

            if (ispred(pref, str1) && ispred(pref, str2)) {
                return pref;
            }
        }

        return "";
    }
};