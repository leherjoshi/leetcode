class Solution {
public:
    string countAndSay(int n) {
       
        int num=1;
        string res =string(1,'1');
        for(int i=1;i<n;i++){
             int cnt=1;
            string temp="";
            for(int j=1;j<res.size();j++){
                if(res[j]==res[j-1]){
                    cnt++;
                }else{
                    temp+=to_string(cnt)+res[j-1];
                    cnt=1;
                }
            }
            temp+=to_string(cnt)+res.back();
            res=temp;
        }
        return res;
    }
};