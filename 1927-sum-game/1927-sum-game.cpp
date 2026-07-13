class Solution {
public:
    bool sumGame(string nums) {
        int lq=0;
        int rq=0;
        int lsum=0;
        int rsum=0;
        int n=nums.size()-1;
        int mid=n/2;
        for(int i=0;i<nums.size();i++){
            if(mid>=i){
                if(nums[i]=='?')lq++;
                else{
                    lsum+=nums[i]-'0';
                }
            }else{
                if(nums[i]=='?')rq++;
                else{
                    rsum+=nums[i]-'0';
                }
            }

        }
        if(lq==rq)return lsum!=rsum;
        if((lq+rq)%2!=0)return true;
        int difq=lq-rq;
        int dif=rsum-lsum;
        return 9*(difq/2)!=dif;
    }
};