class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;

        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }

        vector<int> freq;

        for(auto it : mp) {
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end());

        int unique = freq.size();

        for(int i = 0; i < freq.size(); i++) {
            if(k >= freq[i]) {
                k -= freq[i];
                unique--;
            }
            else {
                break;
            }
        }

        return unique;
    }
};