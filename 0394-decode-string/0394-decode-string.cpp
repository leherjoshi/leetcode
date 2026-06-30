class Solution {
public:
    string decodeString(string s) {
        stack<int>count;
        stack<string>ss;

        string curr="";
        int cur=0;

        for(char c:s){
            if(isdigit(c)){
                cur=cur*10+(c-'0');
            }
            else if(c=='['){
                count.push(cur);
                ss.push(curr);
                cur=0;
                curr="";
            }
            else if (c==']'){
                int repeat=count.top();
                count.pop();
                string prev=ss.top();
                ss.pop();
                string temp=prev;
                for(int i=0;i<repeat;i++){
                    temp+=curr;
                }
                curr=temp;
            }
            else{
                curr+=c;
            }
        }

return curr;
        
    }
};