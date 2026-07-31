class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();

         vector<long long> L(n + 1, 0), T(n + 1, 0);
        for (int i = 0; i < n; i++) {
            L[i + 1] = L[i] + (s[i] == 'L');
        }

        
        for (int i = n - 1; i >= 0; i--) {
            T[i] = T[i + 1] + (s[i] == 'T');
        }

        long long cntL=0,cntLC=0,LC,CT=0,LCT=0;

        for (char c:s){
            if(c=='L'){
                cntL++;
            }else if(c=='C'){
                LC+=cntL;
                cntLC+=cntL;
            }else if(c=='T'){
                LCT+=cntLC;
            }
        }

        long long cntT=0;
        for(int i =n-1;i>=0;i--){
            if(s[i]=='T')cntT++;
            else if(s[i]=='C')
            CT+=cntT;
        }

        long long ans=max(LCT+LC,LCT+CT);

        for(int i=0;i<=n;i++){
            ans=max(ans,LCT+L[i]*T[i]);
        }
        return ans;

    }
};