class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
            int n=events.size();
            int ans=INT_MIN;
            vector<int>suff(n,-1);
            suff[n-1]=events[n-1][2];
            for(int i=n-2;i>=0;i--){
                suff[i]=max(suff[i+1],events[i][2]);
            }

            for(int i=0;i<n;i++){
                int s=events[i][0];
                int e=events[i][1];
                int v=events[i][2];
                 ans = max(ans, v);
                int idx=-1;
                int f=i+1;
                int l=n-1;
                while(f<=l){
                    int mid=(l+f)/2;
                    if(e<events[mid][0]){
                        idx=mid;
                        l=mid-1;
                    }else{
                        f=mid+1;
                    }
                }

                if(idx != -1){
                ans = max(ans, v + suff[idx]);
            }
            }
        return ans;
    }
};