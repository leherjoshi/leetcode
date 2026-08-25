class Solution {
public:
    // int solve(int i,int last,int n,vector<vector<int>>&dp){
    //     if(i==n){
    //         return 1;
    //     }

    //     if(last==-1){
    //         for(int i=0;i<7;i++)
    //         ways+=solve(i+1,0,n,dp);
    //         for(int i=0;i<2;i++)
    //         ways+=solve(i+1,1,n,dp);
          
    //         ways+=solve(i+1,3,n,dp);

    //     }
    //     if(last==0){
           
    //         ways+=solve(i+1,0,n,dp)+solve(i+1,0,n,dp);
    //     }
    //     if(last==0){
           
    //         ways+=solve(i+1,0,n,dp)+solve(i+1,0,n,dp)+solve(i+1,0,n,dp)
    //     }


    // }
   int knightDialer(int n) {
    long long one = 1, two = 1, three = 1, four = 1, five = 1;
    long long six = 1, seven = 1, eight = 1, nine = 1, zero = 1;

    long long one2, two2, three2, four2, five2;
    long long six2, seven2, eight2, nine2, zero2;

    long long MOD = 1000000007;

    for (int i = 2; i <= n; i++) {
        one2 = (six + eight) % MOD;
        two2 = (seven + nine) % MOD;
        three2 = (four + eight) % MOD;
        four2 = (zero + three + nine) % MOD;
        
        six2 = (zero + one + seven) % MOD;
        seven2 = (two + six) % MOD;
        eight2 = (one + three) % MOD;
        nine2 = (two + four) % MOD;
        zero2 = (four + six) % MOD;

        one = one2;
        two = two2;
        three = three2;
        four = four2;
       
        six = six2;
        seven = seven2;
        eight = eight2;
        nine = nine2;
        zero = zero2;
    }
    if(n==1)return 10;
    return (one + two + three + four  +
            six + seven + eight + nine + zero) % MOD;
}
};