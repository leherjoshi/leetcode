class Solution {
public:
    int getSum(int a, int b) {
        if(b==0)return a;
        int sum =a^b;
         int cr=(a&b)<<1;
        return getSum(sum,cr);
    }
};