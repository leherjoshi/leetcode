class Solution {
public:
    string decodeString(string s) {
        stack<int>count;
        stack<string>ss;

        int len=0;

        string curr="";

        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isdigit(c)){
                len=len*10+c-'0';
            }
            else if(c=='['){
                count.push(len);
                ss.push(curr);
                len=0;
                curr="";

            }else if(c==']'){
                    int cnt=count.top();
                    count.pop();
                    string prev=ss.top();
                    ss.pop();
                    string temp=prev;

                    for(int j=0;j<cnt;j++)temp+=curr;

                    curr=temp;
            }else{
                curr+=c;
            }
        }
        return curr;
    }
};