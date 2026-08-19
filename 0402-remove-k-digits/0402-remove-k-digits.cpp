class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        stack<char>st;

        for(int i=0;i<num.size();i++){
            while(k>0&&!st.empty()&&st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }
          while(!st.empty()){
            s+=st.top();
            st.pop();
        }

        reverse(s.begin(),s.end());
        int i;
        for(i=0;i<s.size();i++){
            if(s[i]!='0')break;
            
        }
        s=s.substr(i);
        if(s=="")return "0";
        return s;
    }
};