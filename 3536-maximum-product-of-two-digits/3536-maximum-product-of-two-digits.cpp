class Solution {
public:
    int maxProduct(int n) {
        vector<int>a;
        while(n>0){
            int r=n%10;
            
            n/=10;
            a.push_back(r);
            
        }
        sort(a.begin(),a.end());
        int nu=a.size();
        return a[nu-1]*a[nu-2];
    }
};