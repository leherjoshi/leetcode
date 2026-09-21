class Solution {
public:
    long long calculateScore(string s) {
        unordered_map<int, vector<int>> mp;

        long long sum = 0;

        for(int i = 0; i < s.size(); i++) {
            int mirror = 'z' - s[i] + 'a';

            if(mp.find(mirror - 'a') != mp.end() && !mp[mirror - 'a'].empty()) {
                int j = mp[mirror - 'a'].back();

                sum += i - j;

                mp[mirror - 'a'].pop_back();
            }
            else {
                mp[s[i] - 'a'].push_back(i);
            }
        }

        return sum;
    }
};