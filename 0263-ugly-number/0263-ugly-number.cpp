class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0) return false;

        while(num % 2 == 0)
            num /= 2;

        while(num % 3 == 0)
            num /= 3;

        while(num % 5 == 0)
            num /= 5;

        return num == 1;
    }

    bool nthUglyNumber(int n) {
        int cnt = 0;

        for(int i = 1; ; i++) {
            if(isUgly(i)) {
                cnt++;

                if(cnt == n)
                    return true;
            }
        }
        return false;
    }
};