class Solution {
public:

    double r(double x, int n) {
        if(n==0)return 1;

        double half=r(x,n/2);
        if(n%2==0){
            return half*half;
        }
        else{
            return half*half*x;
        }

    }
      double myPow(double x, int n) {
        long long m = n;

        if (m < 0) {
            
            double ans=r(x, -1*m);
            return 1.0 / ans; 
        }

        double ans = r(x, m);

        return  ans;
    }
};