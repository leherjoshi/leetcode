class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(st.empty()){
                        ans++;
                    }
                    else{
                        st.pop();
                    }
            }
        }
        while(!st.empty()){
            st.pop();
            ans++;
        }
        return ans;
    }
};