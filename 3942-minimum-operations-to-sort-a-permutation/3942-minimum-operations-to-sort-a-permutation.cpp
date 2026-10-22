class Solution {
public:
    int minOperations(vector<int>& nums) {
              int n =nums.size();
              if(n<=1)return 0;

              bool inc=true,dec=true;

              for(int i =0;i<n;i++)
            {
                int a = nums[i];
                int b = nums[(i+1)%n];

                if(b!=(a+1)%n)inc =false;
                if(b!=(a-1+n)%n)dec=false;


            }

            int first = nums[0];

            if(inc){
                return min((n-first)%n,first+2);
            }

            if(dec){
                return min(first+2,n-first);
            }
            return -1;
    }
};