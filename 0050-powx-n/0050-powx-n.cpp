class Solution {
public:
    double power(double x, long long n) {
        if (n == 0)
            return 1.0;
            double half=power(x,n/2);
            if(n%2==0)return half*half;
            return half*half*x;
        //return x * power(x, n - 1);
    }

    double myPow(double x, int n) {
        long long m = n;

        bool neg = false;
        if (m < 0) {
            neg = true;
            m = -m;
        }

        double ans = power(x, m);

        return neg ? 1.0 / ans : ans;
    }
};