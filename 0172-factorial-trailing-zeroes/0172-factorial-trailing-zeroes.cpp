class Solution {
public:
    int trailingZeroes(int n) {
        int res=0;
        for(int i=1;i<=n;i++){
            int p=pow(5,i);
            if(n/p==0)break;
            res+=n/p;
            
        }
        return res;
    }
};