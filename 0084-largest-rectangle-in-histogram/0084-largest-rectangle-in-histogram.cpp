class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n=height.size();
      vector<int>left(n,0);
      vector<int>right(n,0); 
      stack<int>st;

      for(int i=0;i<n;i++){
        
            while(!st.empty()&&height[st.top()]>=height[i])st.pop();

        left[i]=!st.empty()?st.top():-1;
        st.push(i);

      } 
      while (!st.empty()) st.pop();

      for(int i=n-1;i>=0;i--){
        while(!st.empty()&&height[st.top()]>=height[i])st.pop();
        right[i]=!st.empty()?st.top():n;
        st.push(i);
      }
    int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, height[i] * width);
        }
        return maxArea;

    }
};