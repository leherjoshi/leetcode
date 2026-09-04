class Solution {
public:
     int cnt=0;
    void merge(vector<int>&nums,int left,int mid,int right){
        vector<int>temp;
        int i=left;
        int j=mid+1;
        
        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j<=right){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k=0;k<temp.size();k++){
            nums[left+k]=temp[k];
        }
    }
    void mergesort(vector<int>&nums,int i,int j){
        if(i>=j)return ;

        int mid=(i+j)/2;

        mergesort(nums,i,mid);
        mergesort(nums,mid+1,j);

        int right=mid+1;
        for(int k=i;k<=mid;k++){
            while(right<=j && (long long)nums[k]>2LL*nums[right]){
                right++;
            }
            cnt+=right-(mid+1);
        }
        merge(nums,i,mid,j);
    }
    int reversePairs(vector<int>& nums) {
        cnt=0;
        mergesort(nums,0,nums.size()-1);
        return cnt;
    }
};