class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> vis(26, false);

        // Count frequency of each character
        for(char ch : s)
            freq[ch - 'a']++;

        stack<char> st;

        for(char ch : s) {

            // Current character is being processed
            freq[ch - 'a']--;

            // Already present in answer
            if(vis[ch - 'a'])
                continue;

            // Make answer lexicographically smaller
            while(!st.empty() &&
                  st.top() > ch &&
                  freq[st.top() - 'a'] > 0) {

                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            vis[ch - 'a'] = true;
        }

        // Convert stack to string
        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};