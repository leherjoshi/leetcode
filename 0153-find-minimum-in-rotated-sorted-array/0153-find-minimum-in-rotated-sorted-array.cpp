class Solution {
public:
    int findMin(vector<int>& nums) {
        // int low=0;
        // int high=nums.size()-1;

        // while(low<=high){
        //     int mid=(low+high)/2;
        // //left part is sorted
        //     if(){
        //         if(){

        //         }
        //         else{

        //         }
        //     }
        //     //right part is sorted
        //     if(){
        //         if(){

        //         }else{

        //         }
        //     }
        // }
        return *min_element(nums.begin(),nums.end());
    }
};