class Solution {
public:
    void solve(int i, string mid, vector<string>& ans, string s, int parts) {

        if(parts == 4) {
            if(i == s.size()) {
                mid.pop_back();
                ans.push_back(mid);
            }
            return;
        }

        if(i >= s.size())
            return;

        // send 1 digit
        solve(i + 1, mid + s[i] + '.', ans, s, parts + 1);

        // send 2 digits
        if(s[i] != '0' && i + 1 < s.size()) {
            string st = "";

            for(int j = i; j < i + 2; j++) {
                st += s[j];
            }

            if(stoi(st) <= 255) {
                solve(i + 2, mid + st + '.', ans, s, parts + 1);
            }
        }

        // send 3 digits
        if(s[i] != '0' && i + 2 < s.size()) {
            string st = "";

            for(int j = i; j < i + 3; j++) {
                st += s[j];
            }

            if(stoi(st) <= 255) {
                solve(i + 3, mid + st + '.', ans, s, parts + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        solve(0, "", ans, s, 0);

        return ans;
    }
};