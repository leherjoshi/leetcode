class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        map<char, int> freq;
        for (char c : s) freq[c]++;

        string ans = "";

        for (int i = 0; i < n; i++) {
            map<char, int> avail = freq;
            string prefix;
            bool possible = true;

            // Try to match target's first i characters exactly
            for (int j = 0; j < i; j++) {
                char c = target[j];
                auto it = avail.find(c);
                if (it == avail.end()) {
                    possible = false;
                    break;
                }
                prefix += c;
                if (--(it->second) == 0) avail.erase(it);
            }
            if (!possible) continue;

            // At position i, pick the smallest available char strictly greater than target[i]
            char need = target[i];
            auto it = avail.upper_bound(need);
            if (it == avail.end()) continue; // no valid char here, try next i

            string candidate = prefix;
            candidate += it->first;
            if (--(it->second) == 0) avail.erase(it);

            // Fill the rest in ascending order (smallest possible tail)
            for (auto& [ch, cnt] : avail) {
                candidate.append(cnt, ch);
            }

            if (ans.empty() || candidate < ans) {
                ans = candidate;
            }
        }

        return ans;
    }
};