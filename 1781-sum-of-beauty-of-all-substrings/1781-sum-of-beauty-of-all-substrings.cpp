class Solution {
public:
    int beautySum(string s) {

                int n = s.size();
        int totalBeauty = 0;

for(int j=0;j<n;j++){
        int freq[26]={0};
        for(int i=j;i<n;i++){
            freq[s[i]-'a']++;
        

        int maxi=0;
        int mini = INT_MAX;

        for(int f:freq){
            if(f>0){
                maxi = max(maxi,f);
                mini =min(mini,f);
            }
        }
        totalBeauty+=(maxi-mini);


    }
    }
    return totalBeauty;
}
};