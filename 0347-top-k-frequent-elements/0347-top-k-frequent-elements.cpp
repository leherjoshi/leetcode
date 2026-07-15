class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<pair<int,int>>pq;
     
      sort(nums.begin(),nums.end());
      int cnt=0;
      int a=-99999999;
      nums.push_back(-99999999);
        // pq.push({cnt,a});
      for(int i=0;i<nums.size();i++){
        if(a==-99999999&&cnt==0){
            a=nums[0];
            cnt=1;
        }
        if(nums[i]!=a){
                pq.push({cnt,a});
                cnt=0;
                a=nums[i];

        }
        cnt++;
      }
      vector<int>ans;
      while(k--&&!pq.empty()){
        auto [cn,nu]=pq.top();pq.pop();
        ans.push_back(nu);
      }
      return ans;
    }
};