class Solution {
public:
    int ans=INT_MAX;

    void can(int ind,vector<int>&cookies,vector<int>&v,int k){
        if(ind==cookies.size()){
            int maxi=INT_MIN;

            for(int i=0;i<k;i++){
                maxi=max(maxi,v[i]);
            }
            ans=min(ans,maxi);
            return ;
        }

        for(int i=0;i<k;i++){
            v[i]+=cookies[ind];
            can(ind+1,cookies,v,k);
            v[i]-=cookies[ind];
        }

    }
    int distributeCookies(vector<int>& cookies, int k) {
        
        int n=cookies.size();
        vector<int>v(k,0);
        can(0,cookies,v,k);
        return ans;

        
    }
};