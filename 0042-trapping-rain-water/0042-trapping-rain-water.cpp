class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
       int i=0;
        int area=0;
        int j=n-1;
        int mxleft=0;
        int mxright=0;
        while(i<=j){
                mxleft=max(mxleft,height[i]);
                mxright=max(mxright,height[j]);

                
                if(mxleft<mxright){
                    area+=mxleft-height[i];
                     i++;

                }else{
                    area+=mxright-height[j];
                    j--;
                }
              
              
        }
        return area;
    }
};