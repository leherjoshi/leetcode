class Solution {
public:
    struct Job{
        int s;
        int e;
        int profit;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profits) {
        int n=startTime.size();
        vector<Job>job;
        for(int i=0;i<n;i++){
            job.push_back({startTime[i],endTime[i],profits[i]});
        }

        sort(job.begin(),job.end(),[](auto &a,auto &b){
            return a.e<b.e;
        });

        vector<int>dp(n);
        dp[0]=job[0].profit;
        for(int i=1;i<n;i++){
            int take=job[i].profit;
                int l=0;
                int r=i-1;
                int idx=-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    if(job[mid].e<=job[i].s){
                        idx=mid;
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }

                }
                if(idx!=-1){
                    take+=dp[idx];
                }
                 dp[i] = max(dp[i-1], take);
        }

        return dp[n-1];
    }
};