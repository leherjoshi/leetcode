class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,n));

        int top=0;
        int left=0;
        int down=n-1;
        int right=n-1;
        
        int curr=1;

        while(curr<=n*n){
            for(int c=left;c<=right;c++){
                ans[top][c]=curr++;
            }
            top++;
            for(int c=top;c<=down;c++){
                ans[c][right]=curr++;
            }
            right--;
            for(int c=right;c>=left&&curr<=n*n;c--){
                ans[down][c]=curr++;
            }
            down--;
            for(int c=down;c>=top&&curr<=n*n;c--){
                ans[c][left]=curr++;
            }
            left++;

        }
        return ans;
    }
};