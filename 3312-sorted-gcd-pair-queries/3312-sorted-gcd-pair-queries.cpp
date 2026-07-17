class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int>freq(maxi+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        
        vector<long long>divisivlby(maxi+1,0);

        for(int i=maxi;i>0;i--){

                long long cnt=0;
                for(int greater=i;greater<=maxi;greater+=i){
                    cnt+=freq[greater];
                }

                long long multiple=cnt*(cnt-1)/2;

                for(int j=2*i;j<=maxi;j+=i)
                    {
                        multiple-=divisivlby[j];
                    }
                    divisivlby[i]=multiple;
        }

        vector<long long>prefixSum(maxi+1,0);
         
        prefixSum[1] = divisivlby[1];
        for(int i = 2; i <= maxi; i++) {
            prefixSum[i] = prefixSum[i - 1] + divisivlby[i];
        }

        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int idx=lower_bound(prefixSum.begin(),prefixSum.end(),queries[i]+1)-prefixSum.begin();
            ans.push_back(idx);

        }
        return ans;

    }
};