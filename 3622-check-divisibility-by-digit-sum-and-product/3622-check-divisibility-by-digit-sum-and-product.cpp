class Solution {
public:
    bool checkDivisibility(int n) {
        if(n<10)return false;
        int sum=0;
        int prd=1;
        int m=n;
        while(n){
            sum=sum+n%10;
            prd=prd*(n%10);
            n=n/10;
        }
        cout<<sum<<" ";
        cout<<prd<<" ";
       return m%(sum+prd)==0?true:false;
    
    }
};