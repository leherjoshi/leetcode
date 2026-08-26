class Solution {
public:
    int reverseBits(int n) {
       
        vector<int> store;
        
        for (int i = 0; i < 32; i++) {  // Use a loop instead of while
            int bit = (n >> i) & 1;  // Extract the i-th bit properly
            store.push_back(bit);    // Store 0 or 1
          
        }
        
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            res |= (store[i] << (31 - i));  // Place bit at correct position
        }
        return res;
    }
};