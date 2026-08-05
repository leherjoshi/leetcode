class Solution {
public:
    int minSwaps(vector<int>& arr) {
   
        int n=arr.size();
        int zero=0;
        int swaps=0;
        int ones=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                ones++;
            }
        }
          if (ones <= 1)
            return 0;
             

        for(int i=0;i<ones;i++){
            if(arr[i]==0)zero++;
        }
        int ans = zero;

        for(int i=ones;i<arr.size()+ones-1;i++){
            if(arr[(i-ones)%n]==0)zero--;
             if(arr[i%n]==0)zero++;
             ans=min(ans,zero);
        }
        return ans;
        
    }
};