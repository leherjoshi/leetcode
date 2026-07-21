class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq_map;
        for (char c : tasks) {
            freq_map[c]++;
        }
        int ans=0;
        priority_queue<pair<int, char>> max_heap;
        for (auto &[ch, freq] : freq_map) {
            max_heap.push({freq, ch});
        }

        string res;
        int mini=0;
        while (max_heap.size()) {
           vector<pair<int,char>> temp;
            for(int i=0;i<=n;i++)
            {
            if(!max_heap.empty()){
            auto [freq1, char1] = max_heap.top(); max_heap.pop();
            res += char1;
            if (--freq1 > 0) temp.push_back({freq1, char1});
            ans++;
            }
            else{
                if(!temp.empty())
                ans++;
            }
            }
            for(auto &x : temp)
            max_heap.push(x);
                }

        

        return ans;
    }
};