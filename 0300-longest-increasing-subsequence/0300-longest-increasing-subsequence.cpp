class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> temp;

    for (int x : nums) {
        int low = 0;
        int high = temp.size();

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (temp[mid] < x)
                low = mid + 1;
            else
                high = mid;
        }

        if (low == temp.size())
            temp.push_back(x);
        else
            temp[low] = x;
    }

    return temp.size();
}
};