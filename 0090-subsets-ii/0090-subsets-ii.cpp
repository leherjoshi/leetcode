class Solution {
public:

  void sums(vector<int>&arr,int i,vector<vector<int>>&res,vector<int>&sum){
      if(i==arr.size()){
          res.push_back(sum);
          return ; 
      }
      sum.push_back(arr[i]);
     sums(arr,i+1,res,sum);
     
      sum.pop_back();
      while(i+1<arr.size() && arr[i]==arr[i+1]) i++;
      sums(arr,i+1,res,sum);
  }
  
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>>res;
        vector<int>sum;
        sort(arr.begin(),arr.end());
        sums(arr,0,res,sum);
        return res;
    }
};